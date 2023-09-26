#include "Common.hpp"
#include "Title.hpp"
#include "Game.hpp"
#include "Help.hpp"
#include "SelectTurn.hpp"
#include "SelectTime.hpp"


/*
 限界しりとり補助ツール　完全版(仮)
 現在、
 ・チェスクロック
 ・文字数表示
 ・遊び方表示
 ・先攻・後攻決め
 ・コマンド表示
 のみ実装されています
 
 */
void Main()
{
    FontAsset::Register(U"TitleFont", FontMethod::MSDF, 50, U"example/font/RocknRoll/RocknRollOne-Regular.ttf");
    FontAsset(U"TitleFont").setBufferThickness(4);
    FontAsset::Register(U"Menu", FontMethod::MSDF, 40, Typeface::Medium);
    FontAsset::Register(U"Ranking", 40, Typeface::Heavy);
    FontAsset::Register(U"GameScore", 30, Typeface::Light);
    AudioAsset::Register(U"Brick", GMInstrument::Woodblock, PianoKey::C5, 0.2s, 0.1s);
    
    Window::SetTitle(U"Limited Shiritori");
    
    App manager;
    manager.add<Title>(State::Title);
    manager.add<Game>(State::Game);
    manager.add<Help>(State::Help);
    manager.add<SelectTurn>(State::SelectTurn);
    manager.add<SelectTime>(State::SelectTime);

    // ゲームシーンから開始したい場合はこのコメントを外す
    //manager.init(State::Game);

    while (System::Update())
    {
        if (not manager.update())
        {
            break;
        }
    }
}
