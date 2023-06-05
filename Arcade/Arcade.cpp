#include <iostream>
#include <string>
#include <windows.h>
#include "Snake.h"
#include "flappybird.h"
#include "Pong.h"
#include "LeaderBoard.h"
#include "LeaderBoard2.h"

using namespace std;

string Takechoice()
{
    string choice;
    while (true)
    {
        system("cls");
        for (int i = 0; i < 12; i++)
        {
            cout << endl;
        }
        cout << "                                       ";
        cout << "1. Play Game\n"; 
        cout << "                                       ";
        cout << "2. See LeaderBoard\n"; 
        cout << "                                       ";
        cout << "3. Exit\n"; 
        cout << "                                       ";
        cout << "Enter Your Choice : ";
        cin >> choice;
        PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
        system("cls");
        for (int i = 0; i < choice.size(); i++)
        {
            if (isdigit(choice[i]))
                return choice;
            else
            {
                cout << "Invalid Selection!!\n\n";
                Sleep(500);
                system("cls");
                continue;
            }
        }
    }
}

string Gamechoice()
{
    string choice;
    while (true)
    {
        system("cls");
        for (int i = 0; i < 12; i++)
        {
            cout << endl;
        }
        cout << "                                         ";
        cout << "1. Snake Game\n";
        cout << "                                         ";
        cout << "2. Flappy Bird\n";
        cout << "                                         ";
        cout << "3. Ping Pong\n";
        cout << "                                         ";
        cout << "4. Back\n";
        cout << "                                ";
        cout << "Choose the game you want to play : ";
        cin >> choice;
        PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
        system("cls");
        for (int i = 0; i < choice.size(); i++)
        {
            if (isdigit(choice[i]))
                return choice;
            else
            {
                cout << "Invalid Selection!!\n\n";
                Sleep(500);
                system("cls");
                continue;
            }
        }
    }
}

string Boardchoice()
{
    string choice;
    while (true)
    {
        system("cls");
        for (int i = 0; i < 12; i++)
        {
            cout << endl;
        }
        cout << "                                    ";
        cout << "1. Snake Game LeaderBoard\n";
        cout << "                                    ";
        cout << "2. Flappy Bird LeaderBoard\n";
        cout << "                                    ";
        cout << "3. Ping Pong LeaderBoard\n";
        cout << "                                ";
        cout << "Choose the game you want to play : ";
        cin >> choice;
        PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
        system("cls");
        for (int i = 0; i < choice.size(); i++)
        {
            if (isdigit(choice[i]))
                return choice;
            else
            {
                cout << "Invalid Selection!!\n\n";
                Sleep(500);
                system("cls");
                continue;
            }
        }
    }
}

string Difficulty()
{
    string choice;
    while (true)
    {
        system("cls");
        for (int i = 0; i < 12; i++)
        {
            cout << endl;
        }
        cout << "                                    ";
        cout << "1. Easy\n";
        cout << "                                    ";
        cout << "2. Medium\n";
        cout << "                                    ";
        cout << "3. Hard\n";
        cout << "                                ";
        cout << "Select the Difficulty Level : ";
        cin >> choice;
        PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
        system("cls");
        for (int i = 0; i < choice.size(); i++)
        {
            if (isdigit(choice[i]))
                return choice;
            else
            {
                cout << "Invalid Selection!!\n\n";
                Sleep(500);
                system("cls");
                continue;
            }
        }
    }
}

bool checkInteger(string input)
{

    for (int i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]))
            return true;
    }
    return false;
}

void StartUp()
{
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
    }
    cout << "                             ";
    for (int i = 0; i < 20; i++)
    {
        cout << "\xDF ";
    }
    cout << endl;
    cout << "                             ";
    cout << "\xDF " << "                       " << "             \xDF\n";
    cout << "                             ";
    cout << "\xDF " << "            Arcade Mania" << "            \xDF\n";
    cout << "                             ";
    cout << "\xDF " << "                       " << "             \xDF\n";
    cout << "                             ";
    cout << "\xDF " << "                       " << "             \xDF\n";
    cout << "                             ";
    for (int i = 0; i < 20; i++)
    {
        cout << "\xDF ";
    }
    cout << endl;
    cout << "                                   ";
    cout << "Press Any Key To continue...";

    PlaySound(_T("shuruDaGana.wav"), NULL, SND_ASYNC| SND_LOOP);
    _getch();
    PlaySound(NULL, NULL, SND_ASYNC);
    PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
} 

int main()
{
    string Name, ID;
    string p1, p2;
    string I1, I2;
    string choice;
    string gameChoice;
    string boardChoice;
    string difficulty;
    
    LeaderBoard SBoard = LeaderBoard();
    SBoard.InsertFromSnakeFile();
    LeaderBoard BBoard = LeaderBoard();
    BBoard.InsertFromBirdFile();
    LeaderBoard2P PBoard = LeaderBoard2P();
    PBoard.InsertFromPongFile();

    system("cls");

    char PlayAgain;
    char BackToOptions;

    system("cls");
    system("color 0A");
    StartUp();

    while (true)
    {
        choice = Takechoice();
        system("cls");
        while (choice == "1")
        {
            system("cls");
            gameChoice = Gamechoice();
            system("cls");
            while (gameChoice == "1")
            {
                system("cls");
                for (int i = 0; i < 12; i++)
                {
                    cout << endl;
                }
                cout << "                                       ";
                cout << "Enter Your Name: ";
                //getline(cin, Name);
                cin >> Name;
                cout << "                                       ";
                while (true)
                {
                    cout << "Enter Your Game ID: ";
                    cin >> ID;
                    if (checkInteger(ID) == true)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Enter Game ID as an integer nothing else!!\n";
                        continue;
                    }
                }
                PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
                if (!SBoard.Search(ID))
                {
                    SBoard.InsertPlayer(Name, ID, 0);
                }
                Reset();
                system("cls");
                WelcomeScreen();
                difficulty = Difficulty();
                if (difficulty == "1")
                {
                    Setup();
                    while (!gameOver)
                    {
                        Draw();
                        Input();
                        Logic();
                        Sleep(100);
                    }
                }
                else if (difficulty == "2")
                {
                    Setup();
                    while (!gameOver)
                    {
                        Draw();
                        Input();
                        Logic();
                        Sleep(50);
                    }
                }
                else if (difficulty == "3")
                {
                    Setup();
                    while (!gameOver)
                    {
                        Draw();
                        Input();
                        Logic();
                    }
                }
                SBoard.UpdateScore(ID, Score);
                cout << "Wanna Play Again? (y/n): ";
                cin >> PlayAgain;
                PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
                if (PlayAgain == 'y' || PlayAgain == 'Y')
                {
                    Reset();
                    continue;
                }
                else if (PlayAgain == 'n' || PlayAgain == 'N')
                {
                    break;
                }
            }
            if (gameChoice == "2")
            {
                system("cls");
                for (int i = 0; i < 12; i++)
                {
                    cout << endl;
                }
                cout << "                                       ";
                cout << "Enter Your Name: ";
                //getline(cin, Name);
                cin >> Name;
                cout << "                                       ";
                while (true)
                {
                    cout << "Enter Your Game ID: ";
                    cin >> ID;
                    if (checkInteger(ID) == true)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Enter Game ID as an integer nothing else!!\n";
                        continue;
                    }
                }
                PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
                if (!BBoard.Search(ID))
                {
                    BBoard.InsertPlayer(Name, ID, 0);
                }
                setcursor(0, 0);
                srand((unsigned)time(NULL));

                do
                {
                    system("cls");
                    gotoxy(10, 5);
                    cout << "--------------------------";
                    gotoxy(10, 6);
                    cout << "|       Flappy Bird      |";
                    gotoxy(10, 7);
                    cout << "--------------------------";
                    gotoxy(10, 9);
                    cout << "      1. Start Game";
                    gotoxy(10, 10);
                    cout << "      2. Instructions";
                    gotoxy(10, 11);
                    cout << "      3. Quit";
                    gotoxy(10, 13);
                    cout << "Select option: ";
                    char op = _getche();

                    if (op == '1')
                        play();
                    else if (op == '2')
                        instructions();
                    else if (op == '3')
                        break;

                } while (1);
                BBoard.UpdateScore(ID,score);
            }
            if (gameChoice == "3")
            {
                system("cls");
                for (int i = 0; i < 12; i++)
                {
                    cout << endl;
                }
                cout << "                                       ";
                cout << "Enter Player's 1 Name: ";
                //getline(cin, Name);
                cin >> p1;
                cout << "                                       ";
                while (true)
                {
                    cout << "Enter Player's 1 Game ID: ";
                    cin >> I1;
                    if (checkInteger(I1) == true)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Enter Game ID as an integer nothing else!!\n";
                        continue;
                    }
                }
                if (!PBoard.Search(I1))
                {
                    PBoard.InsertPlayer(p1, I1, 0);
                }
                system("cls");
                PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
                for (int i = 0; i < 12; i++)
                {
                    cout << endl;
                }
                cout << "                                       ";
                cout << "Enter Player's 2 Name: ";
                //getline(cin, Name);
                cin >> p2;
                cout << "                                       ";
                while (true)
                {
                    cout << "Enter Player's 2 Game ID: ";
                    cin >> I2;
                    if (checkInteger(I2) == true)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Enter Game ID as an integer nothing else!!\n";
                        continue;
                    }
                }
                PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
                if (!PBoard.Search(I2))
                {
                    PBoard.InsertPlayer(p2, I2, 0);
                }
                cGameManger c(40, 20);
                c.Run();
                
                PBoard.UpdateWins(I1, c.win1);
                PBoard.UpdateWins(I2, c.win2);
                
            }
            if (gameChoice == "4")
            {
                break;
            }
        }
        if (choice == "2")
        {
            system("cls");
            boardChoice = Boardchoice();
            if (boardChoice == "1")
            {
                system("cls");
                SBoard.Sort();
                SBoard.DisplaySnakeBoard();
                cout << "\n";
                cout << "                               ";
                cout << "Want to Go back to Menu?: (y/n): ";
                cin >> BackToOptions;
                PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
                if (BackToOptions == 'y' || BackToOptions == 'Y')
                {
                    Reset();
                    continue;
                }
                else if (BackToOptions == 'n' || BackToOptions == 'N')
                {
                    SBoard.InsertInSnakeFile();
                    break;
                }
            }
            else if (boardChoice == "2")
            {
                system("cls");
                BBoard.Sort();
                BBoard.DisplayBirdBoard();
                cout << "\n";
                cout << "                               ";
                cout << "Want to Go back to Menu?: (y/n): ";
                cin >> BackToOptions;
                PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
                if (BackToOptions == 'y' || BackToOptions == 'Y')
                {
                    Reset();
                    continue;
                }
                else if (BackToOptions == 'n' || BackToOptions == 'N')
                {
                    BBoard.InsertInBirdFile();
                    break;
                }
            }
            else if (boardChoice == "3")
            {
                system("cls");
                PBoard.Sort();
                PBoard.DisplayPongBoard();
                cout << "\n";
                cout << "                               ";
                cout << "Want to Go back to Menu?: (y/n): ";
                cin >> BackToOptions;
                PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
                if (BackToOptions == 'y' || BackToOptions == 'Y')
                {
                    Reset();
                    continue;
                }
                else if (BackToOptions == 'n' || BackToOptions == 'N')
                {
                    PBoard.InsertInPongFile();
                    break;
                }
            }
        }
        else if (choice == "3")
        {
            PlaySound(_T("Screen.wav"), NULL, SND_ASYNC);
            SBoard.Sort();
            SBoard.InsertInSnakeFile();
            BBoard.Sort();
            BBoard.InsertInBirdFile();
            PBoard.Sort();
            PBoard.InsertInPongFile();
            break;
        }
    }
    return 0;
}