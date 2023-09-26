#include "SelectTime.hpp"

SelectTime::SelectTime(const InitData& init)
:IScene{init} {
    Scene::SetBackground(Palette::Honeydew);
}

void SelectTime::update()
{
    if(SimpleGUI::TextBox(time, Vec2{ 100, 140 })){
        message.clear();
    }
    
    if(SimpleGUI::Button(U"ChangeTime", Vec2{100, 200})){
//        実装出来ていません
//        tmp = Parse<Duration>(Format(time.text));
//        Print << time.text;
//        time2 = tmp;
//        getData().timerL.set(0min);
//        getData().timerR.set(60s);
        time.clear();
        message = U"Changed the count time!";

    }
    
    if(SimpleGUI::Button(U"Back", Vec2{ 50, 550 }) || KeyX.down()){
        changeScene(State::Game);
    }
}

void SelectTime::draw() const
{
    text(message).draw(100, 300, Palette::Black);
}
