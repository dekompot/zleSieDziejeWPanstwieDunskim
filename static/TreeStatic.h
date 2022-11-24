//
// Created by 48791 on 18.11.2022.
//

#ifndef UNTITLED1_TREESTATIC_H
#define UNTITLED1_TREESTATIC_H
#include "NodeStatic.h"

class TreeStatic
{
public:
    TreeStatic();
    TreeStatic(NodeStatic newRoot);
    ~TreeStatic();
    NodeStatic *getRoot();
    void setRoot(NodeStatic newRoot);
    void print();
    bool insertSubtree(NodeStatic *newParent, NodeStatic *newChild);
private:
    NodeStatic root;
};


#endif //UNTITLED1_TREESTATIC_H
