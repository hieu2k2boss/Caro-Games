#ifndef THEME_H
#define THEME_H

class Theme
{
private:
    int backgound_color;
    int text_color;

public:
    Theme(int backgound_color, int text_color);
    void SetColor() {};
    ~Theme();
};

#endif
