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

reset.css側ではEric Mayer、Normalize.css、Sanitize.css、YUI 3では@<code>{body}要素へ対し@<code>{margin: 0;}を指定しています。
Webページを作るときにページの外周へmarginを設定することはほとんど無いため、このような指定がされていると予想しています。

== p要素

p要素はGeckoでは文字レイアウトの方向（@<code>{writing-mode}）や文字の向き（@<code>{text-decoration}）、また文字が流れる方向（@<code>{direction}）を元にマージンを設定する@<code>{margin-block-start}や@<code>{margin-block-end}が定義されています。

またBlinkやWebKitでは、@<code>{margin-before}や@<code>{margin-after}といったプロパティが定義されています。また値として@<code>{1__qem}というのが定義されています。
これは、互換性モードで表示するときにmarginの相殺をおこなわないようにするものです。

reset.css側ではYUI 3やEric Mayerといった古めのreset.cssでは@<code>{margin}と@<code>{padding}が0と指定されています。
しかし、他のreset.cssでは特に指定がなくユーザーエージェントスタイルシートをそのまま使うようにしています。

これは縦書きという概念が出てきて、論理marginが適用されている中、文字レイアウトの方向や向き、文字が流れる方向を意識しない指定が避けられてきた結果です。

== h1要素

h1要素は見出しを表す要素の中でもっともランクが高い要素です。
また@<code>{section}や@<code>{article}要素といったセクショニング・コンテンツへh1要素を入れた場合は、入れ子具合に応じてスタイルが変わるようになっています。

//list[h1-element][h1要素に対するスタイル定義]{
#@mapfile(../codes/h1.css)
//}

normalize.cssやsanitize.cssではこの入れ子具合によってスタイルが変わるのを無くし、@<list>{h1-normalize}で示すスタイルが適用されるようになっています。

//list[h1-normalize][h1要素に対するnormalize.cssなどのスタイル定義]{
#@mapfile(../codes/h1-normalize.css)
//}

また、YUI3やEric Mayerでは見出しらしいスタイル定義を全て無かったことにしています（@<list>{h1-yui3}）。

//list[h1-yui3][h1要素に対するYUI3などのスタイル定義]{
#@mapfile(../codes/h1-yui3.css)
//}
