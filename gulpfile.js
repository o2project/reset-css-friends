const exec = require('child_process').exec
const execSync = require('child_process').execSync
const gulp = require('gulp')
const del = require('del')

const repositoryName = 'kubosho/review-boilerplate'
const repository = process.env.GH_TOKEN
  ? `https://${process.env.GH_TOKEN}@github.com/${repositoryName}`
  : `git@github.com:${repositoryName}`
const publishBranch = 'gh-pages'

const targetDir = 'articles'
const tempDir = 'temp'
const webrootDir = 'book'

const redpenBin = 'redpen-distribution-*/bin/redpen'
const redpenTargetFile = '*.re'
const redpenConfigFile = 'redpen-config.xml'

const reviewConfig = 'config.yml'
const reviewPrefix = 'bundle exec'
const reviewCompile = `${reviewPrefix} review-compile`
const reviewWebMaker = `${reviewPrefix} review-webmaker`
const reviewPdfMaker = `${reviewPrefix} review-pdfmaker`
const reviewEpubMaker = `${reviewPrefix} review-epubmaker`

gulp.task('clean', done => {
  del([`${targetDir}/${webrootDir}`])
    .then(paths => {
      console.log('Deleted files and folders:\n', paths.join('\n'))
      done()
    })
})

gulp.task('web', done => {
  process.chdir(targetDir)
  exec(`${reviewWebMaker} ${reviewConfig}`, (error) => {
    if (error != null) {
      console.error(error)
    }
    done()
  })
})

gulp.task('pdf', done => {
  process.chdir(targetDir)
  exec(`${reviewPdfMaker} ${reviewConfig}`, (error) => {
    if (error != null) {
      console.error(error)
    }
    done()
  })
})

gulp.task('redpen', done => {
  exec(`${redpenBin} -c ${redpenConfigFile} ${targetDir}/${redpenTargetFile}`, (error, stdout, stderr) => {
    // RedPen outputs log in stderr
    const stdOutput = stdout.replace(/\r?\n/g, '')
    if (error == null && stderr == null && stdOutput === '') {
      done()
    }

    // RedPen outputs error message in stdout
    if (stderr != null && stdOutput !== '') {
      console.error(stdout)
      setImmediate(() => process.exit(1))
    }
  })
})

gulp.task('deploy', () => {
  execSync(`mkdir ${tempDir} || rm -rf ${tempDir}`)
  execSync(`git clone --quiet ${repository} ${tempDir} 2> /dev/null`)

  process.chdir(tempDir)

  execSync(`git checkout --orphan ${publishBranch}`)
  execSync(`git fetch origin`)
  execSync(`git reset --hard origin/${publishBranch}`)

  process.chdir('..')

  execSync(`npm run web`)
  execSync(`cp ${targetDir}/${webrootDir}/*.* ${tempDir}`)
  const sha = execSync('git rev-parse --verify HEAD').toString().substring(0, 7)

  process.chdir(tempDir)

  const remote = execSync('git remote').toString().replace(/\r?\n/g, '')
  execSync(`git add -A`)
  execSync(`git commit -m '[ci skip] Update with ${sha}'`)
  execSync(`git push -u --quiet ${remote} ${publishBranch}`)
})
