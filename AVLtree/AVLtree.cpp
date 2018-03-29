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
    int h;                          // tree hight
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

int AVLtree::geth()
{
    return this->root->h;
}

tree_element* AVLtree::balance_knot(tree_element* knot)
{
    if (knot == NULL)
    {
        cout << "You gave NULL to balancing function!" << endl;
        return NULL;
    }


    tree_element* dub;
    tree_element* dubl;
    tree_element* dubr;
    tree_element* dubright;
    tree_element* dubrl;
    int hr, hl, hrr, hrl, hll, hlr;
    if (knot->right == NULL)
        hr = 0;
    else
    {
        hr = knot->right->h;
	if (knot->right->left == NULL)
	    hrl = 0;
	else
	    hrl = knot->right->left->h;

	if (knot->right->right == NULL)
	    hrr = 0;
	else
	    hrr = knot->right->right->h;
	
    }

    if (knot->left == NULL)
        hl = 0;
    else
    {
        hl = knot->left->h;
	if (knot->left->left == NULL)
            hll = 0;
        else
            hll = knot->left->left->h;

        if (knot->left->right == NULL)
            hlr = 0;
        else
            hlr = knot->left->right->h;

    }

    if (hr == hl +2)
    {

        if (hrl <= hrr)
        {
            dub = knot->right;
            knot->right = knot->right->left;
            dub->left = knot;
	    
	    dub->h = hl + 2;
	    dub->left->h = hl + 1;

            return dub;
        }
        else
        {
            dubl = knot->right->left->left;
            dubr = knot->right->left->right;
            dubright = knot->right;
	    dubrl = knot->right->left;

	    dubright->left = dubr;
	    knot->right = dubl;
	    dubrl->right = dubright;
	    dubrl->left = knot;
	    knot = dubrl;
	    /*
	    knot->right->left->right = knot->right;
	    knot->right->left->left = knot;
	    knot = knot->right->left;
	    knot->right->left = dubr;
	    knot->left->right = dubl;
            */	    
	    knot->h = maxpointer(knot->left, knot->right) + 1;
	    knot->left->h = maxpointer(knot->left->left, knot->left->right) + 1;
	    knot->right->h = maxpointer(knot->right->left, knot->right->right) + 1;

            return knot;
        }

    }
    else if (hl == hr +2)
    {

        if (hlr <= hll)
        {
            dub = knot->left;
            knot->left = knot->left->right;
            dub->right = knot;

	    dub->h = hr + 2;
            dub->right->h = hr + 1;

            return dub;
        }
        else
        {
            dubr = knot->left->right->right;
            dubl = knot->left->right->left;
            dubright = knot->left;
	    dubrl = knot->left->right;

            dubright->right = dubl;
            knot->left = dubr;
            dubrl->left = dubright;
            dubrl->right = knot;
            knot = dubrl;
   	    /*
	    knot->left->right->left = knot->left;
            knot->left->right->right = knot;
            knot = knot->left->right;
            knot->left->right = dubl;
            knot->right->left = dubr;          
 	    */
	    knot->h = maxpointer(knot->left, knot->right) + 1;
            knot->right->h = maxpointer(knot->right->left, knot->right->right) + 1;
            knot->left->h = maxpointer(knot->left->left, knot->left->right) + 1;


            return knot;

        }
    }

    if ((hl-hr)*(hl-hr) > 4)
    {
        cout << "Something realy bad has happened to your tree (in elem->value = "<< knot->value << ")."  << endl;
        // << " You may use function Balance from AVLtree class to solve this problem." <<endl;
        return knot;
    }
    if ((hl-hr)*(hl-hr) < 4)
    {
        cout << "Knot (value = " << knot->value << ") is balanced." << endl;
        return knot;
    }
}

/*tree_element* AVLtree::Balance(tree_element* root)
{
    //Go to the depths of chaos
    if (root->h != 1)
    {
        if ((root->left == NULL) && (root->right == NULL))
            return root;

        else if (root->left == NULL)
            root->right = Balance(root->right);

        else if (root->right == NULL)
            root->left = Balance(root->left);

        else if ()
    }
}
*/

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
	root->h = 1;
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

    root = AVLtree::balance_knot(root);
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

//Для проверок всяких (выводит дерево с высотой каждого элемента)
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
            printh_tree(cur->left);
        }
        cout << cur->value << " h= " << cur->h << endl;
        if (cur->right != NULL)
        {
            printh_tree(cur->right);
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
        //cout << "Deleating error" << endl;
        return root;
    }

    tree_element* parent = Umka(root,elem);
    if (parent == NULL)
    {
        //cout << "Root element was deleated" << endl;

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

