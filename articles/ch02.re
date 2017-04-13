= Reset CSSの特色

Reset CSSは2004年に生まれて数多くのReset CSSが生まれてきたであります。
Reset CSSは年代によって思想や宣言されているスタイルが少しずつ変わっているでありますよ。
ここでは有名なReset CSSを7個見ていくでありますよー！うおー！

== Hard reset

Hard resetは2004年に発表された、おそらく最初のReset CSSであります@<fn>{fight-the-power-default}！最初のReset CSSだけあって単純であります（@<list>{hard-reset}）。

//list[hard-reset][Hard reset]{
#@mapfile(../codes/reset-css/hard-reset.css)
* {
  margin: 0;
  padding: 0;
}
#@end
//}

Hard resetという名は「A Comprehensive Guide to CSS Resets@<fn>{a-comprehensive-guide-to-css-resets}」という記事で出てきたであります。
当時の状況はよく分からないので、ここからはわたしの勘によって書くでありますよー！
#@# prh:disable
//footnote[fight-the-power-default][https://web.archive.org/web/20150905184045/http://leftjustified.net/journal/2004/10/07/css-negotiation/]
//footnote[a-comprehensive-guide-to-css-resets][http://sixrevisions.com/css/a-comprehensive-guide-to-css-resets/]

Hard resetが発表されたときは、ブラウザ間で@<code>{margin}や@<code>{padding}の値に差があることに関心があったようであります。
そのためユニバーサルセレクタで@<code>{margin}と@<code>{padding}を@<code>{0}にして、ブラウザ間の@<code>{margin}や@<code>{padding}の値に差があるのを無かったことにしたようでありますよ。

== Eric Meyer's Reset CSS

Eric MeyerというCSSへ対しとても貢献している人がいるであります。Eric Meyerの実績はすごいでありますよ！@<fn>{eric-meyer-linkedin}

  * オライリーから出版された@<kw>{CSS: The Definitive Guide}@<fn>{css-the-definitive-guide}（日本語版は@<kw>{CSS完全ガイド}@<fn>{css-complete-guide}）を執筆
  * 上記の本以外にも多数の本を執筆@<fn>{eric-meyer-biblio}
  * css-discuss.orgの立ち上げ@<fn>{css-discuss}
  * スライドショー用のファイルフォーマット@<kw>{S5}を考案@<fn>{s5}
  * Netscape DevEdgeやCase Western Reserve University、Encyclopedia of Cleveland Historyのプロジェクトリーダーとデザイナーだった

#@# prh:disable
//footnote[eric-meyer-linkedin][https://www.linkedin.com/in/meyerweb/]
//footnote[css-the-definitive-guide][http://shop.oreilly.com/product/9780596527334.do]
//footnote[css-complete-guide][https://www.oreilly.co.jp/books/487311232X/]
//footnote[eric-meyer-biblio][https://en.wikipedia.org/wiki/Eric_A._Meyer#Bibliography]
//footnote[css-discuss][http://www.css-discuss.org/]
#@# prh:disable
//footnote[s5][https://en.wikipedia.org/wiki/S5_(file_format)]

最近ではその功績にコミュニティが敬意を払って、6歳で亡くなってしまった娘の名前をCSSの色名@<code>{beccapurple}として追加しようと提案されたであります@<fn>{becca-purple}。
そして本人と亡くなってしまった娘の要望@<fn>{rebecca-purple}によって、@<code>{rebeccapurple}としてCSS Color Module Level 4@<fn>{css-color-module-level-4}に追加されたであります！すごいであります！
//footnote[becca-purple][https://discourse.wicg.io/t/name-663399-becca-purple-in-css4-color/225]
#@# prh:disable
//footnote[rebecca-purple][http://meyerweb.com/eric/thoughts/2014/06/19/rebeccapurple/]
//footnote[css-color-module-level-4][https://drafts.csswg.org/css-color/#named-colors]

そのEric MeyerがHard resetの問題点を踏まえた上で作ったReset CSSがEric Meyer's Reset CSSであります。
Hard resetの問題点は次の2点であります。これらの問題を解決するためにそれぞれの要素ごとにリセットしたのがEric Meyer's Reset CSSであります！

  * ユニバーサルセレクタを使って@<code>{margin}や@<code>{padding}を@<code>{0}にするやり方がフォーム関連の要素に対してどういった影響があるか分からない
  * @<code>{margin}や@<code>{padding}を@<code>{0}にするだけでなく、フォントに関わる一貫したスタイル宣言をしたい

#@# prh:disable
Eric Meyer's Reset CSSのソースコードは@<href>{http://meyerweb.com/eric/tools/css/reset/}であります！

== YUI 3 Reset CSS

Yahoo!が主に開発していたYUI libraryに含まれるReset CSSであります！
ちなみにYUI 3はこれからメンテナンスをおこなわないというアナウンスをしているのであります@<fn>{yui-deprecate}。
//footnote[yui-deprecate][https://yahooeng.tumblr.com/post/96098168666/important-announcement-regarding-yui]

他のReset CSSに無いものとして、html要素に対し@<code>{color}プロパティや@<code>{background}プロパティが宣言されているでありますよ。
ただYUI 2からReset CSSはほぼ更新されていない@<fn>{yui2-2008-1}@<fn>{yui2-2008-2}であります。なのでHTML5で追加された要素の宣言は無いであります@<fn>{yui2-reset}。
//footnote[yui2-2008-1][YUI 2のReset CSSを見てみると2008年から内容がほぼ変わっていないであります]
//footnote[yui2-2008-2][https://github.com/yui/yui2/blob/324b3755ea4f3ac643572eb839d85c09801aac5f/build/reset/reset.css]
//footnote[yui2-reset][https://github.com/yui/yui2/blob/master/src/reset/css/reset.css]

== HTML5 Doctor Reset CSS

HTML5を使った開発について発信していた@<kw>{HTML5 Doctor}で発表されたReset CSSであります！
HTML5 Doctor Reset CSSのソースコードは@<href>{http://html5doctor.com/html-5-reset-stylesheet/}であります！

HTML5 Doctor Reset CSSはEric Meyer's Reset CSSのv1.0を元に作られたものでありますよ。
Eric Meyer's Reset CSSのv1.0は作られた時期が2008年2月12日なので、HTML5で追加された要素のスタイル宣言がなかったであります。
HTML5 Doctor Reset CSSはそこにHTML5で追加された要素のスタイル宣言を追加しているであります。他にもいろんな要素に独自のスタイル宣言をしているであります！

ちょっと眠くなったので、ここからはビーバー殿にまかせてわたしは寝るであります。

== normalize.css

プレーリーさんが寝てしまったのでここからはおれっちが説明するっす。

normalize.cssはそれまでのReset CSSに代わるReset CSSとして出てきたっす。
それまでのReset CSSはブラウザが既定で適用するスタイルをほぼすべてリセットしていたっす。

normalize.cssは今までと違ってブラウザが適用するスタイルで使えそうなものは残しているっす。
あとで説明する@<kw>{sanitize.css}や@<kw>{ress}と違って、作者の意見が無くて純粋にブラウザのスタイルを正規化しているっす@<fn>{normalize-v5}。
//footnote[normalize-v5][v5.0.0まではスタイル宣言に作者の意見が含まれていたのですが、v6.0.0でそれらがすべて取り除かれたっす]

ソースコードにはなぜその宣言をしたか書かれているので読むだけでも勉強になるっす。

== sanitize.css

normalize.cssをNicolas Gallagherとともに作ったJonathan Nealが作ったReset CSSっす。
Eric Meyer's Reset CSSやnormalize.cssなどを元に多くの人が書いたスタイル宣言を含んだのがsanitize.cssっすね。
たとえばhtml要素に@<code>{box-sizing: border-box;}を宣言して、ユニバーサルセレクタで@<code>{box-sizing: inherit;}を宣言しているっす（@<list>{sanitize-html}）。
こうすることで特定の要素に対してwidthやheightを宣言するときに値の計算がしやすくなるっす。

//list[sanitize-html][sanitize.cssのhtml要素に対する宣言]{
#@mapfile(../codes/reset-css/sanitize-css/html.css)
/**
 * 1. Remove repeating backgrounds in all browsers (opinionated).
 * 2. Add box sizing inheritence in all browsers (opinionated).
 */

*,
::before,
::after {
  background-repeat: no-repeat; /* 1 */
  box-sizing: inherit; /* 2 */
}

/**
 * 1. Add border box sizing in all browsers (opinionated).
 * 2. Add the default cursor in all browsers (opinionated).
 * 3. Prevent font size adjustments after orientation changes in IE and iOS.
 */

html {
  box-sizing: border-box; /* 1 */
  cursor: default; /* 2 */
  -ms-text-size-adjust: 100%; /* 3 */
  -webkit-text-size-adjust: 100%; /* 3 */
}
#@end
//}

== ress

最後は@<kw>{A modern CSS reset}と名乗るressっすね。
ressはnormalize.cssの宣言を引き継ぎつつ、Hard resetのようにユニバーサルセレクタを使ってすべての要素に対し@<code>{margin}や@<code>{padding}を@<code>{0}にしているっす。
またsanitize.cssと同じくすべての要素に対して@<code>{box-sizing: border-box;}を宣言しているっす。こうする利点はsanitize.cssの説明を読んでほしいっす。
フォームに関連する要素も@<kw>{A modern CSS reset}と名乗るとおり、大胆にユーザーエージェントスタイルシートの宣言をリセットしているっす。
