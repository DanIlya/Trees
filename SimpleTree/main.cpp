#include <iostream>

#include"SimpleTree.hpp"

using namespace std;

int main()
{
    Container* c = new SimpleTree();

    for(int i = 1; i < 10; i++)
        c->insert(i*i);

    cout << "Tree after creation:" << endl;
    c->print();

    cout << "Tree hight:" << endl;

    delete c;
    return 0;
}

