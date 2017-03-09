= reset.cssとは

reset.cssは、Web上のページを読み込んだときに既定で適用されるスタイル定義をリセットするためのものです。
reset.cssは@<kw>{Hard reset}とも呼ばれるユニバーサルセレクタを使ってすべてのmarginとpaddingを0にする手法から始まりました（@<list>{hard-reset-css}）。
そして今日に至るまでさまざまな手法が開発されています。

//list[hard-reset-css][初期のreset.cssであるHard reset]{
#@mapfile(../codes/hard-reset.css)
* {
  margin: 0;
  padding: 0;
}
#@end
//}

== なぜreset.cssを使うのか

reset.cssが使われる理由としてはブラウザが既定で定義するCSS（ユーザーエージェントCSSとも呼ばれます）がブラウザによって差異があるためです。
例として@<code>{h1}要素と@<code>{p}要素を定義しただけのHTMLをブラウザで見てみます。
するとFirefoxではセリフがないフォントで表示されています（@<img>{firefox-font}）が、Safariではセリフがあるフォントで表示されます（@<img>{safari-font}）。

//image[firefox-font][Firefoxでプレビューしたときの様子]{
//}

//image[safari-font][Safariでプレビューしたときの様子]{
//}

このようにフォント1つとっても差異があります。もちろん他にも差異はあるため、それを吸収するために何らかのreset.cssライブラリを使うか、自分で差異を吸収する必要があります。

== reset.cssを使わない場面

reset.cssを使う理由として「ブラウザが既定で定義しているCSSの差異を吸収するため」と書きました。
そのためNW.jsやElectronといったChromiumしか存在しない環境ではreset.cssを使う必要はなく、必要に応じて各要素をリセットしたほうがよいです。
