#include "SkipList.h"

int main()
{
    SkipList *t = new SkipList(10);
    t->insertNode(1,10);
    t->insertNode(2,3);
    t->insertNode(3,14);
    t->insertNode(10,7);
    t->insertNode(5,4);
    t->insertNode(6,2);
    t->displayList();
    std::cout<<t->getData(3);
}