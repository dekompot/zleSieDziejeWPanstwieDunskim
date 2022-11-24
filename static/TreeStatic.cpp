//
// Created by 48791 on 18.11.2022.
//

#include "TreeStatic.h"

TreeStatic::TreeStatic() {

}

TreeStatic::TreeStatic(NodeStatic newRoot) {
    setRoot(newRoot);
}

TreeStatic::~TreeStatic() {

}

NodeStatic *TreeStatic::getRoot() {
    return(&root);
}

void TreeStatic::setRoot(NodeStatic newRoot) {
    root = newRoot;
}

void TreeStatic::print() {
    root.printAllBelow();
}

bool TreeStatic::insertSubtree(NodeStatic *newParent, NodeStatic *newChild) {
    bool canPerform = newParent->isInTheSameTree(&root) && !newParent->isInTheSameTree(newChild);
    if (canPerform)
    {
        int oldIndex = newChild->getMyIndex();
        NodeStatic oldParent = *newChild->getParent();
        //newChild->detachFromParent();
        newParent->addNewChild(newChild);
        oldParent.removeChild(oldIndex);
    }
    return canPerform;
}
