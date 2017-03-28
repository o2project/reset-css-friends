const exec = require('child_process').exec
const execSync = require('child_process').execSync
const gulp = require('gulp')
const sass = require('gulp-sass')
const del = require('del')

const repositoryName = 'o2project/reset-css-friends'
const repository = process.env.GH_TOKEN
  ? `https://${process.env.GH_TOKEN}@github.com/${repositoryName}`
  : `git@github.com:${repositoryName}`

const targetDir = 'articles'
const tempDir = 'temp'
const webrootDir = 'book'
const publishBranch = 'master'
const publishDir = 'docs'

const redpenBin = 'redpen-distribution-*/bin/redpen'
const redpenTargetFile = '*.re'
const redpenConfigFile = 'redpen-conf-ja.xml'

const reviewConfig = 'config.yml'
const reviewPrefix = 'bundle exec'
const reviewPreproc = `${reviewPrefix} review-preproc --replace`
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

gulp.task('preproc', done => {
  process.chdir(targetDir)

  exec(`${reviewPreproc} *.re`, (error) => {
    if (error != null) {
      console.error(error)
    }
    done()
  })
})

gulp.task('sass', () => {
  return gulp.src('./articles/css/*.scss')
    .pipe(sass().on('error', sass.logError))
    .pipe(gulp.dest('./articles/'));
})

gulp.task('web', ['sass', 'preproc'], done => {
  exec(`${reviewWebMaker} ${reviewConfig}`, (error) => {
    if (error != null) {
      console.error(error)
    }
    done()
  })
})

gulp.task('pdf', ['preproc'], done => {
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
  execSync(`npm run web`)
  execSync(`rm -rf ${tempDir}/${publishDir}/`)
  execSync(`mkdir ${tempDir}/${publishDir}/`)
  execSync(`echo friends.o2p.jp > ${tempDir}/${publishDir}/CNAME`)
  execSync(`cp ${targetDir}/${webrootDir}/*.* ${tempDir}/${publishDir}`)
  execSync(`cp -r ${targetDir}/${webrootDir}/images ${tempDir}/${publishDir}`)

  const sha = execSync('git rev-parse --verify HEAD').toString().substring(0, 7)

  process.chdir(tempDir)

  const remote = execSync('git remote').toString().replace(/\r?\n/g, '')

  execSync(`git add -A`)
  execSync(`git commit -m '[ci skip] update Web preview with ${sha}'`)
  execSync(`git push -u --quiet ${remote} ${publishBranch}`)
})
