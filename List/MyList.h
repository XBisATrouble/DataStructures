//
// Created by XB on 2017/9/22.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H


#include <iostream>

class MyList {
public:
    MyList();
    virtual ~MyList();
    void create_List();                                  //创建头结点
    void insert(const int& d);                           //插入函数
    void insertPos(const int& d,const int& position);    //在指定位置插入
    void deletePos(const int& d);                        //删除指定数据的节点
    void reverse();                                      //反转链表函数
    void print();                                        //打印
private:
    struct Node{
        int data;
        Node * next;
        Node(const int& d):data(d),next(nullptr){} //空头指针
    };

    Node * head;//头节点
    //清理链表函数
    void clear(){
        Node * p = head;
        while(p){
            Node * q = p->next;
            delete p;
            p = q;
        }
    }
    //查找数据d的上一个节点位置的函数
    //为了方便后面删除操作
    Node* find(const int& d){
        Node * p = head;
        for(;p;p=p->next){
            if(p->next->data==d)
                break;
        }
        return p;
    }
};


#endif //LIST_LIST_H
