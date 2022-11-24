#include "NodeStatic.h"

NodeStatic::NodeStatic() {
    value = 0;
    parent = NULL;
    root = this;
}

NodeStatic::~NodeStatic() {

}

void NodeStatic::setValue(int newValue) {
    value = newValue;
}

int NodeStatic::getChildrenNumber() {
    return(children.size());
}

void NodeStatic::addNewChild(NodeStatic *newChild) {
    newChild->parent = this;
    newChild->setRoot(this->root);
    children.push_back(*newChild);
}

void NodeStatic::addNewChild() {
    NodeStatic newChild;
    newChild.parent = this;
    newChild.root = this->root;
    children.push_back(newChild);
}

void NodeStatic::setRoot(NodeStatic *newRoot) {
    root = newRoot;
    for (int i = 0 ; i < getChildrenNumber() ; i++)
    {
        children.at(i).setRoot(newRoot);
    }
}

NodeStatic *NodeStatic::getChild(int childIndex) {
    if (childIndex >= 0 && childIndex < getChildrenNumber())
    {
        return &children[childIndex];
    }
    else return nullptr;
}

void NodeStatic::printNode() {
    cout << " " << value;
}

void NodeStatic::printAllBelow() {
    printNode();
    for (NodeStatic childNode: children) {
        childNode.printAllBelow();
    }
}

void NodeStatic::printAllAbove() {
    printNode();
    if (parent != NULL)
        parent->printAllAbove();
}

bool NodeStatic::isInTheSameTree(NodeStatic *otherNode) {
    return root == otherNode->root;
}

void NodeStatic::removeChild(int index){
    children.erase(children.begin()+index);
}

void NodeStatic::detachFromParent() {
    if (this!=root)
    {
        parent->removeChild(getMyIndex());
    }
}

int NodeStatic::getMyIndex() {
    int index = 0;
    if (root!= this)
    {
        for (int i = 0 ; i < parent->getChildrenNumber() ; i++)
        {
            if (parent->children.at(i).value == value) index = i;
        }
    }
    return index;
}

NodeStatic *NodeStatic::getParent() const {
    return parent;
}

bool NodeStatic::operator==(const NodeStatic &rhs) const {
    return value == rhs.value;
}

bool NodeStatic::operator!=(const NodeStatic &rhs) const {
    return !(rhs == *this);
}

bool NodeStatic::isRoot(){
    return root==this;
}

