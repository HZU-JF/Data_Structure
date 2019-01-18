//
// Created by Ī�� on 2018/11/25.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include <cassert>
using namespace std;
const int DefaultSize = 100;
enum KindOfStatus {Active, Empty, Deleted};             //Ԫ�ط��ࣨ�/��/ɾ��
template <class E, class K>
class HashTable{
public:
    HashTable(const int d, int sz = DefaultSize);
    ~HashTable(){
        delete []ht;
        delete []info;
    }
    HashTable<E, K>& operator = (const HashTable<E, K>& ht2);
    bool Search(const K k1, E& e1)const;
    bool Insert(const E& e1);
    bool Remove(const K k1, E& e1);
    void makeEmpty();
    void output();  //���
//	HashTable<E,K>& operator = (const HashTable<E,K> &ht2);
    friend ostream& operator << (ostream &out, HashTable<E,K> &ht2){
        for(int i = 0; i < ht2.TableSize; i++){
            if(ht2.info[i] == Active){
                out << "#" << i << ":\t"<< ht2.ht[i] << endl;
            }
            else if (ht2.info[i] == Empty){
                out << "#" << i << ":\tEmpty!" << endl;
            }
            else if (ht2.info[i] == Deleted){
                out << "#" << i << ":\tDeleted!" << endl;
            }
        }
        return out;
    }
    friend istream& operator >> (istream &in, HashTable<E,K> &ht2){
        E data;
        in >> data;
        while (data != 0 && ht2.CurrentSize < ht2.TableSize){
            ht2.Insert(data);
            assert(in >> data);
        }
        return in;
    }
private:
    int divitor;
    int CurrentSize, TableSize;
    E *ht;
    KindOfStatus *info;
    int FindPos(const K k1)const;
    int operator == (E& e1){
        return *this == e1;
    }
    int operator != (E& e1){
        return *this != e1;
    }
};

template <class E, class K>
HashTable<E, K>::HashTable(const int d, int sz) {
    divitor = d;
    TableSize = sz;
    CurrentSize = 0;
    ht = new E[TableSize];
    info = new KindOfStatus[TableSize];
    for (int i = 0; i < TableSize; i++){
        info[i] = Empty;
    }
}

template <class E, class K>
void HashTable<E, K>::makeEmpty() {
    for (int i = 0; i < TableSize; i++){
        info[i] = Empty;
        CurrentSize = 0;
    }
}

template <class E, class K>
HashTable<E, K>& HashTable<E, K>::operator = (const HashTable<E, K> &ht2) {
    if (this != &ht2){
        delete []ht;
        delete []info;
        ht = new E[ht2.TableSize];
        info = new KindOfStatus[ht2.TableSize];
        for (int i = 0; i < ht2.TableSize; i++){
            ht[i] = ht2.ht[i];
            info[i] = ht2.info[i];
        }
        CurrentSize = ht2.CurrentSize;
    }
    return *this;
}

template <class E, class K>
int HashTable<E, K>::FindPos(const K k1) const {
    //������һ��ɢ�б��йؼ�����k1ƥ���Ԫ�أ����سɹ����������ظ�Ԫ�ص�λ�ã����򷵻ز���㣨������㹻�Ŀռ䣩
    int i = k1 % divitor;       //�����ʼͰ��
    int j = i;          //j�Ǽ����һ��Ͱ�±�
    do{
        if (info[j] == Empty || info[j] == Active && ht[j] == k1)return j;      // �ҵ�
        j = (j + 1) % TableSize;                                    //����ѭ�������ҵ���һ����Ͱ
    }while (j != i);
    return j;                                   //תһȦ�ص���ʼ�㣬��������ʧ��
}
template <class E, class K>
bool HashTable<E, K>::Search(const K k1, E &e1) const {
    //ʹ������̽�鷨��ɢ�б�ht��ÿ��Ͱ����һ��Ԫ�أ�������k1.���k1�ڱ��д��ڣ�
    //��������true���������ò���e1�����ҵ���Ԫ�أ����k1���ڱ��У��򷵻�false��
    int i = FindPos(k1);
    if (info[i] != Active || ht[i] != k1)return false;
    e1 = ht[i];
    return true;
}

template <class E, class K>
bool HashTable<E, K>::Insert(const E &e1) {
    //��ht��������e1,�����ҵ����ٲ��룬��δ�ҵ����������������ٲ��룬����false��
    //���ҵ�λ�õı�־��Empty��Deleted�����۱��Ƿ�������x���룬����true
    K k1 = e1;              //���غ�������ȡ�ؼ���
    int i = FindPos(k1);        //��ɢ�к�������Ͱ��
    if (info[i] != Active){
        ht[i] = e1;
        info[i] = Active;
        CurrentSize++;
        return true;
    }
    if (info[i] == Active && ht[i] == e1){
        cout << "�������д�Ԫ�أ����ܲ��룡" << endl;
        return false;
    }
    cout << "�����������ܲ��룡" << endl;
    return false;
}

template <class E, class K>
bool HashTable<E, K>::Remove(const K k1, E &e1) {
    //��ht����ɾ��Ԫ��k1���������Ҳ���k1������Ȼ�ҵ�k1�������Ѿ��߼�ɾ����
    //�򷵻�false�������ڱ���ɾ��Ԫ��k1������true���������ò���e1�еõ���
    int i = FindPos(k1);
    if (info[i] == Active && ht[i] == k1){
        e1 = ht[i];
        info[i] = Deleted;
        CurrentSize--;
        return true;
    }
    else return false;
}

template <typename E, typename K>
void HashTable<E,K>::output(){
    for(int i = 0; i<TableSize; i++)	{
        if(info[i] == Active){
            cout << "#" << i << ":\t"<< ht[i] << endl;
        }
        else if (info[i] == Empty){
            cout << "#" << i << ":\tEmpty!" << endl;
        }
        else if (info[i] == Deleted){
            cout << "#" << i << ":\tDeleted!" << endl;
        }
    }
}

#endif //HASHTABLE_HASHTABLE_H
