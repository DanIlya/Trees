#include <iostream>

#include"SimpleTree.hpp"

using namespace std;

int main()
{
    Container* c = new SimpleTree();
    int v;
    int i;
    for(i = 0; i < 1000; i++)
    {
	v = rand() % 2000 - 1000;
        c->insert(v);
    }

    cout << "Tree after creation:" << endl;
    c->print();


    for(i = 0; i < 500; i++)
	{
	v = rand() % 2000 - 1000;
	if(c->exists(v))
	    {
		cout << v << " exists. delete it." << endl;
		c->remove(v);
	    }
	}

    cout << "Tree after deletion:" << endl;
    c->print();

    delete c;
    return 0;
}

