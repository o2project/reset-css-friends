= Reset CSSは何をリセットしているのか

ブラウザがWeb上のページを読み込むときに既定で使うCSSとして、@<kw>{ユーザーエージェントスタイルシート}があります。
このユーザーエージェントスタイルシートはブラウザ上でどのように指定されているか見ることができます。

#@# prh:disable
  * Chrome: https://chromium.googlesource.com/chromium/blink/+/master/Source/core/css/html.css
  * Firefox: https://dxr.mozilla.org/mozilla-central/source/layout/style/res/html.css
  * Safari: http://trac.webkit.org/browser/trunk/Source/WebCore/css/html.css

このユーザーエージェントスタイルシートですが、ブラウザごとに指定されているスタイルが違います。
そのため別途Reset CSSを使わなかった場合、ブラウザによって見えかたが違うということが起きます@<fn>{user-agent-stylesheet-diff}。

この章では、各ブラウザがユーザーエージェントスタイルシート内へどういった指定をしているか解説し、その後Reset CSSがどのような指定をしているか見ていきます。
なお、解説するHTML要素は（@<list>{explain-elements}）のみに絞ります。
//footnote[user-agent-stylesheet-diff][https://developer.mozilla.org/ja/docs/Web/Compatibility_FAQ/Tips_Default_Style_Difference.html]

//list[explain-elements][解説するHTML要素一覧]{
html, body, img,
ul, ol, li,
table, tr, td,
h1, p, a, blockquote, br,
section, article, nav, aside,
header, footer, main,
form, input, textarea, button, select
//}

== html要素

まずはhtml要素です。ChromeとSafariでは@<code>{display: block;}の指定だけがあります。
いっぽうFirefoxでは@<code>{display: block;}以外にも、@<code>{unicode-bidi: isolate;}という複数の表記方向が混在する文章をどのように扱うか決める定義もされています。
@<code>{unicode-bidi}プロパティの値によって表示がどう変わるかは@<href>{http://www.osaka-kyoiku.ac.jp/~joho/html5_ref/css/unicode-bidi_css.php}を参照してください。

Reset CSS側ではsanitize.cssとress.cssが、html要素に対し@<code>{box-sizing: border-box;}を指定した上で、全称セレクタへ@<code>{box-sizing: inherit;}を指定しています。
このことでコンテンツ領域に@<code>{padding}や@<code>{border}の値が入るようになります。
これによりボックスサイズの計算をより簡単にすることを狙っていると思われます。

== body要素

body要素はChrome・Firefox・Safariで同様のスタイル定義がおこなわれています（@<list>{body-element}）。
ただし@<code>{margin: 8px;}の指定は多くのWebサイトにおいて不要な指定となるため、Reset CSSでは@<code>{margin: 0;}と指定されていることが多いです。

//list[body-element][body要素に対するスタイル定義]{
#@mapfile(../codes/body.css)
body {
  display: block;
  margin: 8px;
}
#@end
//}

Eric Meyer's Reset CSS、normalize.css、sanitize.css、YUI 3 Reset CSSでは@<code>{body}要素へ対し@<code>{margin: 0;}を指定しています。
Webページを作るときにページの外周へmarginを設定することはほとんど無いため、このような指定がされていると思われます。

== セクショニング・コンテンツとh1要素

h1要素は見出しを表す要素の中でもっともランクが高い要素です。
また@<code>{section}要素や@<code>{article}要素といったセクショニング・コンテンツへh1要素を入れた場合は、入れ子の深さに応じてスタイルが変わるようになっています。

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

normalize.cssやsanitize.cssではこの入れ子具合によってスタイルが変わるのを無くし、@<list>{h1-normalize}で示すスタイルが適用されるようになっています。

//list[h1-normalize][h1要素に対するnormalize.cssやsanitize.cssのスタイル定義]{
#@mapfile(../codes/h1-normalize.css)
h1 {
  font-size: 2em;
  margin: 0.67em 0;
}
#@end
//}

また、YUI 3 Reset CSSやEric Meyer's Reset CSSでは見出しらしいスタイル定義をすべて無かったことにしています（@<list>{h1-yui3}）。

//list[h1-yui3][h1要素に対するYUI 3 Reset CSSやEric Meyer's Reset CSSのスタイル定義]{
#@mapfile(../codes/h1-yui3.css)
h1 {
  margin:0;
  padding:0;
  font-size:100%;
  font-weight:normal;
}
#@end
//}

== p要素

Firefoxでは文字のレイアウト方向や向き、文字が流れる方向を元にマージンを設定する@<code>{margin-block-start}や@<code>{margin-block-end}が定義されています。
ちなみにCSSのプロパティでは、文字のレイアウト方向は@<code>{writing-mode}、文字の向きは@<code>{text-orientation}、文字の流れる方向は@<code>{direction}に対応しています。

ChromeやSafariでは、@<code>{margin-before}や@<code>{margin-after}といったプロパティが定義され、値として@<code>{1__qem}が定義されています。
これは、互換性モードで表示するときにmarginの相殺をおこなわないようにするものです。

YUI 3 Reset CSSやEric Meyer's Reset CSSといった古めのReset CSSでは@<code>{margin}と@<code>{padding}が0と指定されています。
しかし、他のReset CSSでは特に指定がなくユーザーエージェントスタイルシートをそのまま使うようにしています。

#@# prh:disable
これは新しく縦書きという概念が出てきたのに従い、Reset CSSで文字の方向や向き、流れる方向を意識するようになったためです。
その結果ユーザーエージェントスタイルシートをそのまま使ったほうが良いという結論に至ったと思われます。

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

img要素はiOSのSafari上でタップしたときにハイライトが適用されないようになっています。

//list[img-webkit][img要素に対するWebKitのスタイル定義]{
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

normalize.cssやsanitize.css、ressではIE 10でリンク内に画像があるとborderが適用されてしまうのを防ぐために、@<code>{border-style: none;}が指定されています。

== ul, ol要素

ulやol要素はFirefoxやChrome、Safariで論理marginとpaddingが指定されています@<list>{ul-firefox}。

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

入れ子になったulやol要素はFirefoxとChrome、Safariで指定しているプロパティは同じですが、セレクタの指定方法が違います。
Firefoxでは@<code>{:any()}という疑似クラスを使って、@<list>{ul-nested-firefox}のようにul要素やol要素などが入れ子になったときのスタイル指定をおこなっています@<fn>{mdn-any-pseudo-class}。
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

@<code>{:any()}や@<code>{:matches()}の仕様が固まっていないためか、ChromeやSafariでは@<list>{ul-nested-chrome}のように従来どおりの子孫セレクタを使った指定になっています。

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

sanitize.cssではnav要素が親要素としてあるときにol要素とul要素に対して@<code>{list-style: none;}の指定をしています@<list>{sanitize-ul-ol}。
実際に自分が開発しているときも、nav要素内に指定したol要素とul要素に対して@<code>{list-style}の値を指定することは少ないので、自分で書くスタイル指定を減らすことができます。

//list[sanitize-ul-ol][sanitize.cssのulやol要素に対するスタイル指定]{
#@mapfile(../codes/sanitize-ul-ol.css)
/**
 * Remove the list style on navigation lists in all browsers (opinionated).
 */

nav ol,
nav ul {
  list-style: none;
}
//}

== table要素

table要素のスタイル指定ですが、Firefoxでは非推奨となった属性にもスタイル指定をおこなっているのが特色です。
たとえば@<code>{align}や@<code>{frame}、@<code>{rules}といった属性が挙げられます（@<list>{table-firefox-1}）。

//list[table-firefox-1][Firefoxで指定されている非推奨の属性に対してのスタイル指定（一部）]{
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

またFirefox特有の指定として@<code>{-moz-is-html}という擬似クラスのようなセレクタ指定があります（@<list>{table-firefox-2}）。
この指定が何を示すのかJSFiddleで見てみようとしましたが、特に表示は変わりなく謎のままでした@<fn>{form-firefox}。
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

sanitize.cssでは@<code>{border-collapse: collapse;}の指定がされています（@<list>{sanitize-table}）。
これはtableのborderをセル同士で共有する指定になります。表を表示するときにセルを分けて表示することは少ないので、余計なスタイル指定を減らすことができます。

//list[sanitize-table][sanitize.cssのtable要素に対する指定]{
#@mapfile(../codes/sanitize-table.css)
/**
 * Collapse border spacing
 */

table {
  border-collapse: collapse;
}
#@end
//}

@<code>{border-collapse}の値によって表示がどのように変わるかは@<img>{table-border-collapse}で示すとおりです@<fn>{table-border-collapse-image}。
//footnote[table-border-collapse-image][画像の著作権はCC-BY-SA 2.5 © 2005-2017 Mozilla Developer Network & 貢献者各人です]

//image[table-border-collapse][border-collapseの指定によって表示が変わる]{
//}

== blockquote要素

blockquote要素はFirefoxで@<code>{[type=cite]}という属性に対するスタイル指定があります（@<list>{blockquote-firefox}）。
この属性は現在W3Cの仕様には無い仕様ですが、過去にはあったらしくFirefoxではいい感じの見た目になります@<img>{firefox-blockquote-type-cite}。

//list[blockquote-firefox][blockquote要素に対してのスタイル指定]{
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

//image[firefox-blockquote-type-cite][Firefoxでblockquote\[type="cite"\]をプレビューしてみた様子]{
//}

Eric Meyer's Reset CSSではblockquoteやq要素に対し引用符を消すスタイルが指定されています（@<list>{eric-meyers-blockquote}）。
なお、他のReset CSSには特徴的な指定がありません。

//list[eric-meyers-blockquote][Eric Meyer's Reset CSSのblockquote要素に対するスタイル指定]{
#@mapfile(../codes/eric-meyers-blockquote.css)
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

input要素はtype属性の値によって、@<img>{input-types}で示すように挙動が大きく変わります。
そのためChromeのユーザーエージェントスタイルシートでは1123行中295行がinput要素関連のスタイル指定です。
Safariに至っては1221行中421行がinput要素関連のスタイル指定です@<fn>{safari-user-agent-stylesheet-line}。
//footnote[safari-user-agent-stylesheet-line][Safariの場合iOS向けと思われるスタイル指定もあるためChromeと比較して行数が多いのかもしれません]
なおFirefoxは895行中24行がinput要素関連のスタイル指定です。

//image[input-types][input要素はtype属性の値によって挙動が大きく変わる]{
//}

//list[chrome-input][input要素へ対するChromeのスタイル指定]{
#@mapfile(../codes/browser/chrome/input.css)
input, textarea, keygen, select, button {
  margin: 0__qem;
  font: -webkit-small-control;
  text-rendering: auto; /* FIXME: Remove when tabs work with optimizeLegibility. */
  color: initial;
  letter-spacing: normal;
  word-spacing: normal;
  line-height: normal;
  text-transform: none;
  text-indent: 0;
  text-shadow: none;
  display: inline-block;
  text-align: start;
}

input {
  -webkit-appearance: textfield;
  padding: 1px;
  background-color: white;
  border: 2px inset;
  -webkit-rtl-ordering: logical;
  -webkit-user-select: text;
  cursor: auto;
}
#@end
//}

sanitize.cssでは他にない指定として@<code>{touch-action: manipulation;}があります（@<list>{sanitize-fix-tap-delay}）。
ページのスクロールとズームのみを許可する指定ですが、IE 10ではタップ時の遅延をなくす指定になります。

//list[sanitize-fix-tap-delay][IE 10でタップ時の遅延を無くすCSS]{
#@mapfile(../codes/sanitize-fix-tap-delay.css)
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
