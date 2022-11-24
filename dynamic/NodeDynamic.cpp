#include "NodeDynamic.h"
#include "TreeDynamic.h"

//
// Created by 48791 on 18.11.2022.
//

NodeDynamic::NodeDynamic() {
    value = 0;
    parent = NULL;
    root = this;
}

NodeDynamic::~NodeDynamic() {
    for (int i = 0 ; i < getChildrenNumber() ; i++)
    {
        delete getChild(i);
    }
    children.clear();

}

void NodeDynamic::setValue(int newValue) {
    value = newValue;
}

int NodeDynamic::getChildrenNumber() {
    return(children.size)();
}

int NodeDynamic::getMyIndex() {
    int index = 0;
    if (root!= this)
    {
        for (int i = 0 ; i < parent->getChildrenNumber() ; i++)
        {
            if (parent->children.at(i) == this) index = i;
        }
    }
    return index;
}

void NodeDynamic::setRoot(NodeDynamic *newRoot) {
    root = newRoot;
    for (int i = 0 ; i < getChildrenNumber() ; i++)
    {
        children.at(i)->setRoot(newRoot);
    }
}

void NodeDynamic::addNewChild() {
    addNewChild(new NodeDynamic());
}

void NodeDynamic::addNewChild(NodeDynamic *newChild) {
    newChild->parent = this;
    newChild->setRoot(root);
    children.push_back(newChild);
}

void NodeDynamic::removeChild(int index){
    children.erase(children.begin()+index);
}

void NodeDynamic::detachFromParent() {
    if (this!=root)
    {
        parent->removeChild(getMyIndex());
    }
}

NodeDynamic *NodeDynamic::getChild(int childIndex) {
    if (childIndex >= 0 && childIndex < getChildrenNumber())
    {
        return children[childIndex];
    }
    else return nullptr;
}

void NodeDynamic::print() {
    cout << " " << value;
}

void NodeDynamic::printAllBelow() {
    print();
    for (int i = 0 ; i < getChildrenNumber() ; i++)
    {
        getChild(i)->printAllBelow();
    }
}

bool NodeDynamic::isInTheSameTree(NodeDynamic *otherNode) {
    return root == otherNode->root;
}

#include "NodeDynamic.h"
