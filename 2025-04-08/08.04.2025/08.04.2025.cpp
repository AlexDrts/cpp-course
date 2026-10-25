#include "Header.h"


int main() {
    srand(time(0));
    system("title Bomberman");

    // Сховати курсор
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = false;
    cursor.dwSize = 100;
    SetConsoleCursorInfo(h, &cursor);

    int map[HEIGHT][WIDTH] = {};
    InitAndDrawMap(map);

    COORD hero = { 0, 2 };
    DrawHero(hero);

    GameLoop(map, hero);

    Sleep(INFINITE);
}


