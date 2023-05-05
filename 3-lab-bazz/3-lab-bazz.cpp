#include <iostream>
#include <vector>
#include <chrono>
#include<stack>
#include <ctime>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void next_greater_element(Node* head, int next_greater[], int n) {
    stack<int> s;
    int i = 0;
    while (head != NULL) {
        while (!s.empty() && s.top() <= head->data)
            s.pop();
        if (s.empty())
            next_greater[i] = 0;
        else
            next_greater[i] = s.top();
        s.push(head->data);
        head = head->next;
        i++;
    }
}
void reverseArray(int arr[], int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void replaceElements(int* arr, int n) {
    int* stack = new int[n];
    int top = -1;
    for (int i = 0; i < n; i++) {
        while (top >= 0 && arr[stack[top]] < arr[i]) {
            arr[stack[top]] = arr[i];
            top--;
        }
        stack[++top] = i;
    }
    while (top >= 0) {
        arr[stack[top]] = 0;
        top--;
    }
    delete[] stack;
}
void vectorfunc(vector<int>& arr, vector<int>& result, int n)
{
    for (int i = 0; i < n; i++)
    {
        int next_greater_element = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i]) {
                next_greater_element = arr[j];
                break;
            }
        }
        result[i] = next_greater_element;
    }
}
void printmatrix(int *arr,int n)
{
    for (int i = 0; i < n; i++)
    {
            cout << arr[i] << " ";
            
    }
    cout << endl;
}
void printvector(vector<int> &arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";

    }
    cout << endl;
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int reload;
    do {
        int n;
        cout << "Работу выполнил Ершов Владислав Олегович РПИа-о22 " << endl;
        cout << "Введите кол-во лементов для создания списка: \n";
        cin >> n;
        vector<int> a(n);
        int* arr = new int[n];
        int* next_greater = new int[n];
        int* b = new int[n];
        Node* head = NULL;
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 100;
            b[i] = a[i];
            arr[i] = b[i];
            push(&head, arr[i]);
        }
        printmatrix(b, n);
        printmatrix(arr, n);
        printvector(a, n);
        auto start1 = chrono::steady_clock::now();
        replaceElements(b, n);
        auto end1 = chrono::steady_clock::now();
        auto diff1 = end1 - start1;
        auto start2 = chrono::steady_clock::now();
        next_greater_element(head, next_greater, n);
        auto end2 = chrono::steady_clock::now();
        auto diff2 = end2 - start2;
        reverseArray(next_greater, n);
        auto start3 = chrono::steady_clock::now();
        vector<int> result(n);
        vectorfunc(a, result, n);
        auto end3 = chrono::steady_clock::now();
        auto diff3 = end3 - start3;
        float c = 2.0f * n * n * n;
        double mflops1 = c / (diff1.count() * 1e-6);
        double mflops2 = c / (diff2.count() * 1e-6);
        double mflops3 = c / (diff3.count() * 1e-6);
        cout << endl <<"Массив время: "<< chrono::duration <double, milli>(diff1).count() << " ms" << endl;
        cout << "MFLOPS первый способ " << mflops1 << endl;
        cout << endl <<"Список время: "<<chrono::duration <double, milli>(diff2).count() << " ms" << endl;
        cout << "MFLOPS второй способ: " << mflops2 << endl;
        cout << endl << "Стл вектор время: " <<chrono::duration <double, milli>(diff3).count() << " ms" << endl;
        cout << "MFLOPS третий способ: " << mflops3 << endl;
        cout << "\nКонечные списки: \n";
        printmatrix(b, n);
        printmatrix(next_greater, n);
        printvector(result, n);
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