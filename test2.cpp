#include<iostream>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int a = 1;
    int b = 2;
    int c = MAX(++a, ++b);
    std::cout << c;  
    return 0;
}