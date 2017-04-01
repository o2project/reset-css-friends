= Reset CSSの特色

Reset CSSの思想は2004年に生まれ、そこから数多くのReset CSSが生まれました。
Reset CSSは年代によって思想や定義されているスタイルが若干ゃ変わっています。
この章では特に有名だと思われるReset CSSの思想を7個見ていきます。

== Hard reset

Hard resetは@<list>{hard-reset}のように書くだけの簡単なReset CSSです。

//list[hard-reset][Hard reset]{
#@mapfile(../codes/reset-css/hard-reset.css)
* {
  margin: 0;
  padding: 0;
}
#@end
//}

Hard resetは2004年に発表されました、おそらく最初のReset CSSだと思われます@<fn>{fight-the-power-default}。
公式ではHard resetと名乗っていません。Hard resetという名称は「A Comprehensive Guide to CSS Resets@<fn>{a-comprehensive-guide-to-css-resets}」という記事で出てきました。
2004年当時、自分はWebサイトを作っていなかったため状況をよく知りません。そのため次の段落は憶測を含みます。
#@# prh:disable
//footnote[fight-the-power-default][https://web.archive.org/web/20150905184045/http://leftjustified.net/journal/2004/10/07/css-negotiation/]
//footnote[a-comprehensive-guide-to-css-resets][http://sixrevisions.com/css/a-comprehensive-guide-to-css-resets/]

このHard resetが発表された当時はブラウザ間で@<code>{margin}や@<code>{padding}の宣言に差があることに対し大きな関心を持っていたようです。
そのためユニバーサルセレクタで@<code>{margin}と@<code>{padding}を@<code>{0}にすることで、ブラウザによって@<code>{margin}や@<code>{padding}の宣言に差があるのを無かったことにしようと試みたようです。

== Eric Meyer's Reset CSS

Eric MeyerというCSSへ対しとても貢献している人がいます。彼の功績を挙げると次のとおりです@<fn>{eric-meyer-linkedin}。

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

最近ではその功績にコミュニティが敬意を払い、彼の6歳で夭折した娘の名前をCSSの色名@<code>{beccapurple}として追加しようと提議されました@<fn>{becca-purple}。
そして本人と夭折した娘の要望@<fn>{rebecca-purple}により@<code>{rebeccapurple}としてCSS Color Module Level 4@<fn>{css-color-module-level-4}に追加されました。
//footnote[becca-purple][https://discourse.wicg.io/t/name-663399-becca-purple-in-css4-color/225]
#@# prh:disable
//footnote[rebecca-purple][http://meyerweb.com/eric/thoughts/2014/06/19/rebeccapurple/]
//footnote[css-color-module-level-4][https://drafts.csswg.org/css-color/#named-colors]

そのEric MeyerがHard resetの問題点を指摘した上で作ったReset CSSがEric Meyer's Reset CSSです。
#@# prh:disable
Eric Meyer's Reset CSSのソースコードは@<href>{http://meyerweb.com/eric/tools/css/reset/}にあります。

Hard resetの問題点ですが、ユニバーサルセレクタを使って@<code>{margin}や@<code>{padding}を@<code>{0}にするやり方は、フォーム関連の要素に対してどういった影響があるか分からないと書いてあります。
そして@<code>{margin}や@<code>{padding}を@<code>{0}にするだけでなく、フォントに関わる一貫したスタイル宣言をしたかったとも書いてあります。
そのため明示的に要素を宣言して個別にリセットしていくようにしたのがEric Meyer's Reset CSSです。

== YUI 3 Reset CSS

Yahoo!が主に開発していたYUI library@<fn>{yui-deprecate}に含まれるReset CSSです。
//footnote[yui-deprecate][なおYUI 3はこれからメンテナンスをおこなわないというアナウンスをしています]

YUI 3 Reset CSSはhtml要素に対し@<code>{color}プロパティや@<code>{background}プロパティが宣言されています。
ただしYUI 2の時代からReset CSSがほぼ更新されていない@<fn>{yui2-2008-1}@<fn>{yui2-2008-2}ため、article要素やheader要素といったHTML5で追加された要素に対する宣言はありません@<fn>{yui2-reset}。
//footnote[yui2-2008-1][YUI 2のReset CSSを見てみると2008年から指定内容がほぼ変わっていません]
//footnote[yui2-2008-2][https://github.com/yui/yui2/blob/324b3755ea4f3ac643572eb839d85c09801aac5f/build/reset/reset.css]
//footnote[yui2-reset][https://github.com/yui/yui2/blob/master/src/reset/css/reset.css]

== HTML5 Docter Reset CSS

HTML5を使った開発について発信していた@<kw>{HTML5 Docter}で提唱されたReset CSSです。
HTML5 Docter Reset CSSのソースコードは@<href>{http://html5doctor.com/html-5-reset-stylesheet/}にあります。

HTML5 Docter Reset CSSはEric Meyer's Reset CSSのv1.0を元に作られたものです。
Eric Meyer's Reset CSSのv1.0は作られた時期が2008年2月12日のため、HTML5で追加された要素のスタイル宣言がありませんでした。
HTML5 Docter Reset CSSはそこにarticle要素やheader要素などHTML5で追加された要素のスタイル宣言を追加しています。
他にもins要素やmark要素、hr要素などに独自のスタイルが定義されています。

== normalize.css

normalize.cssはそれまでのReset CSSを代替するReset CSSとして出てきました。

それまでのReset CSSはブラウザが既定で宣言しているスタイルをほぼすべてリセットするものでした。
normalize.cssはブラウザが宣言しているスタイルで使えそうなものを残しているのが特徴です。
後述するsanitize.cssやressと違い、作者の意見が入っていない純粋にブラウザのスタイルを正規化するライブラリです@<fn>{normalize-v5}。
//footnote[normalize-v5][v5.0.0まではスタイル宣言に作者の意見が含まれていましたが、v6.0.0でそれらがすべて取り除かれました]

ソースコードにはなぜその宣言をしたのか書かれているため、ソースコードを読むだけでも勉強になります。

== sanitize.css

normalize.cssをNicolas Gallagherとともに作ったJonathan Nealが作ったReset CSSです。
Jonathan NealはEric Meyer's Reset CSSやnormalize.cssを使っていましたが、それらを元に大多数が書いたスタイル宣言を含んだのがsanitize.cssです。
一例を挙げるとhtml要素に@<code>{box-sizing: border-box;}を宣言してユニバーサルセレクタで@<code>{box-sizing: inherit;}を宣言しています（@<list>{sanitize-html}）。
これにより特定の要素に対してwidthやheightを宣言するときに、borderやpaddingの宣言を気にせずwidthやheightの値を宣言できます。

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

最後は@<kw>{A modern CSS reset}と称するressです。ressはnormalize.cssの宣言を受け継ぎつつ、Hard resetのようにユニバーサルセレクタを使ってすべての要素に対し@<code>{margin}や@<code>{padding}を@<code>{0}にしています。
またsanitize.cssと同じくすべての要素に対して@<code>{box-sizing: border-box;}を宣言しています。
フォームに関連する要素についても@<kw>{A modern CSS reset}と称しているとおり、大胆にユーザーエージェントスタイルシートの宣言をリセットしています。
