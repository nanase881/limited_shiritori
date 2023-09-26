#pragma once
#include "Common.hpp"

class SelectTurn : public App::Scene{
public:
    SelectTurn(const InitData& init);
    void update() override;
    void draw() const override;
    
private:
    const Font text{50};
    const Font show{80};
    bool turn;
    String turns;
};
