#include "SkipList.h"

SkipList::SkipList(int max_level) {
    MAX_LEVEL = max_level>0?max_level:1;
    head = new SkipListNode;
    tail = new SkipListNode;//head的后继节点

    head->next_nodes = new SkipListNode *[MAX_LEVEL]; //生成一个最高的Node
    for (int i = 0; i < MAX_LEVEL; ++i) {
        head->next_nodes[i]=tail;
    }
}

SkipList::~SkipList() {
    SkipListNode *curr = nullptr;
    while(head->next_nodes[0] != tail) {
        curr = head->next_nodes[0];
        head->next_nodes[0] = curr->next_nodes[0];
        delete curr->next_nodes;
        delete curr;
    }
    delete head->next_nodes;
    delete head;
    delete tail;
}

int SkipList::RandomLevel() {
    int level=1;
    while (random()%2)
        level++;
    level=(MAX_LEVEL>level)? level:MAX_LEVEL;
    return level;
}

void SkipList::insertNode(int key, int data) {
    SkipListNode *update[MAX_LEVEL];
    SkipListNode *curr = head;

    // 寻找每一层上待插入节点之前的节点
    for(int i = MAX_LEVEL - 1; i >= 0; --i) {
        if(curr->next_nodes[i] == tail || curr->next_nodes[i]->key > key)
            update[i] = curr;
        else {
            while(curr->next_nodes[i] != tail && curr->next_nodes[i]->key < key)
                curr = curr->next_nodes[i];
            if(curr->next_nodes[i] != tail && curr->next_nodes[i]->key == key) {
                curr->next_nodes[i]->data = data;
                return;
            }
            update[i] = curr;
        }
    }

    // 生成待插入节点
    int level = RandomLevel();
    auto temp = new SkipListNode;
    temp->key = key;
    temp->data = data;
    temp->level = level;
    temp->next_nodes = new SkipListNode *[level + 1];

    // 在每层上的链表中插入节点
    for(int i = 0; i <= level; ++i) {
        temp->next_nodes[i] = update[i]->next_nodes[i];
        update[i]->next_nodes[i] = temp;
    }
}

int SkipList::getData(int key) {
    SkipListNode* curr =  head;
    for(int i = MAX_LEVEL - 1; i >= 0; --i) {
        if(curr->next_nodes[i] == tail || curr->next_nodes[i]->key > key)
            continue;
        else {
            while(curr->next_nodes[i] != tail && curr->next_nodes[i]->key < key)
                curr = curr->next_nodes[i];
            if(curr->next_nodes[i] != tail && curr->next_nodes[i]->key == key)
                return curr->next_nodes[i]->data;
        }
    }
    return 0;
}

void SkipList::displayList() {
    SkipListNode *p = head;
    while (p->next_nodes[0] != tail)
    {
        std::cout << "key:" << p->next_nodes[0]->key <<",value:"<< p->next_nodes[0]->data<<std::endl;
        p = p->next_nodes[0];
    }
}