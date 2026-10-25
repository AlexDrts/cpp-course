#include <iostream>
#include <windows.h> // COORD HANDLE SetConsoleTextAttribute SetConsoleCursorPosition
#include <conio.h> // _getch
using namespace std;

void InitAndDrawMap(int map[][65]);
void DrawHero(COORD hero);
void UpdateCoinsInfo(int coins);
void HandleInput(int map[][65], COORD& hero, int& coins_collected);
void GameLoop(int map[][65], COORD hero);

enum GameObject : short { HALL, WALL, COIN, ENEMY };
enum Color : short {
    BLACK, DARKBLUE, DARKGREEN, TURQUOISE, DARKRED,
    PURPLE, DARKYELLOW, GREY, DARKGREY, BLUE, GREEN,
    CYAN, RED, PINK, YELLOW, WHITE
};
enum Key : short { LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80, ENTER = 13, SPACE = 32, ESCAPE = 27, BACKSPACE = 8 };

const int HEIGHT = 25;
const int WIDTH = 65;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


void InitAndDrawMap(int map[][65]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[y][x] = rand() % 4;
            if (x == 0 || y == 0 || x == WIDTH - 1 || y == HEIGHT - 1)
                map[y][x] = WALL;
            if ((x == 0 && y == 2) || (x == 1 && y == 2) || (x == 2 && y == 2) ||
                (x == WIDTH - 1 && y == HEIGHT - 3) || (x == WIDTH - 2 && y == HEIGHT - 3) || (x == WIDTH - 3 && y == HEIGHT - 3))
                map[y][x] = HALL;
            if (map[y][x] == ENEMY) {
                int r = rand() % 10;
                if (r != 0) map[y][x] = HALL;
            }

            switch (map[y][x]) {
            case HALL:
                SetConsoleTextAttribute(h, BLACK);
                cout << " ";
                break;
            case WALL:
                SetConsoleTextAttribute(h, DARKGREEN);
                cout << (char)178;
                break;
            case COIN:
                SetConsoleTextAttribute(h, YELLOW);
                cout << ".";
                break;
            case ENEMY:
                SetConsoleTextAttribute(h, RED);
                cout << "O";
                break;
            }
        }
        cout << "\n";
    }
}

void DrawHero(COORD hero) {
    SetConsoleCursorPosition(h, hero);
    SetConsoleTextAttribute(h, BLUE);
    cout << "O";
}

void UpdateCoinsInfo(int coins) {
    COORD coins_info;
    coins_info.X = WIDTH + 1;
    coins_info.Y = 0;
    SetConsoleCursorPosition(h, coins_info);
    SetConsoleTextAttribute(h, DARKYELLOW);
    cout << "COINS: ";
    SetConsoleTextAttribute(h, YELLOW);
    cout << coins;
}

void HandleInput(int map[][65], COORD& hero, int& coins_collected) {
    if (_kbhit()) {
        int code = _getch();
        if (code == 224) {
            code = _getch();
        }

        COORD old_position = hero;
        bool moved = false;

        switch (code) {
        case LEFT:
            if (hero.X > 0 && map[hero.Y][hero.X - 1] != WALL) {
                hero.X--;
                moved = true;
            }
            break;
        case RIGHT:
            if (map[hero.Y][hero.X + 1] != WALL) {
                hero.X++;
                moved = true;
            }
            break;
        case UP:
            if (map[hero.Y - 1][hero.X] != WALL) {
                hero.Y--;
                moved = true;
            }
            break;
        case DOWN:
            if (map[hero.Y + 1][hero.X] != WALL) {
                hero.Y++;
                moved = true;
            }
            break;
        }

        if (moved) {
            SetConsoleCursorPosition(h, old_position);
            SetConsoleTextAttribute(h, BLACK);
            cout << " ";
            DrawHero(hero);
        }

        if (map[hero.Y][hero.X] == COIN) {
            coins_collected++;
            map[hero.Y][hero.X] = HALL;
            UpdateCoinsInfo(coins_collected);
        }

        if (map[hero.Y][hero.X] == ENEMY) {
            SetConsoleCursorPosition(h, { 0, HEIGHT + 1 });
            SetConsoleTextAttribute(h, RED);
            cout << "YOU WERE KILLED!";
            Sleep(3000);
            exit(0);
        }
    }
}

void GameLoop(int map[][65], COORD hero) {
    int coins_collected = 0;
    UpdateCoinsInfo(coins_collected);

    while (true) {
        HandleInput(map, hero, coins_collected);
        Sleep(50);
    }
}
