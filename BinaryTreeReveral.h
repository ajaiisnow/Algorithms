#ifndef BINARY_TREE_REVERSAL
#define BINARY_TREE_REVERSAL

class Node
{
public:
    Node( int val): val(val), left_child(0), right_child(0)
    {
    }

    int val;
    Node* left_child;
    Node* right_child;
};


class BinarySearchTree
{
public:
    BinarySearchTree(): Tree(0){}
    void AddNodes( int val);
    void Inorder_Traversal(){Inorder_Traversal(Tree);}
    void Preorder_Traversal(){Preorder_Traversal(Tree);}
    void Postorder_Traversal(){Postorder_Traversal(Tree);}
    void ReverseTree(){ReverseTree(Tree);}

private:
    void Inorder_Traversal(Node* Tree);
    void Preorder_Traversal(Node* Tree);
    void Postorder_Traversal(Node* Tree);
    void ReverseTree(Node* Tree);
    Node* AddNodes( Node* Tree,int val);

private:
    Node* Tree;
};

#endif