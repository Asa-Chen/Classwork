//Alot of vocab


//Binary trees
//special node called 'root'. Only node that does not have parent. Not relating to inheritence.
//Nodes can be associated with other nodes.
//Nodes below are called left and right nodes.
//Can only have a max of two decenants per node
//Can never have a cycle, all nodes lead to the root. 
//ancestor nodes are the nodes above, decendants are below.
//imidiate decendants are children.
//imidiate ancestors are parents.
//Nodes without children, at the end of the tree are called leaf/leaves.
//The larger tree has 'sub-trees' inside it, which can be derrived from any node and its decendants.
//Depth of a node is how many levels from the root you are.
//Total depth is the total number of levels the tree has. Root is 0, the next is 1, etc.
//A 'full' tree is a tree where every node, except for the leaves, has exactly two children.
//A 'complete' tree is one where, starting from the left, every node to the left of the node with one or no children has two children.
//A full tree is complete but a complete tree is not always full.


//defining a node to make a binary tree
//can be done with structs or classes
//Binary tree nodes need pointers (left & right) instead of next or next & prev
class Bnode{
    public:
        Bnode(int d = 0, Bnode* l = NULL, Bnode* r = NULL);
        int data() {return dat;}
        Bnode* left() {----}
        Bnode* right() {----}
        void set_data(int d);
        void set_left(Bnode* t);
        void set_right(Bnode* t);
    private:
    Bnode* left_child;
    Bnode* right_child;
    int dat;
};

//Function to destroy the list
//Easiest way to delete a tree from the bottom up is to use recursion
void clear_tree(Bnode*& root){
    //Recursion base case, empty list
    if(root == NULL) {
        return;
    } else { //You want to delete all of the left and right subtrees
        clear_tree(root -> left());
        clear_tree(root -> right());
        delete root;
        root = NULL;
    }
}
