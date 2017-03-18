= Reset CSSは何をリセットしているのか

Reset CSSの思想は2004年に生まれ、そこから数多くのReset CSSがでました。
そんなReset CSSですが、年代によって思想や定義されているスタイルが変わってきました。
この章では特に有名だと思われる7個のReset CSSから思想や定義されているスタイルを見ていきます。

== Hard reset

Hard resetは@<list>{hard-reset}のように書くだけの簡単なReset CSSです。

//list[hard-reset][Hard reset]{
#@mapfile(../codes/hard-reset.css)
* {
  margin: 0;
  padding: 0;
}
#@end
//}

これが出てきたのは2004年で、おそらく最初のReset CSSだと思われます@<fn>{fight-the-power-default}。
なお公式ではHard resetと名乗っていません。Hard resetという名称は「A Comprehensive Guide to CSS Resets@<fn>{a-comprehensive-guide-to-css-resets}」という記事で出てきました。
自分は2004年当時Webサイトを作っていなかったため、当時の状況はよく分からないので次の段落は憶測を含みます。
#@# prh:disable
//footnote[fight-the-power-default][https://web.archive.org/web/20150905184045/http://leftjustified.net/journal/2004/10/07/css-negotiation/]
//footnote[a-comprehensive-guide-to-css-resets][http://sixrevisions.com/css/a-comprehensive-guide-to-css-resets/]

このHard resetが発表された当時、ブラウザ間でmarginやpaddingの指定に差があることに対し大きな関心を持っていたようです。
そのため、全称セレクタでmarginとpaddingを0にすることで、ブラウザによってmarginやpaddingの指定に差があることを無かったことにしようと試みたようです。

== Eric Meyer's Reset CSS

Eric MeyerというCSSへ対しとても貢献している人がいます。
最近だとその貢献が認められ、CSS Color Module Level 4に彼の亡くなってしまった娘の名前を元にした「rebeccapurple」という色の名前が入ったということでも有名です@<fn>{rebeccapurple}。
そのEric MeyerがHard resetの問題点を指摘した上で作ったReset CSSがEric Meyer's Reset CSSです。
//footnote[rebeccapurple][https://cpplover.blogspot.jp/2014/06/rebeccapurplecss-4-color.html]

Hard resetの問題点ですが、全称セレクタを使ってmarginやpaddingを0にするやり方は、フォーム関連の要素に対してどういった影響があるか分からないと書いてあります。
そしてmarginやpaddingを0にするだけでなく、一貫したフォントに関わるスタイル指定をしたかったとも書いてあります。
また全称セレクタは名前空間が指定されていない場合はすべての要素にマッチしてしまうため、とても処理コストが高いセレクタです。

そのため明示的に要素を指定して個別にリセットしていくことで、そういった問題を解決できると思って書かれたのがEric Meyer's Reset CSSです。
#@# prh:disable
なお、Eric Meyer's Reset CSSのソースコードは@<href>{http://meyerweb.com/eric/tools/css/reset/}にあるので見てください。

== YUI 3 Reset CSS

Yahoo!が主に開発していたYUI library@<fn>{yui-deprecate}の中に含まれるReset CSSです。
//footnote[yui-deprecate][なおYUI 3はこれからメンテナンスをおこなわないというアナウンスをしています]

YUI 3 Reset CSSはhtml要素に対しcolorプロパティやbackgroundプロパティが指定されています。
またarticle要素やheader要素といったHTML5で追加された要素に対する指定がありません。
これはYUI 2の時代からReset CSSがほぼ更新されていないためです@<fn>{yui2-reset}。
//footnote[yui2-reset][https://github.com/yui/yui2/blob/master/src/reset/css/reset.css]

== HTML5 Docter
== normalize.css
== sanitize.css
== ress
