//
// Created by Ī�� on 2018/10/6.
//

#ifndef INC_3_15_SINGLELIST_H
#define INC_3_15_SINGLELIST_H
#ifndef SINGLELIST_SINGLELIST_H
#define SINGLELIST_SINGLELIST_H

#include <iostream>
using namespace std;
template <class T>
struct LinkNode
{
    T data;
    LinkNode<T>* link;
    LinkNode(LinkNode<T>* ptr = NULL){link = ptr;}
    LinkNode(const T& item, LinkNode<T>* ptr = NULL)
    {
        data = item;
        link = ptr;
    }
};
template <class T>
class List
{
protected:
    LinkNode<T>* first;
public:
    List(){first = new LinkNode<T>; }
    List(const T& x){first = new LinkNode<T>(x);}
    List(List<T>& L)
    {
        T value;
        LinkNode<T>* srcptr = L.getHead();
        LinkNode<T>* desptr = first = new LinkNode<T>;
        while (srcptr -> link != NULL)
        {
            value = srcptr -> link -> data;
            desptr -> link = new LinkNode<T>(value);
            srcptr = srcptr -> link;
			desptr = desptr -> link;
        }
        desptr -> link = NULL;
    }
    ~List(){makeEmpty();}
    void makeEmpty()    //��������Ϊ��
    {
        LinkNode<T>* q;
        while (first -> link != NULL)
        {
            q = first -> link;
            first -> link = q -> link;
            delete q;
        }
    }
    int Length()const       //���㸽��ͷ���ĵ�����ĳ��ȣ����Ȳ�����ͷ���
    {
        LinkNode<T>* p = first;
        int count = 0;
        while (p != NULL)
        {
            p = p -> link;
            count++;
        }
        return count;
    }
    LinkNode<T>* getHead()const{return first;}
    LinkNode<T>* Search(T x)
    {
        LinkNode<T>* current = first -> link;
        while (current != NULL)
        {
            if(current -> data == x)break;
            else current = current -> link;
        }
        return current;
    }
    LinkNode<T>* Locate(int i)      //��λ����
    {
        if (i < 0)return NULL;
        LinkNode<T>* current = first;
        int k = 0;
        while (current != NULL && k < i)
        {
            current = current -> link;
            k++;
        }
        return current;
    }
    bool getData(int i, T& x)const      //ȡ�������е�i��Ԫ�ص�ֵ
    {
        if (i <= 0)return NULL;
        LinkNode<T>* current = Locate(i);
        if (current == NULL) return false;
        else
        {
            x = current -> data;
            return true;
        }
    }
    bool setData(int i, T& x)       //�����е�i��Ԫ�ظ�ֵx
    {
        if (i <= 0)return NULL;
        LinkNode<T>* current = Locate(i);
        if (current == NULL) return false;
        else {current -> data = x;return true;}
    }
    bool Insert(int i, T& x)    //����Ԫ��x�����������е�i������
    {
        LinkNode<T>* current = Locate(i);
        if(current == NULL) return false;
        LinkNode<T>* newNode = new LinkNode<T>(x);
        if (newNode == NULL)
        {
            cerr << "�洢�������" << endl;
            exit(1);
        }
        newNode -> link = current -> link;
        current -> link = newNode;
        return true;
    }
    bool Remove(int i, T& x)
    {
        LinkNode<T>* current = Locate(i - 1);
        if(current == NULL || current -> link == NULL)return false;
        LinkNode<T>* del = current -> link;
        current -> link = del -> link;
        x = del -> data;
        delete del;
        return true;
    }
    bool IsEmpty()const
    {
        return first -> link == NULL ? true : false;
    }
    bool IsFull()const {return false;}
    /*void Sort()
    {

    }*/
    void inputFront(T endTag)       //  ǰ�巨��������ջ
    {
        LinkNode<T>* newNode;
        T val;
        makeEmpty();
        cout << "��������ֵ������" << endTag << "ֹͣ";
        cin >> val;
        while (val != endTag)
        {
            newNode = new LinkNode<T>(val);
            if (newNode == NULL)
            {
                cerr << "����������" << endl;
                exit(1);
            }
            newNode -> link = first -> link;
            first -> link = newNode;
            cin >> val;
        }
    }
    void inputRear(T endTag)        //  ��巨������,��
    {
        LinkNode<T>* newNode, *last;
        T val;
        makeEmpty();
        cin >> val;
        last = first;
        while(val != endTag)
        {
            newNode = new LinkNode<T>(val);
            if(newNode == NULL)
            {
                cerr << "����������" << endl;
                exit(1);
            }
            last -> link = newNode;
            last = newNode;
            cin >> val;
        }
        last -> link = NULL;
    }
    void output()
    {
        LinkNode<T>* current = first -> link;
        int count = 1;
        while (current != NULL)
        {
            cout << count++ << " : ";
            cout << current -> data << endl;
            current = current -> link;
        }
    }
    List<T>& operator=(List<T>& L)
    {
        T value;
        LinkNode<T>* srcptr = L.getHead();
        LinkNode<T>* desptr = first = new LinkNode<T>;
        while (srcptr -> link != NULL)
        {
            value = srcptr -> link -> data;
            desptr -> link = new LinkNode<T>(value);
            desptr = desptr -> link;
            srcptr = srcptr -> link;
        }
        desptr -> link = NULL;
        return *this;
    }
    //LinkNode<T>* max()
    void max()
    {
        LinkNode<T>* current = first -> link;
        LinkNode<T>* maxPtr = current;
        T max = current -> data;
        while(current -> link != NULL)
        {
            current = current -> link;
            if(max < current -> data)
            {
                max = current -> data;maxPtr = current;
            }
        }
        if(current -> data > max){ max = current -> data;maxPtr = current;}
        cout << "The max is :" << max;
        //return maxPtr;
    }

};
#endif //SINGLELIST_SINGLELIST_H
#endif //INC_3_15_SINGLELIST_H
