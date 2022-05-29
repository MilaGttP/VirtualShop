
#include "VirtualShop.h"
#include "Discount.h"
#include "Team.h"

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
            Worker * worker = new Worker;
            cin >> *worker;
            team.AddWorker(*worker);
        }break;

        case 2:
        {
            team.Show();
        }break;

        case 3:
        {
            team.SortByRang();
            team.Show();
        }break;

        case 4:
        {
            string name;
            cout << "Enter>";
            cin >> name;
            team.Find(name);
        }break;

        case 5:
        {
            string name;
            cout << "Enter>";
            cin >> name;
            team.DeleteWorker(name);
        }break;
        }

        system("pause");
    }
    
    
    return 0;
}