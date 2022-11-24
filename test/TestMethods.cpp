#include "../static/NodeStatic.h"
#include "../static/TreeStatic.h"
#include "../dynamic/NodeDynamic.h"
#include "../dynamic/TreeDynamic.h"

void staticTreeTest()
{
    NodeStatic root;
    root.addNewChild();
    root.addNewChild();
    root.getChild(0)->setValue(1);
    root.getChild(1)->setValue(2);
    root.getChild(0)->addNewChild();
    root.getChild(0)->addNewChild();
    root.getChild(0)->getChild(0)->setValue(11);
    root.getChild(0)->getChild(1)->setValue(12);
    root.getChild(1)->addNewChild();
    root.getChild(1)->addNewChild();
    root.getChild(1)->getChild(0)->setValue(21);
    root.getChild(1)->getChild(1)->setValue(22);
    TreeStatic secondTree;
    NodeStatic secondRoot;
    secondRoot.addNewChild();
    secondRoot.addNewChild();
    secondRoot.getChild(0)->setValue(3);
    secondRoot.getChild(1)->setValue(4);
    secondRoot.getChild(0)->addNewChild();
    secondRoot.getChild(0)->addNewChild();
    secondRoot.getChild(0)->getChild(0)->setValue(31);
    secondRoot.getChild(0)->getChild(1)->setValue(32);
    secondRoot.getChild(1)->addNewChild();
    secondRoot.getChild(1)->addNewChild();
    secondRoot.getChild(1)->getChild(0)->setValue(41);
    secondRoot.getChild(1)->getChild(1)->setValue(42);
    secondTree.setRoot(secondRoot);
    printf("\n %s \n","Print below root:");
    root.printAllBelow();
    printf("\n %s \n","Print above root's grandchildren:");
    root.getChild(0)->getChild(1)->printAllAbove();

    TreeStatic tree;
    //tree.print();
    tree.setRoot(root);
    printf("\n %s \n","First tree:");
    tree.print();
    printf("\n %s \n","Second tree:");
    secondTree.print();

    tree.insertSubtree(&root,secondRoot.getChild(0));

    printf("\n %s \n","First tree:");
    tree.print();
    printf("\n %s \n","Second tree:");
    secondTree.print();

    tree.setRoot(root);
    secondTree.setRoot(secondRoot);
    printf("\n %s \n","First tree:");
    tree.print();
    printf("\n %s \n","Second tree:");
    secondTree.print();
}
void dynamicTreeTest()
{
    NodeDynamic root;
    root.addNewChild();
    root.addNewChild();
    root.getChild(0)->setValue(1);
    root.getChild(1)->setValue(2);
    root.getChild(0)->addNewChild();
    root.getChild(0)->addNewChild();
    root.getChild(0)->getChild(0)->setValue(11);
    root.getChild(0)->getChild(1)->setValue(12);
    root.getChild(1)->addNewChild();
    root.getChild(1)->addNewChild();
    root.getChild(1)->getChild(0)->setValue(21);
    root.getChild(1)->getChild(1)->setValue(22);
    printf("\n %s \n","Print below root:");
    root.printAllBelow();

    TreeDynamic tree;
    tree.setRoot(&root);
    printf("\n %s \n","Our tree:");
    tree.print();

    TreeDynamic secondTree;
    NodeDynamic secondRoot;
    secondRoot.addNewChild();
    secondRoot.addNewChild();
    secondRoot.getChild(0)->setValue(3);
    secondRoot.getChild(1)->setValue(4);
    secondRoot.getChild(0)->addNewChild();
    secondRoot.getChild(0)->addNewChild();
    secondRoot.getChild(0)->getChild(0)->setValue(31);
    secondRoot.getChild(0)->getChild(1)->setValue(32);
    secondRoot.getChild(1)->addNewChild();
    secondRoot.getChild(1)->addNewChild();
    secondRoot.getChild(1)->getChild(0)->setValue(41);
    secondRoot.getChild(1)->getChild(1)->setValue(42);
    secondTree.setRoot(&secondRoot);
    printf("\n %s \n","Second tree:");
    secondTree.print();
    bool b =  tree.insertSubtree(&root,secondRoot.getChild(0));
    //bool b1 =  tree.insertSubtree(&root,&secondRoot);
    printf("\n %s \n","First tree:");
    tree.print();
    printf("\n %s \n","Second tree:");
    secondTree.print();
}
