#include <iostream>
#include "sparseMatrix_cal.h"
using namespace std;
int main() {
    int i;
    cout << "**************************" << endl;
    cout << "*                        *" << endl;
    cout << "*    -ϡ�����������-    *" << endl;
    cout << "*                        *" << endl;
    cout << "*    1-����ӷ�          *" << endl;
    cout << "*    2-�������          *" << endl;
    cout << "*    3-����˷�          *" << endl;
    cout << "*    0-�˳�              *" << endl;
    cout << "*                        *" << endl;
    cout << "**************************" << endl;
    cout << "������0,1,2,3ѡ����е����㣺";
    cin >> i;
    while (i) {
        switch (i) {
            case 1:{
                cout << "����ӷ����㣺" << endl << "======================" << endl;
                Count(i);
                break;
            }
            case 2:{
                cout << "����������㣺" << endl << "======================" << endl;
                Count(i);
                break;
            }
            case 3:{
                cout << "����˷����㣺" << endl << "======================" << endl;
                multiplication();
                break;
            }
        }
        cout << "������0,1,2,3ѡ����е����㣺";
        cin >> i;
    }
    cout << "�������رգ�ллʹ��" << endl << "======================" << endl;
    cout << "��������ӻس���������: " << endl << "======================" << endl;
    char c;
    cin >> c;
    return 0;
}