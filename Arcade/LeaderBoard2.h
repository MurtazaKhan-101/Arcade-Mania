#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class LeaderNode2P
{
private:
public:
    string Name;
    string ID;
    int Wins;
    LeaderNode2P *Next;

    LeaderNode2P()
    {
        Next = NULL;
    }
    LeaderNode2P(string name, string Id, int score)
    {
        Name = name;
        ID = Id;
        Wins = score;
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
    int GetWins()
    {
        return Wins;
    }
    LeaderNode2P *GetNext()
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
    void SetWins(int S)
    {
        Wins = S;
    }
    void SetNext(LeaderNode2P *N)
    {
        Next = N;
    }
};
class LeaderBoard2P
{
private:
    LeaderNode2P *Head;

public:
    LeaderBoard2P()
    {
        // InsertFromfile();
    }
    void InsertPlayer(string Name, string ID, int Score)
    {

        LeaderNode2P *New1 = new LeaderNode2P(Name, ID, Score);
        if (Head == NULL)
        {
            Head = New1;
            return;
        }
        LeaderNode2P *temp = Head;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = New1;
    }
    void DisplayPongBoard()
    {
        LeaderNode2P *Temp = Head;
        int Player = 0;
        /*for (int i = 0; i < 11; i++)
        {
            cout << endl;
        }*/
        while (Temp != NULL)
        {
            cout << "                       ";
            cout << "Player: " << ++Player << " | "
                 << "Name: " << Temp->GetName() << " | "
                 << "ID: " << Temp->GetID() << " | "
                 << "Wins: " << Temp->GetWins() << "\n";
            cout << "\n";
            Temp = Temp->Next;
        }
    }
    bool Search(string Id)
    {
        LeaderNode2P *Tem = Head;
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
    void UpdateWins(string ID, int Wins)
    {
        LeaderNode2P *temp = Head;
        while (temp->GetID() != ID)
        {
            temp = temp->GetNext();
        }
        temp->SetWins(temp->GetWins()+Wins);
    }
    void Sort()
    {
        LeaderNode2P *temp = Head;
        LeaderNode2P *prev;
        while (temp != NULL)
        {
            prev = temp->GetNext();
            while (prev != NULL)
            {
                if (temp->GetWins() < prev->GetWins())
                {
                    int var1 = temp->GetWins();
                    temp->SetWins(prev->GetWins());
                    prev->SetWins(var1);

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
    // For Pong
    void InsertInPongFile()
    {
        fstream File;
        File.open("Pong_Source.txt");
        LeaderNode2P *Temp = Head;
        while (Temp != NULL)
        {
            File << Temp->GetName() << " " << Temp->GetID() << " " << Temp->GetWins() << endl;
            Temp = Temp->GetNext();
        }
    }
    void InsertFromPongFile()
    {
        ifstream OpenFile;
        OpenFile.open("Pong_Source.txt");
        string name, id;
        int Wins;
        while (OpenFile >> name >> id >> Wins)
        {
            if (!Search(id))
            {
                InsertPlayer(name, id, Wins);
            }
        }
    }
};