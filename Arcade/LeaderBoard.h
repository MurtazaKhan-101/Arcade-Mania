#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class LeaderNode
{
private:
public:
    string Name;
    string ID;
    int Scores;
    LeaderNode *Next;

    LeaderNode()
    {
        Next = NULL;
    }
    LeaderNode(string name, string Id, int score)
    {
        Name = name;
        ID = Id;
        Scores = score;
        Next = NULL;
    }
    string GetName()
    {
        return Name;
    }
    string GetID()
    {
        return ID;
    }
    int GetScore()
    {
        return Scores;
    }
    LeaderNode *GetNext()
    {
        return Next;
    }
    void SetName(string N)
    {
        Name = N;
    }
    void SetID(string id)
    {
        ID = id;
    }
    void SetScores(int S)
    {
        Scores = S;
    }
    void SetNext(LeaderNode *N)
    {
        Next = N;
    }
};
class LeaderBoard
{
private:
    LeaderNode *Head;

public:
    LeaderBoard()
    {
        // InsertFromfile();
    }
    void InsertPlayer(string Name, string ID, int Score)
    {

        LeaderNode *New1 = new LeaderNode(Name, ID, Score);
        if (Head == NULL)
        {
            Head = New1;
            return;
        }
        LeaderNode *temp = Head;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = New1;
    }
    void DisplaySnakeBoard()
    {
        LeaderNode *Temp = Head;
        int Player = 0;
        /*for (int i = 0; i < 11; i++)
        {
            cout << endl;
        }*/
        while (Temp != NULL)
        {
            cout << "                       ";
            cout << "Player: " << ++Player << " | "
                 << "Name: " << Temp->GetName() << "     | "
                 << "ID: " << Temp->GetID() << " | "
                 << "Score: " << Temp->GetScore() << "\n";
            cout << "\n";
            Temp = Temp->Next;
        }
    }
    void DisplayBirdBoard()
    {
        LeaderNode* Temp = Head;
        int Player = 0;
        /*for (int i = 0; i < 11; i++)
        {
            cout << endl;
        }*/
        while (Temp != NULL)
        {
            cout << "                       ";
            cout << "Player: " << ++Player << " | "
                << "Name: " << Temp->GetName() << "     | "
                << "ID: " << Temp->GetID() << " | "
                << "Score: " << Temp->GetScore() << "\n";
            cout << "\n";
            Temp = Temp->Next;
        }
    }
    bool Search(string Id)
    {
        LeaderNode *Tem = Head;
        bool exist = false;
        while (Tem != NULL)
        {
            if (Tem->ID == Id)
            {
                exist = true;
                break;
            }
            Tem = Tem->GetNext();
        }
        return exist;
    }
    void UpdateScore(string ID, int Scores)
    {
        LeaderNode *temp = Head;
        while (temp->GetID() != ID)
        {
            temp = temp->GetNext();
        }
        if (temp->GetScore() < Scores)
        {
            temp->SetScores(Scores);
        }
    }
    void Sort()
    {
        LeaderNode *temp = Head;
        LeaderNode *prev;
        while (temp != NULL)
        {
            prev = temp->GetNext();
            while (prev != NULL)
            {
                if (temp->GetScore() < prev->GetScore())
                {
                    int var1 = temp->GetScore();
                    temp->SetScores(prev->GetScore());
                    prev->SetScores(var1);

                    string nvar = temp->GetName();
                    temp->SetName(prev->GetName());
                    prev->SetName(nvar);

                    string Ivar = temp->GetID();
                    temp->SetID(prev->GetID());
                    prev->SetID(Ivar);
                }
                prev = prev->GetNext();
            }
            temp = temp->GetNext();
        }
    }
    //For Snake
    void InsertInSnakeFile()
    {
        fstream File;
        File.open("Snake_Source.txt");
        LeaderNode* Temp = Head;
        while (Temp != NULL)
        {
            File << Temp->GetName() << " " << Temp->GetID() << " " << Temp->GetScore() << endl;
            Temp = Temp->GetNext();
        }
    }
    void InsertFromSnakeFile()
    {
        ifstream OpenFile;
        OpenFile.open("Snake_Source.txt");
        string name, id;
        int scores;
        while (OpenFile >> name >> id >> scores)
        {
            if (!Search(id))
            {
                InsertPlayer(name, id, scores);
            }
        }
    }
    //For Bird
    void InsertInBirdFile()
    {
        fstream File;
        File.open("Bird_Source.txt");
        LeaderNode* Temp = Head;
        while (Temp != NULL)
        {
            File << Temp->GetName() << " " << Temp->GetID() << " " << Temp->GetScore() << endl;
            Temp = Temp->GetNext();
        }
    }
    void InsertFromBirdFile()
    {
        ifstream OpenFile;
        OpenFile.open("Bird_Source.txt");
        string name, id;
        int scores;
        while (OpenFile >> name >> id >> scores)
        {
            if (!Search(id))
            {
                InsertPlayer(name, id, scores);
            }
        }
    }
};