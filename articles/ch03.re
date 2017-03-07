= reset.cssは何をリセットしているのか

== html要素

sanitize.cssとress.cssでは、html要素に対し@<code>{box-sizing: border-box;}を指定した上で、全称セレクタへ@<code>{box-sizing: inherit;}を指定しています。
このことでコンテンツ領域に@<code>{padding}や@<code>{border}の値が入るようになります。
これによりボックスサイズの計算をより簡単にし、サイズの計算をやりやすくすることを狙っていると思われます。

== body要素

reset.css側ではEric Meyer、Normalize.css、Sanitize.css、YUI 3では@<code>{body}要素へ対し@<code>{margin: 0;}を指定しています。
Webページを作るときにページの外周へmarginを設定することはほとんど無いため、このような指定がされていると予想しています。

== p要素

reset.css側ではYUI 3やEric Meyerといった古めのreset.cssでは@<code>{margin}と@<code>{padding}が0と指定されています。
しかし、他のreset.cssでは特に指定がなくユーザーエージェントスタイルシートをそのまま使うようにしています。

これは縦書きという概念が出てきて、論理marginが適用されている中、文字レイアウトの方向や向き、文字が流れる方向を意識しない指定が避けられてきた結果です。

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

また、YUI3やEric Meyerでは見出しらしいスタイル定義を全て無かったことにしています（@<list>{h1-yui3}）。

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

a要素は各ブラウザのuser agent stylesheetでは特にスタイルが適用されていません。
ただ、normalize.cssやsanitize.css、ressでは@<list>{a-reset}のようなスタイル定義をしています。

//list[a-reset][a要素に対するreset.css側のスタイル定義]{
#@mapfile(../codes/a-reset.css)
a {
  background-color: transparent;
  -webkit-text-decoration-skip: objects;
}
#@end
//}

@<code>{background-color: transparent;}が指定されている理由としては、IE 10上でリンクをクリックしたときにグレーの背景がついてしまうため、それを無かったことにするために定義されています。
また@<code>{-webkit-text-decoration-skip: objects;}という指定は、英語の@<kw>{p}や@<kw>{y}、一部のロシア語をリンクの文字列にした場合、リンクの下線が途切れてしまうのを防ぐために指定されています@<fn>{normalize-issue-573}。
//footnote[normalize-issue-573][https://github.com/necolas/normalize.css/pull/573]

== img要素

normalize.cssやsanitize.css、ressではIE10でリンク内に画像があるとborderが適用されてしまうのを防ぐために、@<code>{border-style: none;}が指定されています。
