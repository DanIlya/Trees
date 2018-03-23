#include "AVLtree.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct tree_element
{
        int value;                      // Element value
        struct tree_element* left;      // Pointer to left subtree
        struct tree_element* right;     // Pointer to right subtree
        int h;
} tree_element;


tree_element* AVLtree::create_tree_element(int i)
{
     tree_element* p =(tree_element*) malloc(sizeof(tree_element));
     p ->value = i;
     p -> left = NULL;
     p->right = NULL;
     p->h = 0;
     return p;
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


    root->h = AVLtree::maxpointer(root->left->h,root->right->h) + 1;

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

void AVLtree::printh()
{
    printh_tree(this->root);
}
