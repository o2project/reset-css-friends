= Reset CSSでどのような宣言がされているか

ブラウザがWeb上のページを読み込むときに既定で適用されるスタイルとして、@<kw>{ユーザーエージェントスタイルシート}があります。
ユーザーエージェントスタイルシートがどのように宣言されているかはブラウザごとに次のURLで見られます。

#@# prh:disable
  * Chrome: @<href>{https://chromium.googlesource.com/chromium/blink/+/master/Source/core/css/html.css}
  * Firefox: @<href>{https://dxr.mozilla.org/mozilla-central/source/layout/style/res/html.css}
  * Safari: @<href>{http://trac.webkit.org/browser/trunk/Source/WebCore/css/html.css}

ユーザーエージェントスタイルシートはブラウザごとに定義されているスタイルが違うため、Reset CSSを使わなかった場合ブラウザによって適用されるスタイルが違います@<fn>{user-agent-stylesheet-diff}。

この章では各Reset CSSがどのような宣言をしているか、ユーザーエージェントスタイルシートでどのように宣言されているか一部解説しつつ見ていきます。
なお、解説するHTML要素は（@<list>{explain-elements}）のみに絞ります。
//footnote[user-agent-stylesheet-diff][https://developer.mozilla.org/ja/docs/Web/Compatibility_FAQ/Tips_Default_Style_Difference.html]

//list[explain-elements][解説するHTML要素一覧]{
html, body, img,
ul, ol, li,
table, tr, td,
h1, p, a, blockquote, br,
section, article, nav, aside,
input, textarea, button, select
//}

== html要素

まずはhtml要素です。ChromeとSafariでは@<code>{display: block;}の宣言だけがあります。
いっぽうFirefoxでは@<code>{display: block;}以外にも、@<code>{unicode-bidi: isolate;}という複数の表記方向が混在する文章をどのように扱うか決める定義もされています。
@<code>{unicode-bidi}プロパティの値によって表示がどう変わるかは「CSS: unicode-bidi プロパティ - Unicode文字の表記方向@<fn>{unicode-bidi}」を参照してください。
//footnote[unicode-bidi][http://www.osaka-kyoiku.ac.jp/~joho/html5_ref/css/unicode-bidi_css.php]

Reset CSSではsanitize.cssとressが、html要素へ対し@<code>{box-sizing: border-box;}を宣言した上で、ユニバーサルセレクタへ@<code>{box-sizing: inherit;}を宣言しています。
このことでコンテンツ領域に@<code>{padding}や@<code>{border}の値が入るようになります。
これによりボックスサイズの計算をより簡単にすることを狙っていると思われます。

== body要素

body要素はChrome・Firefox・Safariで同様のスタイル定義がおこなわれています（@<list>{body-element}）。
ただし@<code>{margin: 8px;}の宣言は多くのWebサイトにおいて不要な宣言となるため、Reset CSSでは@<code>{margin: 0;}と宣言されることが多いです。

//list[body-element][body要素に対するスタイル定義]{
#@mapfile(../codes/browser/body.css)
body {
  display: block;
  margin: 8px;
}
#@end
//}

Eric Meyer's Reset CSS、sanitize.css、YUI 3 Reset CSSではbody要素へ対し@<code>{margin: 0;}を宣言しています。
Webページを作るときにページの外周へ@<code>{margin}を設定することはほとんど無いため、このような宣言がされていると思われます。
normalize.cssでもv5.0.0まではbody要素に対し同様の宣言がされていましたが、v6.0.0で削除されて何も宣言されなくなりました。

== セクショニング・コンテンツとh1要素

h1要素は見出しを表す要素の中でもっともランクが高い要素です。またsection要素やarticle要素といったセクショニング・コンテンツへh1要素を入れた場合は、入れ子の深さに応じてスタイルが変わるようになっています（@<list>{h1-element}）。

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

normalize.cssやsanitize.cssでは入れ子具合によってスタイルが変わるのを無くしています（@<list>{h1-normalize}）。

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

また、YUI 3 Reset CSSやEric Meyer's Reset CSSでは見出しらしいスタイル定義をすべて無くしています（@<list>{h1-yui3}）。

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

Firefoxでは文字のレイアウト方向や向き、文字が流れる方向を元にmarginを設定する@<code>{margin-block-start}や@<code>{margin-block-end}が定義されています。
ちなみにCSSのプロパティでは、文字のレイアウト方向は@<code>{writing-mode}、文字の向きは@<code>{text-orientation}、文字の流れる方向は@<code>{direction}に対応しています。

ChromeやSafariでは、@<code>{margin-before}や@<code>{margin-after}といったプロパティが定義され、値として@<code>{1__qem}が定義されています。
これは、互換性モードで表示する際@<code>{margin}の相殺をおこなわないようにするものです。

YUI 3 Reset CSSやEric Meyer's Reset CSSといった古めのReset CSSでは@<code>{margin}と@<code>{padding}が0と宣言されています。
しかし新しめのReset CSSでは特に宣言がなく、ユーザーエージェントスタイルシートをそのまま使うようにしています。

#@# prh:disable
これは新しく縦書きという概念が出てきたため、Reset CSSで文字の方向や向き、流れる方向を意識するようになったからです。
その結果ユーザーエージェントスタイルシートをそのまま使ったほうが良いという結論に至ったと思われます。

== a要素

a要素は各ブラウザのユーザーエージェントスタイルシートでは特にスタイルが定義されていません。
normalize.cssやsanitize.css、ressではIEやSafariに向けたスタイル定義をしています（@<list>{a-reset}）。

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

@<code>{background-color: transparent;}が宣言されている理由としては、IE 10上でリンクをクリックしたときにグレーの背景がついてしまうのを無くすために定義されています。
また@<code>{-webkit-text-decoration-skip: objects;}という宣言は、英語の@<kw>{p}や@<kw>{y}、一部のロシア語をリンクの文字にした場合、リンクの下線が途切れてしまうのを防ぐためです@<fn>{normalize-issue-573}。
//footnote[normalize-issue-573][https://github.com/necolas/normalize.css/pull/573]

== img要素

img要素はiOSのSafari上でタップしたときにハイライトが適用されないようになっています（@<list>{img-safari}）。

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

normalize.cssやsanitize.css、ressではIE 10でリンク内に画像があるとborderが適用されてしまうのを防ぐために、@<code>{border-style: none;}が宣言されています（@<list>{img-normalize}）。

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

ulやol要素はFirefoxやChrome、Safariで@<code>{論理margin}と@<code>{padding}が宣言されています（@<list>{ul-firefox}）。

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

入れ子になったulやol要素はFirefoxとChrome、Safariで宣言しているプロパティは同じですが、セレクタの宣言方法が違います。
Firefoxでは@<code>{:any()}という疑似クラスを使って、ul要素やol要素などが入れ子になったときのスタイル宣言をおこなっています@<fn>{mdn-any-pseudo-class}（@<list>{ul-nested-firefox}）。
この@<code>{:any()}擬似クラスですが、CSS Selectors Level 4では@<code>{:matches()}として仕様策定が進んでいます@<fn>{css-selectors-4-matches}。
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

@<code>{:any()}や@<code>{:matches()}の仕様が固まっていないためか、ChromeやSafariでは従来どおりの子孫セレクタを使った宣言になっています（@<list>{ul-nested-chrome}）。

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

sanitize.cssではnav要素が親要素としてあるときにol要素とul要素に対して@<code>{list-style: none;}の宣言をしています（@<list>{sanitize-ul-ol}）。
nav要素内に宣言したol要素とul要素に対して@<code>{list-style}の値を宣言することは少ないので、自分で書くスタイル宣言を減らせます。

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

table要素のスタイル宣言ですが、Firefoxでは非推奨となった属性にもスタイル宣言をおこなっているのが特色です。
たとえば@<code>{align}や@<code>{frame}、@<code>{rules}といった属性が挙げられます（@<list>{table-firefox-1}）。

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

またFirefox特有の宣言として@<code>{-moz-is-html}という擬似クラスのようなセレクタ宣言があります（@<list>{table-firefox-2}）。
この宣言が何を示すのかJSFiddleで見てみようとしましたが、特に表示は変わりなく謎のままでした@<fn>{form-firefox}。
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

sanitize.cssでは@<code>{border-collapse: collapse;}の宣言がされています（@<list>{sanitize-table}）。
これはtableの@<code>{border}をセル同士で共有する宣言になります。
表を表示するときにセルを分けて表示することは少ないため、余計なスタイル宣言を減らせます。

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

@<code>{border-collapse}の値によって表示がどのように変わるかは@<img>{table-border-collapse}で示すとおりです。

//image[table-border-collapse][border-collapseの宣言によって表示が変わる]{
//}

== blockquote要素

blockquote要素はFirefoxで@<code>{[type=cite]}という属性に対するスタイル宣言があります（@<list>{blockquote-firefox}）。
この属性は現在W3Cの仕様には無い仕様ですが、過去にはあったらしくFirefoxではいい感じの見た目になります（@<img>{firefox-blockquote-type-cite}）。

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

Eric Meyer's Reset CSSではblockquoteやq要素に対し引用符を消すスタイルが宣言されています（@<list>{eric-meyers-blockquote}）。
なお、他のReset CSSには特徴的な宣言がありません。

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

input要素はtype属性の値によって挙動が大きく変わります（@<img>{input-types}）。
そのためChromeのユーザーエージェントスタイルシートでは1123行中295行がinput要素関連のスタイル宣言です。
Safariに至っては1221行中421行がinput要素関連のスタイル宣言です@<fn>{safari-user-agent-stylesheet-line}。
//footnote[safari-user-agent-stylesheet-line][Safariの場合iOS向けと思われるスタイル宣言もあるためChromeと比較して行数が多いのかもしれません]
なおFirefoxは895行中24行がinput要素関連のスタイル宣言です。

//image[input-types][input要素はtype属性の値によって挙動が大きく変わる]{
//}

Reset CSSのinput要素に対する宣言はnormalize.css、sanitize.css、ressそれぞれで似通っているのですが微妙に違います。
この項ではそれぞれのライブラリでどのように宣言されているかを解説します。

==={input-normalize} normalize.css

normalize.cssはinput要素に対してブラウザ間の差異を埋める程度に留めています（@<list>{normalize-input}）。
これもv6.0.0から作者の意見を入れないようにしたnormalize.cssの特徴を示しているといえます。

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

ちなみに、バージョン5.0.0まではフォントや行間に作者の意見が反映されていました（@<list>{normalize-input-old}）。
ほとんどの場合@<code>{font-family: sans-serif}はフォームを構成する要素へ対し宣言されることが多い値です。
そのためnormalize.cssで宣言することで、normalize.cssを使う側では宣言をしなくて済むことを目指していたと思われます。

//list[normalize-input-old][バージョン5.0.0までのnormalize.css]{
#@mapfile(../codes/reset-css/normalize-css/input-old.css)
/**
 * 1. Change the font styles in all browsers (opinionated).
 */

button,
input,
optgroup,
select,
textarea {
  font-family: sans-serif; /* 1 */
  font-size: 100%; /* 1 */
  line-height: 1.15; /* 1 */
}
#@end
//}

==={input-sanitize} sanitize.css

normalize.cssの宣言を受け継ぎつつ、@<code>{font-size}や@<code>{line-height}の値として@<code>{inherit}が宣言されています（@<list>{sanitize-input}）。
親要素の宣言を継承することにより、自分でスタイル宣言することを極力減らそうとしています。

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

またinput要素に対する宣言として他にないものとしては@<code>{touch-action: manipulation;}があります（@<list>{sanitize-fix-tap-delay}）。
ページのスクロールとズームのみを許可する宣言ですが、IE 10ではタップ時の遅延をなくす宣言になります。

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

ressもsanitize.css並かそれ以上に作者の意見が反映されています（@<list>{ress-input}）。
@<code>{[type="button"]}や@<code>{[type="submit"]}、@<code>{[type="search"]}はブラウザのユーザーエージェントスタイルシートで@<code>{border-radius}と宣言されていますが、ressでは無かったことにしています。

また@<code>{background-color}を透過したり、@<code>{border-style}を無くす宣言があったりと大胆な宣言をしています。

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

select要素はChromeとSafariで@<code>{text-transform: none;}という宣言がされています。
しかしEdgeとFirefoxでは宣言がないため、normalize.cssとsanitize.cssでは同様の宣言をしています（@<list>{normalize-select}）。

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

normalize.cssやsanitize.cssと違い独自路線なのがressです。
@<code>{text-transform: none;}も宣言されていますが、他にもselect要素らしい見た目を無くす@<code>{appearance}やIE独自の疑似要素に対してスタイルを宣言しています（@<list>{ress-select}）。
IE独自の疑似要素について書くと、@<code>{::-ms-expand}はドロップダウンを表示するためのボタンを表す疑似要素、@<code>{::-ms-value}はselect要素内の文字を表す疑似要素です@<fn>{ie-pseudo-elements}。
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

normalize.cssやsanitize.css、ressではWebKitのバグを修正するセレクタ宣言やプロパティと値の宣言がおこなわれています（@<list>{normalize-button}）。
またFirefoxに対してもbutton要素内に画像を配置したときにボタンの@<code>{border}と画像の間に隙間が空く問題などが修正されています@<fn>{firefox-form-button}。
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

ressはnormalize.cssやsanitize.cssと同じ宣言もしていますが、ress独自の宣言として@<code>{cursor: pointer;}や@<code>{overflow: visible;}があります（@<list>{ress-button}）。
@<code>{cursor: pointer;}はユーザーエージェントスタイルシートでカーソルへ対する宣言がないため、ress側で宣言しています。
@<code>{overflow: visible;}はコメントにもありますが、IE8〜11ではbutton要素へ対して@<code>{hidden}という値が宣言されているため、それでは不都合があると考えたのか@<code>{overflow: visible;}が宣言されています。

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

textarea要素はnormalize.cssやsanitize.css、ressで似通った宣言になっています。

==={textarea-normalize} normalize.css

normalize.cssの宣言は単純で、IE向けにtextarea要素内のスクロールバーを消すだけの宣言がされています（@<list>{normalize-textarea}）。

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

sanitize.cssとressでは、normalize.cssでされていた宣言に加え、textarea要素のリサイズできる方向を縦方向にのみ制限する宣言がされています（@<list>{sanitize-and-ress-textarea}）。

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
書かれた時期が古いため、IE 7以下に適用されるCSSハックが書かれています（@<list>{yui3-textarea}）。
この@<code>{*font-size:100%}という書き方については@ITの「IE 6とIE 7のCSSハック16選」内にあるアスタリスクハック@<fn>{atmarkit-css}を見てください。
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

Reset CSSといってもライブラリによって思想や宣言内容が違います。
その中から自分が作ろうとしているものに応じてReset CSSを選択するのが重要です。

個人的な意見としては、Eric Meyer's Reset CSSやnormalize.css、sanitize.cssはブラウザ既定の見た目を大幅に上書きしない場面で使えます。
たとえば、企業の公式Webサイトや1ページで収まるようなキャンペーンサイトが挙げられます。

ressはその逆で、大幅にブラウザ既定の見た目を書き換えたい場合に使えます。
たとえばWebアプリやElectronなどで作るデスクトップアプリなどが挙げられます。
