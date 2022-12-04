//
// Created by 48791 on 18.11.2022.
//

#ifndef UNTITLED1_TREEDYNAMIC_H
#define UNTITLED1_TREEDYNAMIC_H
#include <iostream>
#include <vector>

using namespace std;

template <typename T> class NodeDynamic {
public:
    NodeDynamic() {
        //value = NULL;
        parent = NULL;
        root = this;
    }

    ~NodeDynamic() {
        for (int i = 0 ; i < getChildrenNumber() ; i++)
        {
            delete getChild(i);
        }
        children.clear();

    }
    void setValue(T newValue);
    int getChildrenNumber();
    int getMyIndex();
    void addNewChild();
    void addNewChild(NodeDynamic<T> *newChild);
    void detachFromParent();
    void setRoot(NodeDynamic<T> *newRoot);
    NodeDynamic<T> *getChild(int childIndex);
    void print();
    void printAllBelow();
    bool isInTheSameTree(NodeDynamic<T> *otherNode);
    void removeChild(int index);
    bool isRoot();
    int count(T searchedValue);

private:
    vector<NodeDynamic<T> *> children;
    NodeDynamic<T> *parent;

    NodeDynamic<T> *root;

    T value;
};

template <typename T> class TreeDynamic {
public:
    TreeDynamic(){
        root = new NodeDynamic<T>;
    }
    ~TreeDynamic(){
        delete root;
    }
    NodeDynamic<T> *getRoot(){
        return(root);
    }
    void setRoot(NodeDynamic<T> *newRoot){
        root = newRoot;
    }
    void print(){
        root->printAllBelow();
    }
    bool insertSubtree(NodeDynamic<T> *newParent, NodeDynamic<T> *newChild);
    int count(T value) {
        return root->count(value);
    }
private:
    NodeDynamic<T> *root;
};

template <typename T>
bool TreeDynamic<T>::insertSubtree(NodeDynamic<T> *newParent, NodeDynamic<T> *newChild){
    bool canPerform = newParent->isInTheSameTree(root)
                      && !newParent->isInTheSameTree(newChild)
                      && !newChild->isRoot();
    if (canPerform)
    {
        newChild->detachFromParent();
        newParent->addNewChild(newChild);
    }
    return canPerform;
}

template <typename T>
void NodeDynamic<T>::setValue(T newValue) {
    value = newValue;
}

template <typename T>
int NodeDynamic<T>::getChildrenNumber() {
    return(children.size)();
}
template <typename T>
int NodeDynamic<T>::getMyIndex() {
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

template <typename T>
void NodeDynamic<T>::setRoot(NodeDynamic *newRoot) {
    root = newRoot;
    for (int i = 0 ; i < getChildrenNumber() ; i++)
    {
        children.at(i)->setRoot(newRoot);
    }
}

template <typename T>
void NodeDynamic<T>::addNewChild() {
    addNewChild(new NodeDynamic<T>());
}

template <typename T>
void NodeDynamic<T>::addNewChild(NodeDynamic *newChild) {
    newChild->parent = this;
    newChild->setRoot(root);
    children.push_back(newChild);
}

template <typename T>
void NodeDynamic<T>::removeChild(int index){
    children.erase(children.begin()+index);
}

template <typename T>
void NodeDynamic<T>::detachFromParent() {
    if (this!=root)
    {
        parent->removeChild(getMyIndex());
    }
}

template <typename T>
NodeDynamic<T> *NodeDynamic<T>::getChild(int childIndex) {
    if (childIndex >= 0 && childIndex < getChildrenNumber())
    {
        return children[childIndex];
    }
    else return nullptr;
}

template <typename T>
void NodeDynamic<T>::print() {
    cout << " " << value;
}

template <typename T>
void NodeDynamic<T>::printAllBelow() {
    print();
    for (int i = 0 ; i < getChildrenNumber() ; i++)
    {
        getChild(i)->printAllBelow();
    }
}

template <typename T>
bool NodeDynamic<T>::isInTheSameTree(NodeDynamic *otherNode) {
    return root == otherNode->root;
}

template <typename T>
bool NodeDynamic<T>::isRoot()
{
    return root==this;
}

template <typename T>
int NodeDynamic<T>::count(T searchedValue) {
    int counter;
    if (searchedValue == this->value) counter = 1;
    else counter = 0;
    for (int i = 0 ; i < getChildrenNumber() ; i++)
    {
        counter += children.at(i)->count(searchedValue);
    }
    return counter;
}


#endif //UNTITLED1_TREEDYNAMIC_H
