#ifndef AVLTREE
#define AVLTREE

#include "../SimpleTree/SimpleTree.hpp"


//typedef struct tree_element;

class AVLtree: public SimpleTree
{
public:
AVLtree();
~AVLtree();
void insert(int value) override;
void remove(int value) override;
void print() override;
protected:
tree_element* insert_into_tree(tree_element* root, tree_element* elem);
tree_element* create_tree_element(int i);
tree_element* delete_from_tree(tree_element* root, tree_element* elem);
void printh_tree(tree_element* cur);
int maxpointer(tree_element* r, tree_element* l);

};


#endif
