#include <iostream>
#include <stdlib.h>

#include "SimpleTree.hpp"

using namespace std;

SimpleTree::SimpleTree()
{
    this->root = NULL;
}

typedef struct tree_element
{
    int value;                      // Element value
    struct tree_element* left;      // Pointer to left subtree
    struct tree_element* right;     // Pointer to right subtree
} tree_element;


//Костыль для деструктора
void SimpleTree::Burn_this_tree(tree_element* root)
{
    if ((root->left == NULL) && (root->right == NULL))
        free(root);
    else
    {
        if (root->left != NULL)
        {
            Burn_this_tree(root->left);
        }
        if (root->right != NULL)
        {
            Burn_this_tree(root->right);
        }

        free(root);
    }

}


SimpleTree::~SimpleTree()
{
    Burn_this_tree(this->root);
}

// Create new element, set its value to 'i', return pointer to new element
tree_element* SimpleTree::create_tree_element(int i)
{
    tree_element* p =(tree_element*) malloc(sizeof(tree_element));
    p ->value = i;
    p -> left = NULL;
    p->right = NULL;
    return p;
}


// Search for given value in the tree
// Returns pointer to found element and NULL otherwise
tree_element* SimpleTree::search_by_value(tree_element* root, int value)
{
    //tree_element* cur = this->root;

    if (root == NULL)
    {
        //printf("Not found\n");
        return NULL;
    }

    else if (root->value == value)
    {
        //printf("Value found\n");
        return root;
    }

    else if (value < root->value)
    {
        root = search_by_value(root->left,value);
    }
    else if (value > root->value)
    {
        root = search_by_value(root->right,value);
    }
    return root;
}

//костыль для Insert
tree_element* SimpleTree::insert_into_tree(tree_element* root, tree_element* elem)
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
        root->left = insert_into_tree(root->left,elem);
    }
    else
    {
        root->right = insert_into_tree(root->right,elem);
    }

    return root;
}


// Insert element 'elem' into tree 'root'
void SimpleTree::insert(int value)
{
    tree_element* elem = this->create_tree_element(value);

    this->root = insert_into_tree(this->root,elem);
}

// Print tree
void SimpleTree::print_tree(tree_element* cur)
{
    if (cur == NULL)
    {
        //printf("I can not print root = NULL\n");
    }
    else
    {
        if (cur->left != NULL)
        {
            print_tree(cur->left);
        }
        cout << cur->value << endl;
        if (cur->right != NULL)
        {
            print_tree(cur->right);
        }
    }
}

void SimpleTree::print()
{
    print_tree(this->root);
}


bool SimpleTree::exists(int value)
{
    tree_element* cur = this->root;
    if (search_by_value(cur,value) != NULL)
        return 1;
    else
        return 0;
}

//searching for parent (костыль для костыля для remove)
tree_element* SimpleTree::Umka (tree_element* root, tree_element* elem)
{
    if (root == NULL)
    {
        //printf("Umka: root = NULL\n");
        return NULL;
    }

    else if (elem == NULL)
    {
        //printf("Umka: elem = NULL\n");
        return NULL;
    }

    else if ((root->left == elem) | (root->right == elem))
    {
        return root;
    }

    else if (elem == root)
    {
        //printf("Your element is a root element, so he don't have any parents\n");
        return NULL;
    }

    else if (elem->value < root->value)
    {
        root = Umka(root->left,elem);
    }
    else if (elem->value > root->value)
    {
        root = Umka(root->right,elem);
    }
    return root;


}


// Костыль для remove
tree_element* SimpleTree::delete_from_tree(tree_element* root, tree_element* elem)
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

void SimpleTree::remove(int value)
{
    this->root = SimpleTree::delete_from_tree(this->root,SimpleTree::search_by_value(this->root,value));
}


