#pragma once
#include "Common.hpp"

class SelectTime : public App::Scene{
public:
    SelectTime(const InitData& init);
    void update() override;
    void draw() const override;
    
    TextEditState time;
    Duration tmp;
    Minutes time2;
    
private:
    const Font text{30};
    String message;
};
