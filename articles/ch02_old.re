= Reset CSSは何をリセットしているのか

== html要素

sanitize.cssとress.cssでは、html要素に対し@<code>{box-sizing: border-box;}を指定した上で、全称セレクタへ@<code>{box-sizing: inherit;}を指定しています。
このことでコンテンツ領域に@<code>{padding}や@<code>{border}の値が入るようになります。
これによりボックスサイズの計算をより簡単にすることを狙っていると思われます。

== body要素

Reset CSSではEric Meyer、Normalize.css、Sanitize.css、YUI 3では@<code>{body}要素へ対し@<code>{margin: 0;}を指定しています。
Webページを作るときにページの外周へmarginを設定することはほとんど無いため、このような指定がされていると予想しています。

== p要素

Reset CSSではYUI 3やEric Meyerといった古めのReset CSSでは@<code>{margin}と@<code>{padding}が0と指定されています。
しかし、他のReset CSSでは特に指定がなくユーザーエージェントスタイルシートをそのまま使うようにしています。

#@# prh:disable
これは新しく縦書きという概念が出てきたのに従い、Reset CSSで文字の方向や向き、流れる方向を意識するようになったためです。
その結果ユーザーエージェントスタイルシートをそのまま使ったほうが良いという結論に至ったと思われます。

== h1要素

normalize.cssやsanitize.cssではこの入れ子具合によってスタイルが変わるのを無くし、@<list>{h1-normalize}で示すスタイルが適用されるようになっています。

//list[h1-normalize][h1要素に対するnormalize.cssなどのスタイル定義]{
#@mapfile(../codes/h1-normalize.css)
h1 {
  font-size: 2em;
  margin: 0.67em 0;
}
#@end
//}

また、YUI3やEric Meyerでは見出しらしいスタイル定義をすべて無かったことにしています（@<list>{h1-yui3}）。

//list[h1-yui3][h1要素に対するYUI3などのスタイル定義]{
#@mapfile(../codes/h1-yui3.css)
h1 {
  margin:0;
  padding:0;
  font-size:100%;
  font-weight:normal;
}
#@end
//}

== a要素

a要素は各ブラウザのユーザーエージェントスタイルシートでは特にスタイルが適用されていません。
ただ、normalize.cssやsanitize.css、ressでは@<list>{a-reset}のようなスタイル定義をしています。

//list[a-reset][a要素に対するReset CSSのスタイル定義]{
#@mapfile(../codes/a-reset.css)
a {
  background-color: transparent;
  -webkit-text-decoration-skip: objects;
}
#@end
//}

@<code>{background-color: transparent;}が指定されている理由としては、IE 10上でリンクをクリックしたときにグレーの背景がついてしまうのを無くすために定義されています。
また@<code>{-webkit-text-decoration-skip: objects;}という指定は、英語の@<kw>{p}や@<kw>{y}、一部のロシア語をリンクの文字にした場合、リンクの下線が途切れてしまうのを防ぐためです@<fn>{normalize-issue-573}。
//footnote[normalize-issue-573][https://github.com/necolas/normalize.css/pull/573]

== img要素

normalize.cssやsanitize.css、ressではIE10でリンク内に画像があるとborderが適用されてしまうのを防ぐために、@<code>{border-style: none;}が指定されています。
