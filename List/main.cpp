#include "MyList.h"

int main(int argc, const char * argv[])
{

    // insert code here...
    MyList list;
    list.insert(30);
    list.insert(20);
    list.insert(10);
    list.insert(5);
    list.insert(1);
    list.insert(2);
    std::cout << "初始状态" << std::endl;
    list.print();
    list.deletePos(10);
    std::cout << std::endl << "删除10" << std::endl;
    list.print();
    list.reverse();
    std::cout << std::endl << "倒置" << std::endl;
    list.print();
    return 0;
}