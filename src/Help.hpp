#pragma once
#include "Common.hpp"

class Help : public App::Scene{
public:
    Help(const InitData& init);
    void update() override;
    void draw() const override;
    
private:
    const Font head{50};
    const Font text{30};
};
