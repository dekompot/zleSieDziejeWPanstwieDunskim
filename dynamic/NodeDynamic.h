//
// Created by 48791 on 18.11.2022.
//

#ifndef UNTITLED1_NODEDYNAMIC_H
#define UNTITLED1_NODEDYNAMIC_H
#include <iostream>
#include <vector>

using namespace std;

class NodeDynamic {
public:
    NodeDynamic();
    ~NodeDynamic();
    void setValue(int newValue);
    int getChildrenNumber();
    int getMyIndex();
    void addNewChild();
    void addNewChild(NodeDynamic *newChild);
    void detachFromParent();
    void setRoot(NodeDynamic *newRoot);
    NodeDynamic *getChild(int childIndex);
    void print();
    void printAllBelow();
    bool isInTheSameTree(NodeDynamic *otherNode);
    void removeChild(int index);
    bool isRoot();
    int getHeight();

    bool operator==(const NodeDynamic &rhs) const;

    bool operator!=(const NodeDynamic &rhs) const;

private:
    vector<NodeDynamic *> children;
    NodeDynamic *parent;

    NodeDynamic *root;

    int value;
};


#endif //UNTITLED1_NODEDYNAMIC_H
