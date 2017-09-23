#include "AvlTree.h"
using namespace std;
int main()
{
    AvlTree *tree = new AvlTree();

    tree->insert(2);
    tree->insert(4);
    tree->insert(6);
    tree->insert(9);
    tree->insert(1);
    tree->insert(10);
    tree->insert(3);
    tree->insert(5);

    tree->preOrderPrint();
    cout<<endl<<tree->findMax();
    return 0;
}