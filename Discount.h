
#include <iostream>

using std::cout;
using std::endl;

class Discount
{
private:
    uint32_t dis;
public:
    double sum;
    double res;

    Discount()
    {
        this->sum = 0;
        this->res = 0;
    }

    Discount(double sum) : Discount()
    {
        this->sum = sum;
    }

    double Purchase(uint32_t GetRang)
    {
        if (GetRang == 1)
        {
            dis = 10;
            res = sum * 0.10 + sum;
        }
        else if (GetRang == 2)
        {
            dis = 20;
            res = sum * 0.20 + sum;
        }
        else if (GetRang == 3)
        {
            dis = 30;
            res = sum * 0.30 + sum;
        }
        else
        {
            dis = 0;
            res = sum;
        }
        cout << "Сумма со скидкой " << dis << "%: " << res << "грн." << endl;
        return res;
    }
};