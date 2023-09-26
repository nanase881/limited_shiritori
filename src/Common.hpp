#pragma once
#include<Siv3D.hpp>

// シーンの名前
enum class State
{
    Title,
    Game,
    Help,
    SelectTurn,
    SelectTime,
};

// 共有するデータ
struct GameData
{
    Timer timerL{15min};
    Timer timerR{15min};
};

using App = SceneManager<State, GameData>;

