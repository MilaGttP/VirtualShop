
#include <iostream>

class Team
{
public:
    vector<Worker> workers;
    size_t length = 0;
    int num = 0;

    void AddWorker(Worker worker)
    {
        this->workers.push_back(worker);
    }

    void Show()
    {
        for (auto& item : workers)
        {
            cout << item << endl;
        }
    }

    void SortByRang() {
        sort(workers.begin(), workers.end(), [](Worker& w1, Worker& w2) { return w1.GetRang() > w2.GetRang(); });
        system("pause");
    }

    void Find(string name)
    {
        find(workers.begin(), workers.end(), [](Worker w1, Worker w2) { return w1.GetName() == w2.GetName(); });
        system("pause");
    }

    void DeleteWorker(string name)
    {
        auto iter = std::find_if(workers.begin(), workers.end(),
            [=](Worker& s) { return s.GetName() == name; });
        if (iter != workers.end())
            workers.erase(iter);
        else
            cout << "Object not found!.\n";
    }
};
