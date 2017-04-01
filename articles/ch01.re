= Reset CSSとは何か

Reset CSSは、Web上のページを読み込んだときに既定で適用されるスタイル宣言（ユーザーエージェントスタイルシートとも呼ばれます）をリセットするものです。
Reset CSSは@<kw>{Hard reset}と呼ばれる「ユニバーサル（全称）セレクタを使ってすべてのmarginとpaddingを0にする」手法から始まりました（@<list>{hard-reset-css}）。
そこから今日にいたるまでさまざまな手法が開発されています。

//list[hard-reset-css][初期のReset CSSであるHard reset]{
#@mapfile(../codes/reset-css/hard-reset.css)
* {
  margin: 0;
  padding: 0;
}
#@end
//}

== なぜReset CSSはユーザーエージェントスタイルシートを上書きできるか

Reset CSSはユーザーエージェントスタイルシートでの宣言を上書きすることにより、スタイル宣言をリセットしています。
なぜリセットできるのでしょうか？それはスタイル宣言がされた場所（オリジン）によって適用されるスタイルの優先順位があるためです。
CSS Cascading and Inheritance Level 3（@<href>{https://www.w3.org/TR/css-cascade-3/#cascading}）から優先順を引用すると次のとおりです。

 1. transitionの宣言
 1. !important付きのユーザーエージェントスタイルシートでの宣言
 1. !important付きの利用者による宣言
 1. !important付きの上書き宣言
 1. !important付きの作者による宣言
 1. animationの宣言
 1. 上書き宣言
 1. 作者による宣言
 1. 利用者による宣言
 1. ユーザーエージェントスタイルシートでの宣言

ユーザーエージェントスタイルシートの宣言より作者による宣言、つまりHTMLファイルからリンクされたCSSなどの宣言が優先されるため、ユーザーエージェントスタイルシートのスタイル宣言を上書きできます。

== なぜReset CSSを使うのか

Reset CSSが使われる理由は、ブラウザが既定で読み込むユーザーエージェントスタイルシートがブラウザ間で差異があるためです。
例として@<code>{h1}要素と@<code>{p}要素のみ定義したHTMLをブラウザで見てみます。
Firefoxはセリフ@<fn>{font-serif}がないフォントで表示されます（@<img>{firefox-font}）が、Safariはセリフがあるフォントで表示されます（@<img>{safari-font}）。
//footnote[font-serif][文字の線の端にある小さな飾りのことです]

//image[firefox-font][Firefoxでプレビューしたときの見た目]{
//}

//image[safari-font][Safariでプレビューしたときの見た目]{
//}

このように単純なHTMLでも見た目に差異があります。h1要素やp要素の他にも差異はあるため、それを吸収するために何らかのReset CSSライブラリを使うか自分で差異を吸収する必要があります。

== Reset CSSを使わない場面

Reset CSSを使う理由として「ブラウザの既定で適用されるスタイル定義の差異を吸収するため」と書きました。
そのため@<kw>{NW.js}や@<kw>{Electron}といったChromiumしか存在しない環境ではReset CSSを使う必要はなく、必要に応じてユーザーエージェントスタイルシートのスタイル定義をリセットするとよいです。
