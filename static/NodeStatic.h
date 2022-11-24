//
// Created by 48791 on 17.11.2022.
//

#ifndef UNTITLED1_NODESTATIC_H
#define UNTITLED1_NODESTATIC_H

#include <iostream>
#include <vector>

using namespace std;

class NodeStatic {
public:
    NodeStatic();
    ~NodeStatic();
    void setValue(int newValue);
    int getChildrenNumber();
    void addNewChild();
    void addNewChild(NodeStatic *newChild);
    void detachFromParent();
    NodeStatic *getChild(int childIndex);
    int getMyIndex();
    void printNode();
    void printAllBelow();
    void printAllAbove();
    bool isInTheSameTree(NodeStatic *otherNode);
    void removeChild(int index);

    bool isRoot();
    NodeStatic *getParent() const;

    bool operator==(const NodeStatic &rhs) const;

    bool operator!=(const NodeStatic &rhs) const;

private:
    NodeStatic *parent;
    vector<NodeStatic> children;
    NodeStatic *root;
    int value;
    void setRoot(NodeStatic *newRoot);
};


#endif //UNTITLED1_NODESTATIC_H
