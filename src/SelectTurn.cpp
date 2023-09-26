#include "SelectTurn.hpp"

SelectTurn::SelectTurn(const InitData& init)
:IScene{init} {
    Scene::SetBackground(Palette::Honeydew);
}

void SelectTurn::update()
{
    text(U"先攻は...").draw(10, 10, Palette::Black);
    
    if (SimpleGUI::Button(U"select turn", Vec2{300, 10})) {
        turn = RandomBool();
        if(turn == true) turns = U"左側の人";
        else turns = U"右側の人";
    }
    
    if(SimpleGUI::Button(U"Back", Vec2{ 50, 550 }) || KeyX.down()){
        changeScene(State::Game);
    }
}

void SelectTurn::draw() const
{
    show(turns).drawAt(400, 300, Palette::Black);
}
