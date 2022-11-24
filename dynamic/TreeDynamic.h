//
// Created by 48791 on 18.11.2022.
//

#ifndef UNTITLED1_TREEDYNAMIC_H
#define UNTITLED1_TREEDYNAMIC_H


#include "NodeDynamic.h"

class TreeDynamic {
public:
    TreeDynamic();
    ~TreeDynamic();
    NodeDynamic *getRoot();
    void setRoot(NodeDynamic *newRoot);
    void print();
    bool insertSubtree(NodeDynamic *newParent, NodeDynamic *newChild);
    int getHeight();
private:
    NodeDynamic *root;
};


#endif //UNTITLED1_TREEDYNAMIC_H
