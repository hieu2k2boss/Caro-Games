#include "Theme.h"
#include <windows.h>

Theme::Theme(int backgound_color, int text_color) : backgound_color(backgound_color), text_color(text_color)
{
}

void Theme::SetColor()
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

Theme::~Theme()
{
}
