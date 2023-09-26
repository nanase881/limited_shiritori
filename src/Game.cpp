#include"Game.hpp"

        // コンストラクタ（必ず実装）
Game::Game(const InitData& init)
: IScene{ init }{
    Scene::SetBackground(ColorF{ 0.3, 0.6, 1.0 }); //背景色
    
}

        // 更新関数（オプション）
void Game::update()
{

    
    if (KeyA.down() || lefts.leftClicked()) {
        if(leftf == 0 && rightf == 0){
            getData().timerR.start();
            getData().timerL.pause();
            leftf = 0;
            rightf = 1;
        }else{
            getData().timerL.pause();
            getData().timerR.start();
            leftf = 0;
            rightf = 1;
        }
    }else if(KeyL.down() || rights.leftClicked()){
        if(rightf == 0 && leftf == 0){
            getData().timerL.start();
            getData().timerR.pause();
            rightf = 0;
            leftf = 1;
        }else{
            getData().timerR.pause();
            getData().timerL.start();
            rightf = 0;
            leftf = 1;
        }
    }else if(KeySpace.down() || centers.leftClicked()){
        if(leftf == 1 || rightf == 1){
            getData().timerL.pause();
            getData().timerR.pause();
            leftf = rightf = 0;
            //centerf = 1;
        }else /*if(centerf == 1)*/{
            getData().timerL.reset();
            getData().timerR.reset();
            word = U" ";
            color = Palette::White;
            leftf = rightf = 0;
        }
        
    }
    
    if (KeyN.down() || number.leftClicked()) {
        word = words.choice();
        color = RandomColor();
    }
    
    if(SimpleGUI::Button(U"Help", Vec2{ 30, 550 }) || KeyH.down()){
        changeScene(State::Help);
    }
    
    if(SimpleGUI::Button(U"Turn", Vec2{140, 550}) || KeyP.down()){
        changeScene(State::SelectTurn);
    }
    
    if(SimpleGUI::Button(U"Time", Vec2{570, 550}) || KeyT.down()){
        changeScene(State::SelectTime);
    }
    
    SimpleGUI::CheckBox(dl, U"文字数減らし", Vec2{ 20, 420 });
    SimpleGUI::CheckBox(dr, U"文字数減らし", Vec2{ 605, 420 });
    SimpleGUI::CheckBox(nl, U"「ん」廻し", Vec2{ 20, 460 });
    SimpleGUI::CheckBox(nr, U"「ん」廻し", Vec2{ 605, 460 });
    SimpleGUI::CheckBox(kl, U"広辞苑", Vec2{ 20, 500 });
    SimpleGUI::CheckBox(kr, U"広辞苑", Vec2{ 605, 500 });
}

        // 描画関数（オプション）
void Game::draw() const
{
    
    leftTimer.draw();
    rightTimer.draw();
    lefts.draw();
    rights.draw();
    centers.draw();
    number.draw().drawFrame(3, 3, color);
    
    font(getData().timerL).draw(40, 110, Palette::Black);
    font(getData().timerR).draw(450, 110, Palette::Black);
    font(word).draw(Arg::center(400, 350), Palette::Black);
    
    button(leftTxt).draw(40, 330, Palette::Black);
    button(rightTxt).draw(625, 330, Palette::Black);
    space(centerTxt).draw(270, 460, Palette::Black);

}


    
    

//
// = アドバイス =
// アプリケーションをビルドして実行するたびにファイルアクセス許可のダイアログが表示されるのを避けたい場合、
// プロジェクトのフォルダを ユーザ/(ユーザ名)/アプリケーション/ などに移動させると良いです。
// Web カメラ、マイク使用時の許可ダイアログは消せません。
//
// = お役立ちリンク | Quick Links =
//
// Siv3D リファレンス
// https://zenn.dev/reputeless/books/siv3d-documentation
//
// Siv3D Reference
// https://zenn.dev/reputeless/books/siv3d-documentation-en
//
// Siv3D コミュニティへの参加
// Slack や Twitter, BBS で気軽に質問や情報交換ができます。
// https://zenn.dev/reputeless/books/siv3d-documentation/viewer/community
//
// Siv3D User Community
// https://zenn.dev/reputeless/books/siv3d-documentation-en/viewer/community
//
// 新機能の提案やバグの報告 | Feedback
// https://github.com/Siv3D/OpenSiv3D/issues
//
