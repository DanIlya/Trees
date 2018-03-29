#ifndef AVLTREE
#define AVLTREE

#include "../SimpleTree/SimpleTree.hpp"


class AVLtree: public SimpleTree
{
public:
AVLtree();
~AVLtree();
void insert(int value) override;
void remove(int value) override;
void print() override;
int geth();
protected:
//tree_element* Balance(tree_element* root);
tree_element* balance_knot(tree_element* knot);
tree_element* insert_into_tree(tree_element* root, tree_element* elem);
tree_element* create_tree_element(int i);
tree_element* delete_from_tree(tree_element* root, tree_element* elem);
void printh_tree(tree_element* cur);
int maxpointer(tree_element* r, tree_element* l);

};


#endif
