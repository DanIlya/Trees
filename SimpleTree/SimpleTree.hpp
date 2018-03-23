#ifndef SIMPLETREE_H
#define SIMPLETREE_H

#include "Container.hpp"

typedef struct tree_element;

class SimpleTree: public Container
{
public:
    SimpleTree();
    ~SimpleTree();
    void insert(int value) override;
    bool exists(int value) override;
    void remove(int value) override;
    void print() override;


protected:
//typedef struct tree_element;
//костыльчики для рекурсии
void Burn_this_tree(tree_element* root);
tree_element* insert_into_tree(tree_element* root, tree_element* elem);
tree_element* create_tree_element(int i);
tree_element* search_by_value(tree_element* root, int value);
tree_element* delete_from_tree(tree_element* root, tree_element* elem);
tree_element* Umka (tree_element* root, tree_element* elem);
void print_tree(tree_element* cur);



tree_element* root;
};

#endif
