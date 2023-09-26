#include"Common.hpp"

class Game : public App::Scene{
public:
    Game(const InitData& init);
    void update() override;
    void draw() const override;
    
//    String left = timerL.format();
//    String right = timerR.format();

private:
    const Font font{60};
    const Font space{40};
    const Font button{30};
    const Array<String> words =
    {
        U"2",U"3",U"4",U"5",U"6",U"7",U"8",U"9",U"10",U"J"
    };
    
    const PlayingCard::Pack pack{ 75, Palette::Red };
    
    
    
    
    
    
    const String leftTxt = U"Press[A]!";
    const String rightTxt = U"Press[L]!";
    const String centerTxt = U"Press[Space]!";
    
    int leftf = 0, rightf = 0;/*, centerf = 0*/;
    String word;
    ColorF color = Palette::White;
    
    bool dl = false;
    bool dr = false;
    bool nl = false;
    bool nr = false;
    bool kl = false;
    bool kr = false;
    
    Rect leftTimer{20, 60, 350, 200}; //左側のタイマー
    Rect rightTimer{430, 60, 350, 200}; //右側のタイマー
    Rect lefts{20, 300, 175, 100}; //左側のスイッチ
    Rect rights{605, 300, 175, 100}; //右側のスイッチ
    Rect centers{250, 440, 300, 100}; //全体のスイッチ
    Rect number{350, 300, 100, 100};//ランダムに数字を表示(2-J)
    
};
