/*
Auther: Bryan D Ward
Course:CS 315
Assignment: Lab 3 Part B
*/

#include "BinSearchTree.hpp"   
#include "TreeNode.hpp"
#include <iostream>
#include <queue> 
using namespace std;
TreeNode *BinSearchTree::local_insert( TreeNode *root, int v ) {
   if( root == nullptr )
       return new TreeNode( v );
   if( root->value() < v )
       root->rightSubtree( local_insert( root->rightSubtree(), v ) );
   else
       root->leftSubtree( local_insert( root->leftSubtree(), v ) );
   return root;
}

void BinSearchTree::insert(int v) {
    if( ! find(v) )
        root = local_insert( root, v );

}

bool BinSearchTree::local_find(TreeNode *root, int v){
	if ( root == nullptr)
		return false;
	if(root -> value () == v)
		return true;
	if(root -> value () > v)
		return local_find(root -> leftSubtree(),v);
	return local_find (root -> rightSubtree(),v);
}

bool BinSearchTree::find(int v){
	local_find (root,v);
}
bool BinSearchTree::iterFind(int v){
	TreeNode *current = root;
	while (current != nullptr)
	{
		if (current-> value() == v)
			return true;
		if(current -> value() > v)
			current = current -> leftSubtree();
		else if(current -> value () < v)
			current = current -> rightSubtree();
	}
	return false;

}
int BinSearchTree::local_size(TreeNode *root){
	
	if ( root == nullptr)
		return 0;
	return 1 + local_size(root->leftSubtree()) + local_size(root->rightSubtree());	
}

int BinSearchTree::size(){
	
	local_size(root);
}
void BinSearchTree::inorderDump(){
	local_inorderDump(root);
	
}

void BinSearchTree::local_inorderDump(TreeNode *root){
	if(root == nullptr)
		return;
	local_inorderDump(root->leftSubtree());
	cout << root -> value () << endl;
	local_inorderDump(root->rightSubtree());
}
int BinSearchTree::local_maxDepth(TreeNode *root)
{
	if (root == nullptr)
		return 0;
	int i = 1 + local_maxDepth(root->leftSubtree());
	int r = 1 + local_maxDepth(root->rightSubtree());
	if (i> r)
		return i;
	return r;
}
int BinSearchTree::maxDepth(){
 	local_maxDepth(root);
}
void BinSearchTree::levelOrderDump()
{
	if(root == nullptr)
		return;
	queue<TreeNode*> Q;
	Q.push(root);
	while (!Q.empty()){
		TreeNode* current = Q.front();
		cout << current->value() <<" ";
		if (current->leftSubtree() != nullptr)
			Q.push(current->leftSubtree());
		if (current->rightSubtree() != nullptr)
			Q.push(current->rightSubtree());
		Q.pop();
	}

}
bool BinSearchTree::remove( int v )
{
	TreeNode *parent = nullptr;
	//TreeNode *curent = root;
	//return local_remove(int v, root, parent );
	TreeNode *current = root;
	if ( !find(v))
		return false;
	while (current -> value() != v)
	{

		parent = current;
		if(current -> value() > v)
		{
			current = current -> leftSubtree();
		}
		else if(current -> value () < v)
		{
			current = current -> rightSubtree();
		}
	}	
	// if there are no children of the node do this.	
	if(current->leftSubtree() == nullptr && current->rightSubtree() == nullptr)
	{
		if(current -> value() < parent -> value()){
	 		parent -> leftSubtree(nullptr);
			delete current;
		}
		else if (current -> value () > parent ->value()){
			parent -> rightSubtree(nullptr);
			delete current;
		}
	}
	// if there is only one child do this
	// this is for a node with no left child;	
	else if(current->leftSubtree() == nullptr)
	{	
		if(current -> value() < parent -> value()){
			parent -> leftSubtree(current->rightSubtree());
			delete current;
		}		
		else if(current -> value() > parent -> value()){
			parent -> rightSubtree(current->rightSubtree());
			delete current;
		}		
	}
	// this is for a child with no right child
	else if (current ->rightSubtree() == nullptr)
	{

		if(current -> value() < parent -> value()){
			parent -> leftSubtree(current->leftSubtree());
			delete current;
		}		
		else if(current -> value() > parent -> value()){
			parent -> rightSubtree(current->leftSubtree());
			delete current;
		}		
	}
	else {
	 	TreeNode *currMin = current->rightSubtree();
		
		//
		//TreeNode *parentMin  = current;
		parent = current;
		while( currMin->leftSubtree() != nullptr)
		{
			parent = currMin;
			currMin = currMin -> leftSubtree();
		}
		if(currMin->rightSubtree() != nullptr)
		{	
			if(currMin -> value() < parent -> value()){
				current -> value() = currMin -> value();					
				parent -> leftSubtree(currMin->rightSubtree());
				delete currMin;
			}		
			else if(currMin -> value() > parent -> value()){
				current -> value() = currMin -> value();					
				parent -> rightSubtree(currMin->rightSubtree());
				delete currMin;
			}		
		}
		if(currMin -> value() < parent -> value()){
			current -> value() = currMin -> value();					
			delete currMin;
	 		parent -> leftSubtree(nullptr);
		}
		else if (currMin -> value () > parent ->value()){
			current -> value() = currMin -> value();					
			delete currMin;
			parent -> rightSubtree(nullptr);
		}
	
	}
	return true;
}
/*
bool BinSearchTree::local_remove(int v, TreeNode *root, TreeNode *parent)
{
	TreeNode *current = root;
	if (root == nullptr)
		return false;
	if(root -> value () > v){
		parent = current;
		return local_remove(v, root -> leftSubtree(),parent );
	}
	if(root ->value () < v)
		return local_remove(v,root -> rightSubtree(),parent);
	//case 1 if the node has no children

	if(root->leftSubtree() == nullptr && root->rightSubtree() == nullptr)
	{
		delete root;
		root = nullptr;
		return true;
	}
	// case two if left child is null
	if(root->leftSubtree() == nullptr)
	{	
		TreeNode *temp = root;
		root = root->rightSubtree();
		return true;
	}
	if (root->rightSubtree() == nullptr)
	{
		TreeNode *temp = root;
		root = root->leftSubtree();
		return true;
	}
}
*/			





/*
TreeNode BinSearchTree::minValue( TreeNode *root ){
	if (root == nullptr)
		return nullptr;
        if(root -> leftSubtree() == nullptr)
                return root -> value();
        return minValue( root ->leftSubtree() );

}

*/
 
int BinSearchTree::kthSmallest(int k)
{
	if ((k - 1) > local_size(root))
	{
		cout << "the k size is to big"<< endl;
		return 0;
	}
	return helper_kthSmallest(k, root);
}
int BinSearchTree::helper_kthSmallest(int k,TreeNode *root)
{
	if (k -1 == local_size(root->leftSubtree()))
		return root -> value();
	if (k - 1 < local_size(root->leftSubtree()))
		return helper_kthSmallest( k , root->leftSubtree());	
	if (k - 1 > local_size(root->leftSubtree()))
		return helper_kthSmallest ((k-1) - local_size(root->leftSubtree()),root->rightSubtree());

		

}

void BinSearchTree:: valueAtLevel(int k)
{
	helper_valueAtLevel(k, root);
	
}
void BinSearchTree::helper_valueAtLevel(int k , TreeNode *root)
{
	if (root == nullptr)
		return;
	if (k == 1) {
		cout << root->value() << " , ";
	return;
}
	helper_valueAtLevel(k - 1, root->leftSubtree());
	helper_valueAtLevel(k - 1,root ->rightSubtree());	
}

void BinSearchTree::iterValueAtLevel(int k)
{

	if(root == nullptr)
		return;
	queue<TreeNode*> Q;
	Q.push(root);
	int level = Q.size();
	int Plevel = 1;
	while(k > level){
		
		for ( int i = 0; i < Plevel; i++)
		{
			TreeNode* current = Q.front();
				//cout << current->value() <<" ";
			if (current->leftSubtree() != nullptr)
				Q.push(current->leftSubtree());
			if (current->rightSubtree() != nullptr)
				Q.push(current->rightSubtree());
			Q.pop();
		}
		Plevel = Q.size();
		level ++;
	}
	while (!Q.empty())
	{
		cout << Q.front() -> value() << endl;
		Q.pop();
	}
}
int BinSearchTree::iterMaxDepth()
{
	if (root == nullptr)
	        return 0;
 
	    queue<TreeNode *> Q;
 
	    Q.push(root);
    	int depth = 0;
 
    	while (1)
    	{
        	int count = Q.size();
        	if (count == 0)
        	    return depth;
 
        	depth++;
 
        	while (count > 0)
        	{
            		TreeNode *current = Q.front();
            		Q.pop();
            		if (current -> leftSubtree() != nullptr)
                		Q.push(current->leftSubtree());
            		if (current->rightSubtree() != nullptr)
                		Q.push(current->rightSubtree());
            		count--;
        	}
    }
}

bool BinSearchTree::hasRootToLeafSum(int sum){	

	if (local_hasRootToLeafSum(sum,root))
		return true;
	return false;

}
bool BinSearchTree::local_hasRootToLeafSum(int sum, TreeNode *root)
{

	if (root == nullptr)
	{
		if (sum == 0)
			return true;
		return false;
	}
	//if (root == nullptr)
	if(root->leftSubtree() == nullptr && root->rightSubtree() == nullptr)
	{
	//	cout <<currSum;
		if(root->value()==sum)
			return true;
		return false;
	}
	if( root->leftSubtree() == nullptr&& root->rightSubtree())
		return local_hasRootToLeafSum(sum-root->value(),root->rightSubtree());
	if(root -> rightSubtree() == nullptr && root ->leftSubtree() )
		return local_hasRootToLeafSum(sum-root->value(),root->leftSubtree());
	
	return local_hasRootToLeafSum(sum-root->value(),root->rightSubtree())||
		local_hasRootToLeafSum(sum-root->value(),root->leftSubtree());

}

bool BinSearchTree::areIdentical(BinSearchTree *bst)
{
	TreeNode *tree1 = bst ->root;
	TreeNode *tree2 = this ->root;
	return local_areIdentical(tree2,tree1);
}
bool BinSearchTree::local_areIdentical(TreeNode *bst,TreeNode *root)
{
	if (root==nullptr && bst==nullptr)
		return 1;
	if(root != nullptr && bst != nullptr)
	{
		return local_areIdentical(root->leftSubtree(), bst->leftSubtree())
		&& local_areIdentical(root->rightSubtree(),bst->rightSubtree());
	}
	return 0;
}
BinSearchTree * BinSearchTree::intersectWith(BinSearchTree *bst){

	BinSearchTree *intersect = new BinSearchTree();
	if (root == nullptr||bst == nullptr)
		return intersect; 
	return local_intersectWith(root,bst,intersect);
}
BinSearchTree * BinSearchTree::local_intersectWith(TreeNode *root, BinSearchTree *bst, BinSearchTree *intersect)
{
	if (root == nullptr)
		return intersect;
	if(bst->find(root->value()))
		intersect->insert(root->value());
	return local_intersectWith(root->leftSubtree(), bst,local_intersectWith(root-> rightSubtree(),bst,intersect));
}  
BinSearchTree * BinSearchTree::unionWith(BinSearchTree *bst)
{
	
	BinSearchTree *unionW = bst;
	if (root == nullptr||bst == nullptr)
		return unionW; 
	return local_unionWith(root,bst,unionW);
}

BinSearchTree * BinSearchTree::local_unionWith(TreeNode *root,BinSearchTree *bst, BinSearchTree *unionW )
{
	if(root ==nullptr)
		return unionW;
	if(!bst->find(root->value()))
		unionW->insert(root->value());
	return local_unionWith(root->leftSubtree(),bst,local_unionWith(root->rightSubtree(),bst,unionW));
}
BinSearchTree * BinSearchTree::diffrenceOf(BinSearchTree *bst)
{

	BinSearchTree *diffrence = bst;
	if (root == nullptr||bst == nullptr)
		return diffrence; 
	return local_diffrenceOf(root,bst,diffrence);
}  

BinSearchTree * BinSearchTree::local_diffrenceOf(TreeNode * root,BinSearchTree *bst,BinSearchTree *diffrence)
{
	if(root ==nullptr)
		return diffrence;
		
	if(bst->find(root->value()))
		diffrence -> remove(root->value());
	return local_diffrenceOf(root->leftSubtree(),bst,local_diffrenceOf(root->rightSubtree(),bst,diffrence));	
}


























