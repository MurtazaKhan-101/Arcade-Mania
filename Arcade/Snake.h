#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <tchar.h>
#include <dos.h>
#include <time.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, Score;
int tailX[100], tailY[100];
int nTail;
enum eDirection
{
    stop = 0,
    Left,
    Right,
    up,
    down
};
eDirection Dir;
void Setup()
{
    gameOver = false;
    Dir = stop;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    Score = 0;
}

void Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "\xB2";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "\xB2";
            }
            if (i == y && j == x)
            {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << "\xFE";
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }
            if (j == width - 1)
            {
                cout << "\xB2";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "\xB2";
    cout << endl;

    cout << "Score: " << Score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            Dir = Left;
            break;
        case 'd':
            Dir = Right;
            break;
        case 'w':
            Dir = up;
            break;
        case 's':
            Dir = down;
            break;
        case 'q':
            gameOver = true;
            break;
        default:
            break;
        }
    }
}

void Logic()
{
    int preX = tailX[0];
    int preY = tailY[0];
    int pre2X, pre2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        pre2X = tailX[i];
        pre2Y = tailY[i];
        tailX[i] = preX;
        tailY[i] = preY;
        preX = pre2X;
        preY = pre2Y;
    }
    switch (Dir)
    {
    case Left:
        x--;
        break;
    case Right:
        x++;
        break;
    case up:
        y--;
        break;
    case down:
        y++;
        break;
    default:
        break;
    }
    if (x >= width)
    {
        x = 0;
    }
    else if (x < 0)
    {
        x = width - 1;
    }
    if (y >= height)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = height - 1;
    }
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            PlaySound(_T("SnakeDeath.wav"), NULL, SND_ASYNC);
            gameOver = true;
        }
    }
    if (x == fruitX && y == fruitY)
    {
        PlaySound(_T("Consume.wav"), NULL, SND_ASYNC);
        Score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

void WelcomeScreen()
{
    cout << "\n            /^\\/^\\                                             ";
    cout << "\n          _|__|  O|                                              ";
    cout << "\n \\/     /~     \\_/ \\                                          ";
    cout << "\n  \\____|__________/  \\                                         ";
    cout << "\n         \\_______      \\                                       ";
    cout << "\n                 `\\     \\                 \\                   ";
    cout << "\n                   |     |                  \\                   ";
    cout << "\n                  /      /                    \\                 ";
    cout << "\n                 /     /                       \\\\              ";
    cout << "\n               /      /                         \\ \\            ";
    cout << "\n              /     /                            \\  \\          ";
    cout << "\n            /     /             _----_            \\   \\        ";
    cout << "\n           /     /           _-~      ~-_         |   |          ";
    cout << "\n          (      (        _-~    _--_    ~-_     _/   |          ";
    cout << "\n           \\      ~-____-~    _-~    ~-_    ~-_-~    /          ";
    cout << "\n             ~-_           _-~          ~-_       _-~            ";
    cout << "\n                ~--______-~                ~-___-~               ";
    cout << "\nPress any Key To continue\n";
    _getch();
    PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
}

void Reset()
{
    gameOver = false;
    Dir = stop;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    Score = 0;
    nTail = 0;
    for (int i = 0; i < 100; i++)
    {
        tailX[i] = 0;
        tailY[i] = 0;
    }
}