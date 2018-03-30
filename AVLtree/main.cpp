#include <iostream>
#include<cmath>
#include<cstdlib>

#include"AVLtree.hpp"

using namespace std;

int main()
{
    //Container* tree = new AVLtree();

    AVLtree* tree = new AVLtree();
    int N = 100000;
    int v;
    for(int i = 0; i < N; i++)
    {
	v = rand() % 200000 - 100000;
	//cout << "insert: " << v << endl; 
        tree->insert(v);
	//cout << "Tree:" << endl;
	//tree->print(); 
    }
    
    for (int i = 0; i < 50000; i++)
    {
	v = rand() % 200000 - 100000;
	if (tree->exists(v))
	{
	    cout << v << " exist. delete it. " << endl;
	    tree->remove(v);
	    N = N-1;
	}
    }
    
    int h = tree->geth();
    if(h <= 1.45*log2(2+N))
 	cout << "Balance is OK" << endl;	 
    

    cout << "Tree after creation:" << endl;
    tree->print();

    if(h <= 1.45*log2(2+N))
        cout << "Balance is OK" << endl;
    
    tree->Am_I_Truly_Balanced();

    delete tree;
    return 0;
}

