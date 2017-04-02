= Reset CSSとは何か

ここからReset CSSについて解説するよ！かばんちゃんから教えてもらったことを、できるだけ分かりやすく私が教えるからね！

Reset CSSっていうのは、Webページを読み込んだときに既定で適用されるスタイル@<fn>{user-agent-stylesheet}をリセットするものだよ！

@<kw>{Hard reset}っていう「ユニバーサル（全称）セレクタを使ってすべてのmarginとpaddingを0にする」ところから始まったんだよ！（@<list>{hard-reset-css}）
そこから今までさまざまなReset CSSのフレンズが生まれたんだって！すっごーい！
//footnote[user-agent-stylesheet][ユーザーエージェントスタイルシートとも呼ばれます]

//list[hard-reset-css][初期のReset CSSであるHard reset]{
#@mapfile(../codes/reset-css/hard-reset.css)
* {
  margin: 0;
  padding: 0;
}
#@end
//}

== なぜReset CSSはユーザーエージェントスタイルシートを上書きできるか

Reset CSSはユーザーエージェントスタイルシートの宣言を上書きすることで、既定で適用されるスタイルをリセットしているんだよ！
なんでリセットできるかって？それはスタイル宣言がされたちほー（オリジン）によって適用されるスタイルの優先順位があるためなんだって。
よくわかんないけど、CSS Cascading and Inheritance Level 3（@<href>{https://www.w3.org/TR/css-cascade-3/#cascading}）から優先順位を引用すると次のとおりみたい。

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

たとえばユーザーエージェントスタイルシートの宣言より、HTMLファイルからリンクされたCSS内の宣言が優先されるんだって。
だからユーザーエージェントスタイルシートのスタイル宣言を上書きできるんだよー！
…うー、ボスー！ちょっとよく分かんないよー！

== なぜReset CSSを使うのか

Reset CSSを使うのは、ブラウザが既定で読み込むユーザーエージェントスタイルシートがブラウザ間で違いがあるからなんだよ！
たとえば@<code>{h1}要素と@<code>{p}要素だけ書いたHTMLをブラウザで見てみるよ。

するとFirefoxはセリフ@<fn>{font-serif}がないフォントだけど（@<img>{firefox-font}）、Safariはセリフがあるフォントだよ（@<img>{safari-font}）。ふっしぎー！
//footnote[font-serif][文字の線の端にある小さな飾りのことです]

//image[firefox-font][Firefoxでプレビューしたときの見た目]{
//}

//image[safari-font][Safariでプレビューしたときの見た目]{
//}

こんな感じで単純なHTMLにも見た目に違いはあるんだよ！ブラウザによって得意なことは違うからなんらかのReset CSSライブラリを使うか自分で違いを吸収する必要があるんだってー！

== Reset CSSを使わない場面

Reset CSSを使うのは、ブラウザが既定で適用するスタイルがブラウザ間で違いがあるからだけど、@<kw>{NW.js}？や@<kw>{Electron}？みたいな@<kw>{Chromium}？しか無いちほーではReset CSSを使わなくていいんだって！
