= ユーザーエージェントスタイルシート

ブラウザがWeb上のページを読み込むときに既定で使うCSSとして、@<kw>{ユーザーエージェントスタイルシート}があります。
このユーザーエージェントスタイルシートはブラウザ上でどのように指定されているか見ることができます。

#@# prh:disable
  * Chrome: https://chromium.googlesource.com/chromium/blink/+/master/Source/core/css/html.css
  * Firefox: Firefoxで resource://gre-resources/html.css をアドレスバーに入力
  * Safari: http://trac.webkit.org/browser/trunk/Source/WebCore/css/html.css

この章では、各ブラウザがユーザーエージェントスタイルシート内へどういった指定をしているか、自分がよく使う要素に限定し見ていきます（@<list>{explain-elements}）。

//list[explain-elements][解説する要素一覧]{
html, body, img,
ul, ol, li,
table, tr, td,
h1, p, a, blockquote, br,
section, article, nav, aside,
header, footer, main,
form, input, textarea, button, select
//}

== html要素

まず目に入るのがhtml要素です。ChromeとSafariでは@<code>{display: block;}の指定だけがあります。
いっぽうFirefoxでは@<code>{display: block;}以外にも、@<code>{unicode-bidi: isolate;}という複数の表記方向が混在する文章をどのように扱うか決める定義もされています。
@<code>{unicode-bidi}プロパティの値によって表示がどう変わるかは@<href>{http://www.osaka-kyoiku.ac.jp/~joho/html5_ref/css/unicode-bidi_css.php}を参照してください。

== body要素

body要素はChrome・Firefox・Safariで同様のスタイル定義がおこなわれています（@<list>{body-element}）。
ただし@<code>{margin: 8px;}の指定は多くのWebサイトにおいて不要な指定となるため、reset.css側では@<code>{margin: 0;}と指定されていることが多いです。

//list[body-element][body要素に対するスタイル定義]{
#@mapfile(../codes/body.css)
body {
  display: block;
  margin: 8px;
}
#@end
//}

== p要素

Firefoxでは文字のレイアウト方向や向き、文字が流れる方向を元にマージンを設定する@<code>{margin-block-start}や@<code>{margin-block-end}が定義されています。
ちなみにCSSのプロパティでは、文字のレイアウト方向は@<code>{writing-mode}、文字の向きは@<code>{text-orientation}、文字の流れる方向は@<code>{direction}に対応しています。

ChromeやSafariでは、@<code>{margin-before}や@<code>{margin-after}といったプロパティが定義され、値として@<code>{1__qem}が定義されています。
これは、互換性モードで表示するときにmarginの相殺をおこなわないようにするものです。

== h1要素

h1要素は見出しを表す要素の中でもっともランクが高い要素です。
また@<code>{section}や@<code>{article}要素といったセクショニング・コンテンツへh1要素を入れた場合は、入れ子の深さに応じてスタイルが変わるようになっています。

//list[h1-element][h1要素に対するスタイル定義]{
#@mapfile(../codes/h1.css)
/* Blink, WebKit */
h1 {
  display: block;
  font-size: 2em;
  -webkit-margin-before: 0.67__qem;
  -webkit-margin-after: 0.67em;
  -webkit-margin-start: 0;
  -webkit-margin-end: 0;
  font-weight: bold
}
:-webkit-any(article,aside,nav,section) h1 {
  font-size: 1.5em;
  -webkit-margin-before: 0.83__qem;
  -webkit-margin-after: 0.83em;
}
:-webkit-any(article,aside,nav,section) :-webkit-any(article,aside,nav,section) h1 {
  font-size: 1.17em;
  -webkit-margin-before: 1__qem;
  -webkit-margin-after: 1em;
}

/* Gecko */
h1 {
  display: block;
  font-size: 2em;
  font-weight: bold;
  margin-block-start: .67em;
  margin-block-end: .67em;
}

h2,
:-moz-any(article, aside, nav, section)
h1 {
  display: block;
  font-size: 1.5em;
  font-weight: bold;
  margin-block-start: .83em;
  margin-block-end: .83em;
}

h3,
:-moz-any(article, aside, nav, section)
:-moz-any(article, aside, nav, section)
h1 {
  display: block;
  font-size: 1.17em;
  font-weight: bold;
  margin-block-start: 1em;
  margin-block-end: 1em;
}
#@end
//}

== img要素

img要素はiOSのWebKit上でタップしたときのハイライトが適用されないようになっています。

//list[img-webkit][img要素に対するWebKitのスタイル定義]{
#@mapfile(../codes/img-webkit.css)
#if defined(WTF_PLATFORM_IOS) && WTF_PLATFORM_IOS
img {
  -webkit-tap-highlight-color: rgba(0, 0, 0, 0);
}
:any-link img {
  -webkit-tap-highlight-color: inherit;
}
#endif
#@end
//}
