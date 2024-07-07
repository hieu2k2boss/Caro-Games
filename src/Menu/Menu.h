#ifndef MENU_H
#define MENU_H

// Mã escape ANSI cho các màu
#define RESET "\033[0m"
#define BLACK "\033[30m"   /* Đen */
#define RED "\033[31m"     /* Đỏ */
#define GREEN "\033[32m"   /* Xanh lá cây */
#define YELLOW "\033[33m"  /* Vàng */
#define BLUE "\033[34m"    /* Xanh dương */
#define MAGENTA "\033[35m" /* Tím */
#define CYAN "\033[36m"    /* Xanh lam nhạt */
#define WHITE "\033[37m"   /* Trắng */

class Menu
{
private:
    // Theme setColor;
public:
    Menu();
    int choiceMainMenu();
    int choicePlayWithBot();
    ~Menu();
};

#endif