= Reset CSSでどのような宣言がされているか

われわれはかしこいのでReset CSSでどのような宣言があるか教えるです。その前に教えてほしければ料理をよこすのです。

…満腹、満足です。解説が終わったらおかわりをよこすのです。

ブラウザがWeb上のページを読み込むときに既定で適用されるスタイルとして、@<kw>{ユーザーエージェントスタイルシート}があるです。
ユーザーエージェントスタイルシートの内容はブラウザごとに次のURLで見られるのです。

#@# prh:disable
  * Chrome: @<href>{https://chromium.googlesource.com/chromium/blink/+/master/Source/core/css/html.css}
  * Firefox: @<href>{https://dxr.mozilla.org/mozilla-central/source/layout/style/res/html.css}
  * Safari: @<href>{http://trac.webkit.org/browser/trunk/Source/WebCore/css/html.css}

Reset CSSはユーザーエージェントスタイルシートの宣言をリセットするためにあるです。
これからReset CSSのスタイル宣言を一部ユーザーエージェントスタイルシートでの宣言も教えつつ見ていくのです。
ちなみに解説するHTMLの要素は（@<list>{explain-elements}）のみに絞るです。

//list[explain-elements][解説するHTML要素一覧]{
html, body, img,
ul, ol, li,
table, tr, td,
h1, p, a, blockquote, br,
section, article, nav, aside,
input, textarea, button, select
//}

== html要素

まずはhtml要素です。ChromeとSafariでは@<code>{display: block;}の宣言だけなのです。
Firefoxでは@<code>{display: block;}以外にも、@<code>{unicode-bidi: isolate;}という複数の表記方向が混ざる文章をどのように扱うか決める宣言もされているのです。
@<code>{unicode-bidi}プロパティの値が表示にどう影響をあたえるかは「CSS: unicode-bidi プロパティ - Unicode文字の表記方向@<fn>{unicode-bidi}」を見るです。
//footnote[unicode-bidi][http://www.osaka-kyoiku.ac.jp/~joho/html5_ref/css/unicode-bidi_css.php]

sanitize.cssとressは、html要素へ対し@<code>{box-sizing: border-box;}を宣言した上で、ユニバーサルセレクタへ@<code>{box-sizing: inherit;}を宣言しているです。
これでコンテンツ領域に@<code>{padding}や@<code>{border}の値が入るようになるのです。これでボックスサイズの計算がより簡単になるのです。

== body要素

body要素はChrome・Firefox・Safariで同じスタイル宣言なのです（@<list>{body-element}）。

//list[body-element][body要素に対するスタイル定義]{
#@mapfile(../codes/browser/body.css)
body {
  display: block;
  margin: 8px;
}
#@end
//}

@<code>{margin: 8px;}の宣言は多くのWebサイトでいらない宣言なので、Reset CSSで@<code>{margin: 0;}と宣言されることが多いのです。
@<code>{margin: 0;}と宣言しているReset CSSはEric Meyer's Reset CSS、sanitize.css、YUI 3 Reset CSSがあるです。
normalize.cssもv5.0.0まではbody要素に同じ宣言があったです。v6.0.0で削除されて何もなくなったのです。

== セクショニング・コンテンツとh1要素

h1要素は見出しを表す要素の中でもっともランクが高い要素です。
section要素やarticle要素といったセクショニング・コンテンツへh1要素を入れ子した場合は、深さに応じてスタイルが変わるのです（@<list>{h1-element}）。

//list[h1-element][h1要素に対するスタイル定義]{
#@mapfile(../codes/browser/h1.css)
/* Chrome, Safari */
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
:-webkit-any(article,aside,nav,section) :-webkit-any(article,aside,nav,section)
h1 {
  font-size: 1.17em;
  -webkit-margin-before: 1__qem;
  -webkit-margin-after: 1em;
}

/* Firefox */
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

normalize.cssやsanitize.cssでは入れ子の深さによってスタイルが変わるのを無くしているです（@<list>{h1-normalize}）。

//list[h1-normalize][h1要素に対するnormalize.cssやsanitize.cssのスタイル定義]{
#@mapfile(../codes/reset-css/normalize-css/h1.css)
/**
 * Correct the font size and margin on `h1` elements within `section` and
 * `article` contexts in Chrome, Firefox, and Safari.
 */

h1 {
  font-size: 2em;
  margin: 0.67em 0;
}
#@end
//}

YUI 3 Reset CSSやEric Meyer's Reset CSSでは見出しらしいスタイルをすべて無くしているのです（@<list>{h1-yui3}）。

//list[h1-yui3][h1要素に対するYUI 3 Reset CSSやEric Meyer's Reset CSSのスタイル定義]{
#@mapfile(../codes/reset-css/yui3/h1.css)
h1 {
  margin:0;
  padding:0;
  font-size:100%;
  font-weight:normal;
}
#@end
//}

== p要素

Firefoxでは文字のレイアウト方向や向き、文字が流れる方向を元にmarginを適用する@<code>{margin-block-start}や@<code>{margin-block-end}を宣言しているです。
CSSのプロパティはそれぞれ、文字のレイアウト方向は@<code>{writing-mode}、文字の向きは@<code>{text-orientation}、文字の流れる方向は@<code>{direction}に対応しているのです。
ChromeやSafariでは@<code>{margin-before}や@<code>{margin-after}といったプロパティが宣言されて、値に@<code>{1__qem}が指定されているのです。
互換性モードで表示するときに@<code>{margin}の相殺をおこなわないためなのです。

YUI 3 Reset CSSやEric Meyer's Reset CSSなど古めのReset CSSでは@<code>{margin}と@<code>{padding}が0になっているのです。
新しいReset CSSでは特に宣言がないのです。これは新しく縦書きという概念が出てきたので、Reset CSSで文字の方向や向き、流れる方向を意識しだしたからです。
結果としてユーザーエージェントスタイルシートをそのまま使ったほうがいいとなったのです。

== a要素

a要素は各ブラウザのユーザーエージェントスタイルシートではスタイル宣言がないのです。
normalize.cssやsanitize.css、ressではIEとSafari向けのスタイル宣言をしているです（@<list>{a-reset}）。

//list[a-reset][a要素に対するReset CSSのスタイル定義]{
#@mapfile(../codes/reset-css/a-reset.css)
/**
 * 1. Remove the gray background on active links in IE 10.
 * 2. Remove gaps in links underline in iOS 8+ and Safari 8+.
 */

a {
  background-color: transparent; /* 1 */
  -webkit-text-decoration-skip: objects; /* 2 */
}
#@end
//}

@<code>{background-color: transparent;}が宣言されているのは、IE 10でリンクをクリックしたときにグレーの背景がついてしまうのを防ぐためです。
@<code>{-webkit-text-decoration-skip: objects;}という宣言は、英語やロシア語という言葉の一部文字をリンクの文字に指定したとき、下線が途切れてしまうのを防ぐためなのです@<fn>{normalize-issue-573}。
//footnote[normalize-issue-573][https://github.com/necolas/normalize.css/pull/573]

== img要素

img要素はiOSのSafariでタップしたときにハイライトを適用しないようにしているのです（@<list>{img-safari}）。

//list[img-safari][img要素に対するSafariのスタイル定義]{
#@mapfile(../codes/browser/safari/img.css)
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

normalize.cssやsanitize.css、ressではIE 10でリンク内に画像があるとborderが適用されるのを防ぐため、@<code>{border-style: none;}が宣言されているです（@<list>{img-normalize}）。

//list[img-normalize][img要素に対する各種Reset CSSのスタイル定義]{
#@mapfile(../codes/reset-css/normalize-css/img.css)
/**
 * Remove the border on images inside links in IE 10-.
 */

img {
  border-style: none;
}
#@end
//}

== ul, ol要素

ulやol要素はFirefoxやChrome、Safariで@<code>{論理margin}と@<code>{論理padding}が宣言されているです（@<list>{ul-firefox}）。

//list[ul-firefox][ul要素に対するSafariのスタイル定義]{
#@mapfile(../codes/browser/firefox/ul.css)
ul {
  display: block;
  list-style-type: disc;
  margin-block-start: 1em;
  margin-block-end: 1em;
  padding-inline-start: 40px;
}
#@end
//}

ulやol要素が入れ子になったとき、FirefoxとChrome、Safariで宣言しているプロパティは同じなのですが、セレクタの宣言方法が違うのです。
Firefoxでは@<code>{:any()}という疑似クラスを使って、ulやol要素などが入れ子になったときのスタイル宣言をおこなっているです@<fn>{mdn-any-pseudo-class}（@<list>{ul-nested-firefox}）。
@<code>{:any()}擬似クラスは、@<kw>{CSS Selectors Level 4}では@<code>{:matches()}として仕様策定が進んでいるのです@<fn>{css-selectors-4-matches}。
//footnote[mdn-any-pseudo-class][https://developer.mozilla.org/ja/docs/Web/CSS/:any]
//footnote[css-selectors-4-matches][https://drafts.csswg.org/selectors-4/#matches]

//list[ul-nested-firefox][入れ子になったul要素に対するFirefoxのスタイル定義]{
#@mapfile(../codes/browser/firefox/ul-nested.css)
/* nested lists have no top/bottom margins */
:-moz-any(ul, ol, dir, menu, dl) ul,
:-moz-any(ul, ol, dir, menu, dl) ol {
  margin-block-start: 0;
  margin-block-end: 0;
}

/* 2 deep unordered lists use a circle */
:-moz-any(ol, ul, menu, dir) ul {
  list-style-type: circle;
}

/* 3 deep (or more) unordered lists use a square */
:-moz-any(ol, ul, menu, dir) :-moz-any(ol, ul, menu, dir) ul {
  list-style-type: square;
}
#@end
//}

ただ@<code>{:any()}や@<code>{:matches()}の仕様が固まっていないので、ChromeやSafariでは従来どおりの子孫セレクタを使った宣言になっているです（@<list>{ul-nested-chrome}）。

//list[ul-nested-chrome][入れ子になったul要素に対するChromeやSafariのスタイル定義]{
#@mapfile(../codes/browser/chrome/ul-nested.css)
ul ul,
ol ul {
    list-style-type: circle
}
ol ol ul,
ol ul ul,
ul ol ul,
ul ul ul {
    list-style-type: square
}
#@end
//}

sanitize.cssでは、nav要素が親要素のときにulとol要素に@<code>{list-style: none;}の宣言をしているです（@<list>{sanitize-ul-ol}）。
nav要素内にあるulとol要素に@<code>{list-style}の値はあまり宣言しないので、このような宣言になっているです。

//list[sanitize-ul-ol][sanitize.cssのulやol要素に対するスタイル宣言]{
#@mapfile(../codes/reset-css/sanitize-css/ul-ol.css)
/**
 * Remove the list style on navigation lists in all browsers (opinionated).
 */

nav ol,
nav ul {
  list-style: none;
}
#@end
//}

== table要素

Firefoxでtable要素の非推奨となった属性にスタイル宣言をしているのが面白いのです。
たとえば@<code>{align}や@<code>{frame}、@<code>{rules}が挙げられるです（@<list>{table-firefox-1}）。

//list[table-firefox-1][Firefoxで宣言されている非推奨の属性に対してのスタイル宣言（一部）]{
#@mapfile(../codes/browser/firefox/table-1.css)
table[align="left"] {
  float: left;
}

table[align="right"] {
  float: right;
  text-align: start;
}

table[rules] {
  border-width: thin;
  border-style: hidden;
}
#@end
//}

他にもFirefoxだけ@<code>{-moz-is-html}という擬似クラスのようなセレクタ宣言があるです（@<list>{table-firefox-2}）。
この宣言は何が起こるのか謎なのです。かしこいわれわれでも分からないことはあるのです@<fn>{form-firefox}。
//footnote[form-firefox][https://jsfiddle.net/f3rp4kmu/]

//list[table-firefox-2][-moz-is-htmlという謎の擬似クラスっぽいセレクタ]{
#@mapfile(../codes/browser/firefox/table-2.css)
tr > form:-moz-is-html, tbody > form:-moz-is-html,
thead > form:-moz-is-html, tfoot > form:-moz-is-html,
table > form:-moz-is-html {
  /* Important: don't show these forms in HTML */
  display: none !important;
}
#@end
//}

sanitize.cssでは@<code>{border-collapse: collapse;}の宣言があるです（@<list>{sanitize-table}）。
これによってtableの@<code>{border}がセル同士で共有されるです。セル同士をくっつけて表示したいときは便利なのです。

//list[sanitize-table][sanitize.cssのtable要素に対する宣言]{
#@mapfile(../codes/reset-css/sanitize-css/table.css)
/**
 * Collapse border spacing
 */

table {
  border-collapse: collapse;
}
#@end
//}

@<code>{border-collapse}の値が表示へどのように影響するのかは@<img>{table-border-collapse}で示すとおりなのです。

//image[table-border-collapse][border-collapseの宣言によって表示が変わる]{
//}

== blockquote要素

blockquote要素はFirefoxで@<code>{[type=cite]}という属性へスタイル宣言があるのです（@<list>{blockquote-firefox}）。
この属性はいまW3Cの仕様には無いですが、過去にはあってFirefoxではいい感じの見た目になるのです（@<img>{firefox-blockquote-type-cite}）。

//list[blockquote-firefox][blockquote要素に対してのスタイル宣言]{
#@mapfile(../codes/browser/firefox/blockquote.css)
blockquote {
  display: block;
  margin-block-start: 1em;
  margin-block-end: 1em;
  margin-inline-start: 40px;
  margin-inline-end: 40px;
}

blockquote[type=cite] {
  display: block;
  margin-block-start: 1em;
  margin-block-end: 1em;
  margin-inline-start: 0;
  margin-inline-end: 0;
  padding-inline-start: 1em;
  border-inline-start: solid;
  border-color: blue;
  border-width: thin;
}
#@end
//}

//image[firefox-blockquote-type-cite][Firefoxでblockquote[type="cite"\]をプレビューしてみた様子]{
//}

Eric Meyer's Reset CSSでは、blockquoteやq要素で引用符を消すスタイル宣言があるです（@<list>{eric-meyers-blockquote}）。

//list[eric-meyers-blockquote][Eric Meyer's Reset CSSのblockquote要素に対するスタイル宣言]{
#@mapfile(../codes/reset-css/eric-meyers-blockquote.css)
blockquote, q {
  quotes: none;
}
blockquote:before, blockquote:after,
q:before, q:after {
  content: '';
  content: none;
}
#@end
//}

== input要素

input要素はtype属性の値によって動きが大きく変わるのです（@<img>{input-types}）。まるでパンサーカメレオンのようなのです。
input要素関連のスタイル宣言はChromeのユーザーエージェントスタイルシートで1123行中295行、Safariは1221行中421行も充てられているのです@<fn>{safari-user-agent-stylesheet-line}。
Firefoxは895行中24行がinput要素関連のスタイル宣言に充てられているです。
//footnote[safari-user-agent-stylesheet-line][SafariはiOS向けのスタイル宣言もあるので行数が多いかもしれないです]

//image[input-types][input要素はtype属性の値によって挙動が大きく変わる]{
//}

Reset CSSのinput要素に対する宣言はnormalize.css、sanitize.css、ressそれぞれで似ていますが微妙に違うのです。
それぞれのライブラリでどのように宣言されているか解説していくです。

==={input-normalize} normalize.css

normalize.cssはブラウザ間の違いをなくす宣言だけなのです（@<list>{normalize-input}）。
これもv6.0.0から作者の意見を入れないようにしたnormalize.cssの特徴が示されているのです。

//list[normalize-input][あくまでブラウザ間の差異を埋める程度に留めるnormalize.css]{
#@mapfile(../codes/reset-css/normalize-css/input.css)
/**
 * Remove the margin in Firefox and Safari.
 */

button,
input,
optgroup,
select,
textarea {
  margin: 0;
}

/**
 * Show the overflow in IE.
 * 1. Show the overflow in Edge.
 */

button,
input { /* 1 */
  overflow: visible;
}
#@end
//}

==={input-sanitize} sanitize.css

normalize.cssの宣言を元に、@<code>{font-size}や@<code>{line-height}の値として@<code>{inherit}が宣言されているのです（@<list>{sanitize-input}）。
親要素の宣言を受け継ぐことによって、スタイル宣言することを極力減らすようにしているです。優しいのです。

//list[sanitize-input][normalize.cssより作者の主張が含まれているsanitize.css]{
#@mapfile(../codes/reset-css/sanitize-css/input.css)
/**
* Remove the margin in Firefox and Safari.
*/

button,
input,
optgroup,
select,
textarea {
  margin: 0;
}

/**
* Inherit styling in all browsers (opinionated).
*/

button,
input,
select,
textarea {
  background-color: transparent;
  color: inherit;
  font-size: inherit;
  line-height: inherit;
}

/**
* Show the overflow in IE.
* 1. Show the overflow in Edge.
*/

button,
input { /* 1 */
  overflow: visible;
}
#@end
//}

input要素への宣言として他にないものは@<code>{touch-action: manipulation;}なのです（@<list>{sanitize-fix-tap-delay}）。
ページのスクロールとズームのみを許可する宣言なのですが、IE 10だとタップ時の遅延もなくなるのです。

//list[sanitize-fix-tap-delay][IE 10でタップ時の遅延を無くすCSS]{
#@mapfile(../codes/reset-css/sanitize-css/fix-tap-delay.css)
/*
 * Remove the tapping delay on clickable elements (opinionated).
 * 1. Remove the tapping delay in IE 10.
 */

a,
area,
button,
input,
label,
select,
summary,
textarea,
[tabindex] {
  -ms-touch-action: manipulation; /* 1 */
  touch-action: manipulation;
}
#@end
//}

==={input-ress} ress

ressもsanitize.css、もしくはそれ以上に作者の意見が反映されているのです（@<list>{ress-input}）。
@<code>{[type="button"]}や@<code>{[type="submit"]}、@<code>{[type="search"]}はブラウザのユーザーエージェントスタイルシートで@<code>{border-radius}が適用されているですが、ressでは無かったことになっているです。
他にも@<code>{background-color}を透過させたり@<code>{border-style}を無くしたり大胆なのです。

//list[ress-input][normalize.cssと同じく主張が強いress]{
#@mapfile(../codes/reset-css/ress/input.css)
input {
  border-radius: 0;
}

button,
input,
optgroup,
select,
textarea {
  font: inherit; /* Specify font inheritance of form elements */
}

/* Remove the default button styling in all browsers */
button,
input,
select,
textarea {
  background-color: transparent;
  border-style: none;
  color: inherit;
}
#@end
//}

== select要素

select要素はChromeとSafariで@<code>{text-transform: none;}の宣言がされているのです。
しかしEdgeとFirefoxでは宣言がないので、normalize.cssとsanitize.cssには同じ宣言があるです（@<list>{normalize-select}）。

//list[normalize-select][normalize.cssとsanitize.cssではtext-transform: none;の宣言だけ]{
#@mapfile(../codes/reset-css/normalize-css/select.css)
/**
 * Remove the inheritance of text transform in Edge, Firefox, and IE.
 * 1. Remove the inheritance of text transform in Firefox.
 */

button,
select { /* 1 */
  text-transform: none;
}
#@end
//}

==={select-ress} ress

normalize.cssやsanitize.cssと違って自分の道を歩いているのがressなのです。
@<code>{text-transform: none;}も宣言していますが、他にもselect要素らしい見た目を無くす@<code>{appearance}やIE独自の疑似要素へスタイルを宣言しているのです（@<list>{ress-select}）。
@<code>{::-ms-expand}はドロップダウンの項目を見るためのボタンを表す疑似要素で、@<code>{::-ms-value}はselect要素内の文字を表す疑似要素なのです@<fn>{ie-pseudo-elements}。
//footnote[ie-pseudo-elements][http://subtech.g.hatena.ne.jp/mayuki/20110923/1316786871]

//list[ress-select][ressはselect要素でも独自路線]{
#@mapfile(../codes/reset-css/ress/select.css)
/* Style select like a standard input */
select {
  -moz-appearance: none; /* Firefox 36+ */
  -webkit-appearance: none; /* Chrome 41+ */
}

select::-ms-expand {
  display: none; /* Internet Explorer 11+ */
}

select::-ms-value {
  color: currentColor; /* Internet Explorer 11+ */
}
#@end
//}

== button要素

normalize.cssやsanitize.css、ressではWebKitのバグを修正するセレクタ宣言やプロパティと値の宣言をしているです（@<list>{normalize-button}）。
Firefoxでもbutton要素内に画像を置いたときに生まれる@<code>{border}と画像の間にある隙間が埋まるようにしてあるのです@<fn>{firefox-form-button}。
#@# prh:disable
//footnote[firefox-form-button][http://jeffreyfrancesco.org/weblog/2011062101/]

//list[normalize-button][normalize.cssとsanitize.css、ressの共通宣言]{
@mapfile(../codes/reset-css/normalize-css/button.css)
/**
 * 1. Prevent a WebKit bug where (2) destroys native `audio` and `video`
 *    controls in Android 4.
 * 2. Correct the inability to style clickable types in iOS and Safari.
 */

button,
html [type="button"], /* 1 */
[type="reset"],
[type="submit"] {
  -webkit-appearance: button; /* 2 */
}

/**
 * Remove the inner border and padding in Firefox.
 */

button::-moz-focus-inner,
[type="button"]::-moz-focus-inner,
[type="reset"]::-moz-focus-inner,
[type="submit"]::-moz-focus-inner {
  border-style: none;
  padding: 0;
}

/**
 * Restore the focus styles unset by the previous rule.
 */

button:-moz-focusring,
[type="button"]:-moz-focusring,
[type="reset"]:-moz-focusring,
[type="submit"]:-moz-focusring {
  outline: 1px dotted ButtonText;
}
#@#end
//}

==={button-ress} ress

ressはnormalize.cssやsanitize.cssと同じ宣言もあるですが、独自に@<code>{cursor: pointer;}や@<code>{overflow: visible;}が宣言されているです（@<list>{ress-button}）。
@<code>{cursor: pointer;}はユーザーエージェントスタイルシートでカーソルの宣言がないのでressで宣言しているのです。
@<code>{overflow: visible;}はコメントにもあるように、IE8〜11はbutton要素の値として@<code>{hidden}が宣言されているのです。その宣言を無くすために@<code>{overflow: visible;}が宣言されているです。

//list[ress-button][ressのbutton要素へ対する宣言]{
#@mapfile(../codes/reset-css/ress/button.css)
/* Apply cursor pointer to button elements */
button,
[type="button"],
[type="reset"],
[type="submit"],
[role="button"] {
  cursor: pointer;
}

button {
  overflow: visible; /* Address `overflow` set to `hidden` in IE 8/9/10/11 */
}
#@end
//}

== textarea要素

textarea要素はnormalize.cssやsanitize.css、ressで似た宣言がされているです。

==={textarea-normalize} normalize.css

normalize.cssの宣言は単純なのです。IE向けにtextarea要素内のスクロールバーを消すだけの宣言だけです（@<list>{normalize-textarea}）。

//list[normalize-textarea][normalize.cssのtextarea要素へ対する宣言]{
#@mapfile(../codes/reset-css/normalize-css/textarea.css)
/**
 * Remove the default vertical scrollbar in IE.
 */

textarea {
  overflow: auto;
}
#@end
//}

==={textarea-sanitize-and-ress} sanitize.cssとress

sanitize.cssとressは、normalize.cssの宣言に加えてtextarea要素がリサイズできる方向を縦だけにする宣言がされているのです（@<list>{sanitize-and-ress-textarea}）。

//list[sanitize-and-ress-textarea][sanitize.cssとressのtextarea要素へ対する宣言]{
#@mapfile(../codes/reset-css/sanitize-css/textarea.css)
/**
 * 1. Remove the default vertical scrollbar in IE.
 * 2. Change the resize direction on textareas in all browsers (opinionated).
 */

textarea {
  overflow: auto; /* 1 */
  resize: vertical; /* 2 */
}
#@end
//}

==={textarea-yui3} YUI 3 Reset CSS

#@# prh:disable
書かれた時期が古いので、IE 7以下で使えるCSSハックが書かれているです（@<list>{yui3-textarea}）。
@<code>{*font-size:100%}という書き方は@ITの「IE 6とIE 7のCSSハック16選」内にある@<kw>{アスタリスクハック}@<fn>{atmarkit-css}を見るのです。…見なくてもよいのです。
//footnote[atmarkit-css][http://www.atmarkit.co.jp/fwcr/design/benkyo/csshack02/03.html#13]

//list[yui3-textarea][YUI 3のtextarea要素へ対する宣言]{
#@mapfile(../codes/reset-css/yui3/textarea.css)
input,
textarea,
select {
  font-family:inherit;
  font-size:inherit;
  font-weight:inherit;
  *font-size:100%; /*to enable resizing for IE*/
}
#@end
//}

== まとめ

Reset CSSといってもライブラリによって思想や宣言内容が違うのです。フレンズによって得意なことは違うのです。
その中から自分が作ろうとしているものに適したReset CSSを選ぶのが重要なのです。カレーのスパイスが重要なのと一緒なのです。

われわれとしては、Eric Meyer's Reset CSSやnormalize.css、sanitize.cssはブラウザ既定の見た目を大幅に上書きしなければ使えるです。
たとえば会社のWebサイトやキャンペーンサイトが挙げられるのです。

ressは大幅にブラウザ既定の見た目を書き換えたいときに使えるです。たとえばWebアプリやElectronで作るデスクトップアプリなどです。
