//
// Created by 48791 on 18.11.2022.
//

#include "TreeDynamic.h"
#include "NodeDynamic.h"

TreeDynamic::TreeDynamic() {
    //root = new NodeDynamic;
}

TreeDynamic::~TreeDynamic() {
    //delete root;
}

NodeDynamic *TreeDynamic::getRoot() {
    return(root);
}

void TreeDynamic::setRoot(NodeDynamic *newRoot) {
    root = newRoot;
}

void TreeDynamic::print() {
    root->printAllBelow();
}

bool TreeDynamic::insertSubtree(NodeDynamic *newParent, NodeDynamic *newChild) {
    bool canPerform = newParent->isInTheSameTree(root) && !newParent->isInTheSameTree(newChild);
    if (canPerform)
    {
        newChild->detachFromParent();
        newParent->addNewChild(newChild);
    }
    return canPerform;
}
