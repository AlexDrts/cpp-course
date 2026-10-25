#include <iostream>
#include <algorithm>
#include <windows.h> 
#include <conio.h>
using namespace std;

enum GameObject : short { HALL, WALL, COIN, ENEMY, MEDKIT };  // додаэмо аптечку
enum Color : short {
	BLACK, DARKBLUE, DARKGREEN, TURQUOISE, DARKRED,
	PURPLE, DARKYELLOW, GREY, DARKGREY, BLUE, GREEN,
	CYAN, RED, PINK, YELLOW, WHITE
};
enum Key : short {
	LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80,
	ENTER = 13, SPACE = 32, ESCAPE = 27, BACKSPACE = 8
};

int main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));
	rand();
	system("title Bomberman");

	// cursor hide
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = false;
	cursor.dwSize = 100; // 1-100
	SetConsoleCursorInfo(h, &cursor);

	const int HEIGHT = 25;
	const int WIDTH = 65;
	int map[HEIGHT][WIDTH] = {};
	// ASCII Table
	//for (int i = 0; i < 256; i++)
	//{
	//	cout << (char)i << " - " << i << "\n";
	//}

	// MODEL (логіка заповнення масиву)
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			map[y][x] = rand() % 5; // 0 1 2 3  // додэмо для аптечки

			// рамка по краях
			if (x == 0 || y == 0 || x == WIDTH - 1 || y == HEIGHT - 1)
				map[y][x] = GameObject::WALL;

			// отвори для входу і виходу
			if (x == 0 && y == 2 ||
				x == 1 && y == 2 ||
				x == 2 && y == 2 ||

				x == WIDTH - 1 && y == HEIGHT - 3 ||
				x == WIDTH - 2 && y == HEIGHT - 3 ||
				x == WIDTH - 3 && y == HEIGHT - 3)
				map[y][x] = GameObject::HALL;

			if (map[y][x] == GameObject::ENEMY) {
				int r = rand() % 10; // 0 1 2 3 4 5 6 7 8 9
				if (r != 0) {
					map[y][x] = GameObject::HALL;
				}
			}
		}
	}

	///////////////////////////////////////////////////////////

	// VIEW (подання - як буде виглядати ігрова локація)
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			switch (map[y][x]) {
			case GameObject::HALL: // 0
				// як показати коридор
				SetConsoleTextAttribute(h, Color::BLACK);
				cout << " ";
				break;
			case GameObject::WALL: // 1
				SetConsoleTextAttribute(h, Color::DARKGREEN);
				// cout << "#";
				cout << (char)178;
				break;
			case GameObject::COIN:
				SetConsoleTextAttribute(h, Color::YELLOW);
				cout << ".";
				break;
			case GameObject::ENEMY:
				SetConsoleTextAttribute(h, Color::RED);
				cout << "O";
				break;
			case GameObject::MEDKIT:
				SetConsoleTextAttribute(h, Color::TURQUOISE);          // аптечка
				cout << "+";
				break;

				// case GameObject::SMTH_ELSE:
					// як показати щось інше
				//	break;
			}

		}
		cout << "\n";
	}

	////////////////////////////////////////////////////////////
	// показ ГГ
	COORD hero;
	hero.X = 0;
	hero.Y = 2;
	SetConsoleCursorPosition(h, hero);
	SetConsoleTextAttribute(h, Color::BLUE);
	cout << "O";

	int coins_collected = 0;
	int hp = 100;                    //hp   

	COORD coins_info;
	coins_info.X = WIDTH + 1;
	coins_info.Y = 0;
	SetConsoleCursorPosition(h, coins_info);
	SetConsoleTextAttribute(h, Color::DARKYELLOW);
	cout << "COINS: ";
	SetConsoleTextAttribute(h, Color::YELLOW);
	cout << coins_collected;

	COORD hp_info;
	hp_info.X = WIDTH + 1;
	hp_info.Y = 1;
	SetConsoleCursorPosition(h, hp_info);
	SetConsoleTextAttribute(h, Color::RED);                           // аптечка
	cout << "HP: ";
	SetConsoleTextAttribute(h, Color::DARKRED);
	cout << hp;

	// ігровий двигунчик
	while (true) {
		int code = _getch(); // get character
		if (code == 224) {
			code = _getch();
		}

		COORD old_position = hero;
		bool has_been_moved = false; // false - пересування не було

		// cout << code << "\n";
		switch (code) {
		case Key::LEFT:
			if (hero.X > 0 && map[hero.Y][hero.X - 1] != GameObject::WALL) {
				has_been_moved = true;
				hero.X--;
			}
			break;
		case Key::RIGHT:
			if (map[hero.Y][hero.X + 1] != GameObject::WALL) {
				has_been_moved = true;
				hero.X++;
			}
			break;
		case Key::UP:
			if (map[hero.Y - 1][hero.X] != GameObject::WALL) {
				has_been_moved = true;
				hero.Y--;
			}
			break;
		case Key::DOWN:
			if (map[hero.Y + 1][hero.X] != GameObject::WALL) {
				has_been_moved = true;
				hero.Y++;
			}
			break;
		}

		if (has_been_moved) {
			// стирання ГГ в "старих" координатах
			SetConsoleCursorPosition(h, old_position);
			SetConsoleTextAttribute(h, Color::BLACK);
			cout << " ";
			// перемальовка ГГ в нових координатах
			SetConsoleCursorPosition(h, hero);
			SetConsoleTextAttribute(h, Color::BLUE);
			cout << "O";
		}

		// приклад перевірки на перетинання з якимось об'єктом в лабірінті
		if (map[hero.Y][hero.X] == GameObject::COIN) {
			// cout << "COIN";
			coins_collected++;
			map[hero.Y][hero.X] = GameObject::HALL;
			COORD coins_info;
			coins_info.X = WIDTH + 1;
			coins_info.Y = 0;
			SetConsoleCursorPosition(h, coins_info);
			SetConsoleTextAttribute(h, Color::DARKYELLOW);
			cout << "COINS: ";
			SetConsoleTextAttribute(h, Color::YELLOW);
			cout << coins_collected;
		}

		// збір ліків
		if (map[hero.Y][hero.X] == GameObject::MEDKIT) {
			if (hp < 100) {
				hp += 25;
				if (hp > 100) hp = 100;
				map[hero.Y][hero.X] = GameObject::HALL;
				SetConsoleCursorPosition(h, hp_info);
				SetConsoleTextAttribute(h, Color::RED);
				cout << "HP: ";
				SetConsoleTextAttribute(h, Color::DARKRED);
				cout << hp << "   ";
			}
		}

		// зустріч з ворогом
		if (map[hero.Y][hero.X] == GameObject::ENEMY) {
			hp -= 50;
			map[hero.Y][hero.X] = GameObject::HALL;
			SetConsoleCursorPosition(h, hp_info);
			SetConsoleTextAttribute(h, Color::RED);
			cout << "HP: ";
			SetConsoleTextAttribute(h, Color::DARKRED);
			cout << hp << "   ";
		}

		// Перевірка перемоги через вихід
		if (hero.X == WIDTH - 1 && hero.Y == HEIGHT - 3) {
			system("cls"); // очищуе экран
			cout << "Victory  a solution has been found!";
			break;
		}

		// Перевірка перемоги через зібрані монети
		bool all_coins_collected = true;
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				if (map[y][x] == GameObject::COIN) {
					all_coins_collected = false;
					break;
				}
			}
			if (!all_coins_collected) break;
		}
		if (all_coins_collected) {
			system("cls");
			cout << "Victory  coins collected!";
			break;
		}

		// Перевірка поразки через втрату здоров'я
		if (hp <= 0) {
			system("cls");
			cout << "Defeat  health is gone!";
			break;
		}
	}

	Sleep(INFINITE);
}
