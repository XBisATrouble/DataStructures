//
// Created by XB on 2017/9/23.
//

#include "AvlTree.h"

int AvlTree::height(AvlTree::AvlNode *p) const {
    return p == nullptr?-1:p->height;
}

void AvlTree::makeEmpty() {
    makeEmpty(root);
}

void AvlTree::makeEmpty(AvlTree::AvlNode *t) {
    if (t!= nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
}

bool AvlTree::isEmpty() const {
    return root== nullptr;
}

void AvlTree::preOrderPrint() {
    preOrderPrint(root);
}

void AvlTree::preOrderPrint(AvlTree::AvlNode *t) {
    if (t== nullptr) return;
    preOrderPrint(t->left);
    std::cout<<t->element<<",";
    preOrderPrint(t->right);
}

void AvlTree::biggerOreOrderPrint() {
    biggerOreOrderPrint(root);
}

void AvlTree::biggerOreOrderPrint(AvlTree::AvlNode *t) {
    if (t== nullptr) return;
    biggerOreOrderPrint(t->right);
    std::cout<<t->element<<",";
    biggerOreOrderPrint(t->left);
}

void AvlTree::insert(const int &x) {
    insert(x,root);
}

void AvlTree::insert(const int &x, AvlTree::AvlNode *&t) {
    if (t== nullptr)
        t = new AvlNode(x, nullptr, nullptr);
    else if (x<t->element)
    {
        insert(x,t->left);
        if (height(t->left) - height(t->right) ==2)
        {
            if (x<t->left->element)
                rotateWithLeftChild(t);
            else
                doubleWithLeftChild(t);
        }
    }
    else if (x>t->element)
    {
        insert(x,t->right);
        if (height(t->right) - height(t->left) ==2)
        {
            if (x>t->right->element)
                rotateWithRightChild(t);
            else
                doubleWithRightChild(t);
        }
    }
    t->height = max(height(t->left),height(t->right))+1;
}

//左旋转
void AvlTree::rotateWithLeftChild(AvlTree::AvlNode *&k2) {
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left),height(k2->right)) + 1;
    k1->height = max(height(k1->left),k2->height) + 1;

    k2=k1;
}

void AvlTree::rotateWithRightChild(AvlTree::AvlNode *&k1) {
    AvlNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(height(k1->left),height(k1->right)) + 1;
    k2->height = max(height(k2->right),k1->height) + 1;

    k1=k2;
}

//右左，根据第二次旋转定为左还是右
void AvlTree::doubleWithLeftChild(AvlTree::AvlNode *&k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void AvlTree::doubleWithRightChild(AvlTree::AvlNode *&k1) {
    rotateWithLeftChild(k1->left);
    rotateWithLeftChild(k1);
}

int AvlTree::findMin() const {
    if (!isEmpty())
        return findMin(root);
}

int AvlTree::findMax() const {
    if (!isEmpty())
        return findMax(root);
}

int AvlTree::findMin(AvlTree::AvlNode *t) const {
    if (t->left == nullptr)
        return t->element;
    else
        return findMin(t->left);
}

int AvlTree::findMax(AvlTree::AvlNode *t) const {
    if (t->right == nullptr)
        return t->element;
    else
        return findMax(t->right);
}