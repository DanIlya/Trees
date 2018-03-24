#include "AVLtree.hpp"
#include <iostream>
#include <stdlib.h>
#include "../SimpleTree/SimpleTree.hpp"

using namespace std;

typedef struct tree_element
{
        int value;                      // Element value
        struct tree_element* left;      // Pointer to left subtree
        struct tree_element* right;     // Pointer to right subtree
        int h;
} tree_element;

AVLtree::AVLtree()
{
}

AVLtree::~AVLtree()
{
}

tree_element* AVLtree::create_tree_element(int i)
{
     tree_element* p =(tree_element*) malloc(sizeof(tree_element));
     p ->value = i;
     p -> left = NULL;
     p->right = NULL;
     p->h = 0;
     return p;
}

void AVLtree::insert(int value)
{
	this->root = AVLtree::insert_into_tree(this->root, AVLtree::create_tree_element(value));
}

tree_element* AVLtree::insert_into_tree(tree_element* root, tree_element* elem)
{
    if (root == NULL)
    {
        //printf("Inserting into NULL\n");
        root = elem;
        return root;
    }

    if (elem == NULL)
    {
        //printf("Tree + NULL = Tree\n");
        return root;
    }

    if (elem->value < root->value)
    {
        root->left = AVLtree::insert_into_tree(root->left,elem);
    }
    else
    {
        root->right = AVLtree::insert_into_tree(root->right,elem);
    }


    root->h = AVLtree::maxpointer(root->left,root->right) + 1;

 return root;
}

int AVLtree::maxpointer(tree_element* l, tree_element* r)
{
int hl, hr;

if (l == NULL)
         hl = 0;
    else
         hl = l->h;

    if (r == NULL)
         hr = 0;
    else
         hr = r->h;

    if (hl > hr)
	 return hl;
    else
	 return hr;

}

void AVLtree::print()
{
	printh_tree(this->root);
}

void AVLtree::printh_tree(tree_element* cur)
{
    if (cur == NULL)
    {
    //printf("I can not print root = NULL\n");
    }
    else
    {
        if (cur->left != NULL)
        {
            AVLtree::printh_tree(cur->left);
        }
        cout << cur->value << " h= " << cur->h << endl;
        if (cur->right != NULL)
        {
            AVLtree::printh_tree(cur->right);
        }
    }
}

void AVLtree::remove (int value)
{
	this->root = AVLtree::delete_from_tree(this->root, AVLtree::search_by_value(this->root, value)); 
}

// Костыль для remove
tree_element* AVLtree::delete_from_tree(tree_element* root, tree_element* elem)
{
    if ((root == NULL) | (elem == NULL))
    {
        //printf("Deleating error\n");
        return root;
    }

    tree_element* parent = Umka(root,elem);
    if (parent == NULL)
    {
        //printf("Root element was deleated\n");

        root->right = insert_into_tree(root->right,root->left);
        tree_element* Newroot = root->right;

        free(root);
        return Newroot;
    }

    if ((elem->left == NULL) && (elem->right == NULL))
    {
        if (elem->value < parent->value)
        parent->left = NULL;
        else
        parent->right = NULL;

        free(elem);
        return root;
    }


    if (elem->value < parent->value)
    parent->left = elem->right;
    else
    parent->right = elem->right;

    insert_into_tree(parent,elem->left);

    free(elem);
    return root;
}

