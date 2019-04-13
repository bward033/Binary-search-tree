#ifndef BINSEARCHTREE_HPP
#define BINSEARCHTREE_HPP
/*
Auther: Bryan D Ward
Course:CS 315
Assignment: Lab 3 Part B
*/
// Forward declaration of TreeNode class below.
// // Since BinSearchTree uses TreeNode pointers rather
// // than objects, we can get away with this in the .hpp.
// // You should include "TreeNode.hpp" from the .cpp
// class TreeNode;


class TreeNode;

class BinSearchTree {
public:
   void insert( int v );

   bool local_find(TreeNode *root, int v);
   bool find( int v );
   bool iterFind( int v );
   int size();
   int local_size(TreeNode *root);
   void inorderDump();
   void local_inorderDump(TreeNode *root);
   int maxDepth();
   int local_maxDepth(TreeNode *root);
   int kthSmallest(int k);
   int helper_kthSmallest(int k , TreeNode *root);
   bool remove( int v );
   void levelOrderDump();
   void valueAtLevel(int k);
   void helper_valueAtLevel(int k, TreeNode *root);
   void iterValueAtLevel(int k);
   int iterMaxDepth();
   bool hasRootToLeafSum(int sum);
   bool local_hasRootToLeafSum(int sum, TreeNode *root);
   bool areIdentical( BinSearchTree *bst);
   bool local_areIdentical(TreeNode *bst, TreeNode *root);
   BinSearchTree *intersectWith(BinSearchTree *bst);
   BinSearchTree *local_intersectWith(TreeNode *tree1, BinSearchTree *tree2, BinSearchTree *intersect);
   BinSearchTree *unionWith(  BinSearchTree * bst); 
   BinSearchTree *local_unionWith(TreeNode *root,  BinSearchTree *bst, BinSearchTree *unionW); 
   BinSearchTree *diffrenceOf(BinSearchTree *bst);
   BinSearchTree *local_diffrenceOf(TreeNode * root,BinSearchTree *bst, BinSearchTree *diffrence);
private:
   TreeNode *local_insert( TreeNode *, int );
   TreeNode *root;
};
#endif
