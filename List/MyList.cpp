//
// Created by XB on 2017/9/22.
//

#include "MyList.h"

MyList::MyList()
{
    create_List();
}

MyList::~MyList()
{
    clear();
}

void MyList::create_List()
{
    head = new Node(0);
}

void MyList::insert(const int &d)
{
    Node *tmpCell = new Node(d);
    tmpCell->next=head->next;
    head->next=tmpCell;
}

void MyList::insertPos(const int &d, const int &position)
{
    Node *tmpCell = new Node(d);
    Node *flag = find(position);
    tmpCell->next = flag->next;
    flag->next=tmpCell;
}

void MyList::deletePos(const int &d)
{
    Node *p=find(d); //找到d之前的那个节点
    Node *q=p->next;
    p->next = p->next->next;
    delete q;
}

void MyList::print()
{
    Node *p = head->next;
    while (p){
        std::cout<<p->data<<"->";
        p = p->next;
    }
}

void MyList::reverse()
{
    Node *tmpCell = new Node(0);
    Node *p = head->next;
    head->next = nullptr;

    while (p)
    {
        tmpCell = p->next;
        p->next = head->next;
        head->next = p;
        p = tmpCell;
    }
}