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

== Eric Meyer's reset.css



== YUI 3
== HTML5 Docter
== normalize.css
== sanitize.css
== ress
