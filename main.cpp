    #include <iostream>
    #include "TreeNode.hpp"
    #include "BinSearchTree.hpp"
	using namespace std;
    int main( int argc, char *argv[] ) {
        // create a tree and then print the values of its nodes 
        // from the smallest to the largest.
 
        BinSearchTree *tree = new BinSearchTree();

        int v;
        while( std::cin >> v ) {
            tree->insert( v );
        }
	
        BinSearchTree *bst = new BinSearchTree();
//	bst = tree;
//	for(int i = 102; i <= 1000; i+=100 )
//	{
//		bst->insert(i);
//	}
//	bst = tree;
  	tree->inorderDump();
//	cout << tree->maxDepth()<<endl;
	//	tree->levelOrderDump();	
//	cout <<endl;
//	if(tree->iterFind(102))
//	cout <<"found it";	
//	cout << tree->size()<<endl;
//	cout << endl;

//	tree->remove(80);
	tree->inorderDump();
//
cout << "this is the k th smallest == "<<	tree -> kthSmallest(2);
/*
	cout << " level 3" << endl;
	tree -> iterValueAtLevel(3);
	cout<<" level 4"<<endl;
	tree -> iterValueAtLevel(4);
*/
//cout << tree -> iterMaxDepth() <<" , ";	
//if (tree->hasRootToLeafSum(459))
//	cout << "it worked!!!!!";
// 
//if(tree->areIdentical(bst))
//	cout <<" fuck ya";
	
        BinSearchTree *intersect =
	tree->intersectWith(bst);
	intersect->levelOrderDump();
	cout<<" this is union"<<endl;
	BinSearchTree *unionW = tree ->unionWith(bst); 
	unionW->levelOrderDump();
	cout << "\n This is diffrence \n";
	BinSearchTree *diffrence = tree ->diffrenceOf(bst); 
	diffrence -> levelOrderDump();
    return 0;			    
	
    }
