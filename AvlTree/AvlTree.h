//
// Created by XB on 2017/9/23.
//

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include <iostream>

class AvlTree{
public:
    AvlTree(){ root = nullptr; }
    ~AvlTree(){makeEmpty();};

    void makeEmpty();//清空该树
    bool isEmpty() const;//判断该树是否为空
    void preOrderPrint();//从小到大输出该AVL平衡树
    void biggerOreOrderPrint();//从大到小输出该AVL平衡树
    void insert(const int & x);//插入值为x的结点
    int findMin() const;//找到最小值
    int findMax() const;//找到最大值

private:
    struct AvlNode{
        int element;
        AvlNode * left;
        AvlNode * right;
        int height;
        AvlNode(const int & e, AvlNode * lt, AvlNode * rt, int h = 0):element(e), left(lt), right(rt), height(h){}
    };
    AvlNode * root;

private:
    void makeEmpty(AvlNode * t);
    void preOrderPrint(AvlNode * t);
    void biggerOreOrderPrint(AvlNode * t);
    int height(AvlNode * t) const;//获得当前结点t的高度
    void insert(const int & x, AvlNode * & t);//在t处，插入值为x的结点
    void rotateWithLeftChild(AvlNode * & k2);//单旋转，左左插入的情况
    void rotateWithRightChild(AvlNode * & k1);//单旋转，右右插入的情况
    void doubleWithLeftChild(AvlNode * & k3);//双旋转，左右插入的情况
    void doubleWithRightChild(AvlNode * & k1);//双旋转，右左插入的情况
    int findMin(AvlNode * t) const;//找到最小值
    int findMax(AvlNode * t) const;//找到最大值
    int max (int a,int b){return a>=b?a:b;}
};


#endif //AVLTREE_AVLTREE_H
