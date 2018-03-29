#include <iostream>
#include<cmath>
#include<cstdlib>

#include"AVLtree.hpp"

using namespace std;

int main()
{
    //Container* tree = new AVLtree();

    AVLtree* tree = new AVLtree();

    int v;
    for(int i = 0; i < 1000; i++)
    {
	v = rand() % 2000 - 1000;
	//cout << "insert: " << v << endl; 
        tree->insert(v);
	//cout << "Tree:" << endl;
	//tree->print(); 
    }

    int h = tree->geth();
    if(h <= 1.45*log2(2+1000))
 	cout << "Balance is OK" << endl;	 
    

    cout << "Tree after creation:" << endl;
    tree->print();

    delete tree;
    return 0;
}

