//
// Created by Ī�� on 2018/12/27.
//

#ifndef SPARSEMATRIX_CAL_SPARSEMATRIX_CAL_H
#define SPARSEMATRIX_CAL_SPARSEMATRIX_CAL_H
#include <iostream>
#include <iomanip>
using namespace std;
#define MAXSIZE 20
struct Triple{
    int row, col, value;
};
struct SparseMatrix{
    int Row, Col, Terms;
    Triple data[MAXSIZE];
};
void input(SparseMatrix &M){
    cout << "����������������";
    cin >> M.Row;
    cout << "����������������";
    cin >> M.Col;
    cout << "������Ϊ��������Ԫ�鷽ʽ�������Ԫ�أ�'0,0,0'��������:������������������������1���Ҳ��ܳ��������������������" << endl;
    int i, j, k;
    for (M.Terms = 0; ; M.Terms++){
        cout << M.Terms+1 << " : ";
        cin >> i >> j >> k;
        if (i == 0 && j == 0 && k == 0)break;
        if (i > M.Row || j > M.Col || i == 0 || j == 0){
            cout << "����������Ч������������" << endl;
            M.Terms--;
            continue;
        }
        M.data[M.Terms].row = i;
        M.data[M.Terms].col = j;
        M.data[M.Terms].value = k;
    }
}
void Count(int x){
    SparseMatrix M1, M2;
    cout << "�������һ������:" << endl << "======================" << endl;
    input(M1);
    cout << "������ڶ�������:" << endl << "======================" << endl;
    input(M2);
    if (M1.Row != M2.Row || M1.Col != M2.Col){
        cout << "�����������޷����мӼ�����" << endl;
        return;
    }
    if (x == 1) cout << "����ӷ��Ľ��Ϊ:" << endl << "======================" << endl;
    else cout << "��������Ľ��Ϊ:" << endl << "======================" << endl;

    int p = 0,q = 0;
    for (int i = 1; i <= M1.Row; i++){
        for (int j = 1; j <= M1.Col; j++){
            p = 0; q = 0;
            for (int k = 0; k < M1.Terms; k++){
                if ((M1.data[k].row == i)&&(M1.data[k].col == j)){
                    p = M1.data[k].value;break;
                }
            }
            for (int k = 0; k < M2.Terms; k++){
                if ((M2.data[k].row == i)&&(M2.data[k].col == j)){
                    q = M2.data[k].value;break;
                }
            }
            if (x == 1)cout <<setiosflags(ios::right) << setw(3) << p + q << "  ";
            else cout <<setiosflags(ios::right) << setw(3) << p - q << "  ";
        }
        cout << endl;
    }
}
int find(SparseMatrix M, int i, int j){
    for (int t = 0; t < M.Terms; t++){
        if ((M.data[t].row == i)&&(M.data[t].col == j))
            return M.data[t].value;
    }
    return 0;
}
void multiplication()
{
    SparseMatrix M1, M2;
    cout << "�������һ������:" << endl << "======================" << endl;
    input(M1);
    cout << "������ڶ�������:" << endl << "======================" << endl;
    input(M2);
    cout << "����˷��Ľ��Ϊ:" << endl << "======================" << endl;
    if (M1.Col != M2.Row){
        cout << "�����������޷����г˳�����" << endl;
        return;
    }
    int p = 0, q = 0, sum = 0;
    for (int i = 1; i <= M1.Row; i++){
        for (int j = 1; j <= M2.Col; j++){
            sum = 0;
            for (int k = 1; k <= M1.Col; k++){
                p = find(M1, i, k);
                q = find(M2, k, j);
                sum += p * q;
            }
            cout <<setiosflags(ios::right) << setw(3) << sum << "  ";
        }
        cout << endl;
    }

}
#endif //SPARSEMATRIX_CAL_SPARSEMATRIX_CAL_H