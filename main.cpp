#include "VirtualShop.h"


int main()
{
    Team team;

    while (true)
    {
        system("cls");
        cout << "MENU" << endl << endl;
        cout << "1 - Add worker" << endl;
        cout << "2 - Show workers" << endl;
        cout << "3 - Sort by rang" << endl;
        cout << "4 - Find" << endl;
        cout << "5 - Delete" << endl;
        cout << "6 - Exit" << endl << endl;
        cout << "Enter: ";
        int menu;
        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            system("cls");
            Worker worker;
            cin >> worker;
            team.AddWorker(worker);
        }break;

        case 2:
        {
            team.Show();
        }break;

        case 3:
        {
            string name;
            cout << "Enter>";
            cin >> name;
            team.DeleteWorker();
        }break;
        }

        system("pause");
    }

    return 0;
}