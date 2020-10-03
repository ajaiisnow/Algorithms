#include <iostream>
#include "BinaryTreeReveral.h"
using namespace std;

void BinarySearchTree::Inorder_Traversal(Node* Tree)
{
    if(Tree == 0)
    {
        return;
    }
    
    Inorder_Traversal( Tree->left_child);
    cout << Tree->val << "\t";
    Inorder_Traversal( Tree->right_child);
}
void BinarySearchTree::Preorder_Traversal(Node* Tree)
{
    if(Tree == 0)
    {
        return;
    }
    cout << Tree->val << "\t";      
    Preorder_Traversal( Tree->left_child);
    Preorder_Traversal( Tree->right_child);
}

void BinarySearchTree::Postorder_Traversal(Node* Tree)
{
    if(Tree == 0)
    {
        return;
    }   
    Postorder_Traversal( Tree->left_child);
    Postorder_Traversal( Tree->right_child);
    cout << Tree->val << "\t"; 
}

void BinarySearchTree::ReverseTree(Node* Tree)
{
    if(Tree == 0)
    {
        return;
    }
    Node* pTemp = Tree->left_child;
    Tree->left_child = Tree->right_child;
    Tree->right_child = pTemp;

    ReverseTree( Tree->left_child);
    ReverseTree( Tree->right_child);
}

Node* BinarySearchTree::AddNodes( Node* Tree, int val)
{
    if(Tree == 0)
    {
        Tree = new Node( val );
    }
    else if(val > Tree->val)
    {
        Tree->right_child = AddNodes(Tree->right_child, val);
    }
    else 
    {
        Tree->left_child = AddNodes(Tree->left_child, val);
    }
    return Tree;
}

void BinarySearchTree::AddNodes( int val)
{
    Tree = AddNodes(this->Tree, val);
}

int main( int argc, char** argv)
{
    BinarySearchTree bst;
    bst.AddNodes(50);
    bst.AddNodes(30);
    bst.AddNodes(20);
    bst.AddNodes(40);
    bst.AddNodes(70);
    bst.AddNodes(60);
    bst.AddNodes(80);
    
    bst.Inorder_Traversal();
    cout << endl;
    cout << "Reversed Nodes" <<endl;
    bst.ReverseTree();
    bst.Inorder_Traversal();

}







