#include "Help.hpp"


Help::Help(const InitData& init)
:IScene{init} {
    Scene::SetBackground(Palette::Honeydew);
}

void Help::update()
{
    head(U"限界しりとりの遊び方").draw(10, 10, Palette::Black);
    text(U"・引いたトランプの数字分の言葉でしりとりを行う").draw(10, 80, Palette::Black);
    text(U"・トランプは2からJ(11)を使用").draw(10, 120, Palette::Black);
    text(U"・Jは11文字以上であれば良い").draw(10, 160, Palette::Black);
    text(U"・持ち時間は1人15分").draw(10, 200, Palette::Black);
    text(U"・各自1回までコマンドが使える").draw(10, 240, Palette::Black);
    text(U"・濁点、半濁点は付け外し出来ない").draw(10, 280, Palette::Black);
    text(U"・長音は1文字に数え、長音で終わる場合はその前の文字\n   で続ける").draw(10, 320, Palette::Black);
    text(U"\n・小さい文字も1文字に数え、小さい文字で終わる場合は\n   その文字で続ける (例　シチュー→ゆ)").draw(10, 360, Palette::Black);
    text(U"・「ぶ」の時は「ゔ」でも良い").draw(10, 480, Palette::Black);
    
    if(SimpleGUI::Button(U"Back", Vec2{ 50, 550 }) || KeyX.down()){
        changeScene(State::Game);
    }
}

void Help::draw() const
{
    
}

