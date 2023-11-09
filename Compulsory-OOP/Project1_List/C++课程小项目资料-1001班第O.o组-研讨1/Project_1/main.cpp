#include <iostream>
#include "Link.h"
#include "SoccerPlayer.h"
#include <conio.h>
using namespace std;

int main() {
    LinkList<SoccerPlayer> Playerlink;
    SoccerPlayer player;
    Node<SoccerPlayer>* p;
    CareerReport report;
    char name[80], club[80];
    int  choice, number, year, month, day, goal, total_goals;
    double salary, rate;

    while (true)
    {
        char filename[80] = "SoccerPlayers.txt";

        cout << "\nRead " <<  n  << " data " << " from " << filename << endl;
        if (Playerlink.Load(filename) == 0)
        {
            cout << "Please input a list" << endl;
            break;
        }

        cout << "1 -- Search Players" << endl;
        cout << "2 -- Add goals" << endl;
        cout << "3 -- Change club" << endl;
        cout << "0 -- Return" << endl;
        cout << "Please choose: ";
        choice = getche() - '0';

        switch (choice) {
        case 1:
            cin.getline(name, 80);
            p = Playerlink.Locate(string(player), true);
            Playerlink.CurData().Show(cout);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }
        break;
    }
    return 0;
}
