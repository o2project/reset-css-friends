= reset.cssは何をリセットしているのか

=== 各ブラウザが既定で読み込むCSS

ブラウザがWeb上のページを読み込むときに使うCSSとして、@<kw>{user agent stylesheet}があります。
このuser agent stylesheetはブラウザ上でどのように指定されているか見ることができます。

  * Gecko: Firefoxで resource://gre-resources/html.css をアドレスバーに入力
  * WebKit: http://trac.webkit.org/browser/trunk/Source/WebCore/css/html.css
  * Blink: https://chromium.googlesource.com/chromium/blink/+/master/Source/core/css/html.css

== html要素

html要素はBlink・WebKitでは@<code>{display: block;}という指定だけがおこなわれています。
いっぽうGeckoでは@<code>{display: block;}以外にも、@<code>{unicode-bidi: isolate;}という複数の表記方向が混在する文章をどのように扱うか決める定義もされています。
@<code>{unicode-bidi}プロパティの値によって表示がどう変わるかは@<href>{http://www.osaka-kyoiku.ac.jp/~joho/html5_ref/css/unicode-bidi_css.php}を参照してください。

== body要素

body要素はBlink・Gecko・WebKitで同様のスタイル定義がおこなわれています（@<list>{body-element}）。

//list[body-element][body要素に対するスタイル定義]{
#@mapfile(../codes/body.css)
body {
  display: block;
  margin: 8px;
}
#@end
//}

== p要素

p要素はGeckoでは文字レイアウトの方向（@<code>{writing-mode}）や文字の向き（@<code>{text-decoration}）、また文字が流れる方向（@<code>{direction}）を元にマージンを設定する@<code>{margin-block-start}や@<code>{margin-block-end}が定義されています。

またBlinkやWebKitでは、@<code>{margin-before}や@<code>{margin-after}といったプロパティが定義されています。また値として@<code>{1__qem}というのが定義されています。
これは、互換性モードで表示するときにmarginの相殺をおこなわないようにするものです。

== h1要素

h1要素は見出しを表す要素の中でもっともランクが高い要素です。
また@<code>{section}や@<code>{article}要素といったセクショニング・コンテンツへh1要素を入れた場合は、入れ子具合に応じてスタイルが変わるようになっています。

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

normalize.cssやsanitize.css、ressではIE10でリンク内に画像があるとborderが適用されてしまうのを防ぐために、@<code>{border-style: none;}が指定されています。
