#include <iostream>
#include "CircList.h"
using namespace std;
int main()
{
    CircList<int> test;
    int val,n = 0;
    cin >> val;
    while (val)
    {
        test.EnQueue(val);
        cin >> val;
        n++;
    }
    cout << "ɾ��ǰ:" << endl;
    test.output();
    cout << "��һ��ɾ����:" << endl;
    test.DeQueue();
    test.output();
    cout << "�ڶ���ɾ����:" << endl;
    test.DeQueue();
    test.output();
    return 0;
}