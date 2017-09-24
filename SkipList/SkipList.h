//
// Created by XB on 2017/9/24.
//

#ifndef SKIPLIST_SKIPLIST_H
#define SKIPLIST_SKIPLIST_H

#include <cstdlib>
#include <iostream>

typedef struct SkipListNode {
    int key;
    int data;
    int level; //靠level+1决定next_nodes大小
    SkipListNode **next_nodes; //用这个维持内部结构
} SkipListNode;

class SkipList {
public:
    explicit SkipList(int max_level);
    ~SkipList();
    void insertNode(int key, int data);
    //void deleteNode(int key);
    int getData(int key);
    void displayList();
private:
    int MAX_LEVEL;
    int RandomLevel();
    SkipListNode *head;
    SkipListNode *tail;
};

#endif //SKIPLIST_SKIPLIST_H
