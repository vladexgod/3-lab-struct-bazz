#include <iostream>
#include <vector>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    int reload;
    do {
        cout << "Работу выполнил Ершов Владислав Олегович РПИа-о22 " << endl;
        int n, switch_on;
        cout << "Введите кол-во лементов для создания списка: \n";
        cin >> n;
        do
        {
            cout << "Каким способом заполнения хотите воспользоваться? 1-Самостоятельное заполнение 2-Рандом\n";
            cin >> switch_on;
            if (switch_on != 1 && switch_on != 2)
            {
                cout << "Введено неверное значение повтор!\n";
            }
        } while (switch_on != 1 && switch_on != 2);
        vector<int> a(n);
        switch (switch_on)
        {
        case 1:
            cout << "Введите элементы таблицы: ";
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                a[i] = rand() % 100;
            }
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            break;
        }
        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            int next_greater_element = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] > a[i]) {
                    next_greater_element = a[j];
                    break;
                }
            }
            result[i] = next_greater_element;
        }
        cout << "\nКонечная матрица: \n";
        for (int i = 0; i < n; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;

        do
        {
            cout << "Желаете повторить программу? 1-да 2-нет\n";
            cin >> reload;
            if (reload != 1 && reload != 2)
            {
                cout << "Введено неверное значение повтор!\n";
            }
        } while (reload != 1 && reload != 2);
    } while (reload == 1);
    return 0;
}