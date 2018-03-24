#include <iostream>

#include"AVLtree.hpp"

using namespace std;

int main()
{
    Container* c = new AVLtree();

    for(int i = 1; i < 10; i++)
        c->insert(i*i);

    cout << "Tree after creation:" << endl;
    c->print();

    delete c;
    return 0;
}

