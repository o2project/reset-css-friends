= user agent stylesheetとreset.css

ブラウザがWeb上のページを読み込むときに使うCSSとして、@<kw>{user agent stylesheet}というのがあります。
このuser agent stylesheetは各ブラウザごとにどのように指定されているかブラウザ上で見ることができます。

  * Gecko: Firefoxで resource://gre-resources/html.css をアドレスバーに入力
  * WebKit: http://trac.webkit.org/browser/trunk/Source/WebCore/css/html.css
  * Blink: https://chromium.googlesource.com/chromium/blink/+/master/Source/core/css/html.css

全ての指定を見るのは紙面の都合上厳しいため、ここでは各reset.cssで指定されている要素のみ見ていきます。

== html要素

html要素はBlink・WebKitでは@<code>{display: block;}という指定だけがおこなわれています。
いっぽうGeckoでは@<code>{display: block;}以外にも、@<code>{unicode-bidi: isolate;}という複数の表記方向が混在する文章をどのように扱うか決める定義もされています。
@<code>{unicode-bidi}プロパティの値によって表示がどう変わるかは@<href>{http://www.osaka-kyoiku.ac.jp/~joho/html5_ref/css/unicode-bidi_css.php}を参照してください。

sanitize.cssとress.cssでは、html要素に対し@<code>{box-sizing: border-box;}を指定した上で、全称セレクタへ@<code>{box-sizing: inherit;}を指定しています。
このことでコンテンツ領域に@<code>{padding}や@<code>{border}の値が入るようになります。
これによりボックスサイズの計算をより簡単にし、サイズの計算をやりやすくすることを狙っていると思われます。

== body要素

body要素はBlink・Gecko・WebKitで同様のスタイル定義がおこなわれています（@<list>{body-element}）。

//list[body-element][body要素に対するスタイル定義]{
#@mapfile(../codes/body.css)
//}

一方Eric Mayer、Normalize.css、Sanitize.css、YUI 3では@<code>{body}要素へ対し@<code>{margin: 0;}を指定しています。
Webページを作るときにページの外周へmarginを設定することはほとんど無いため、このような指定がされていると予想しています。
