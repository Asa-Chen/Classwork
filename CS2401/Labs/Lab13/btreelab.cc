#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Bnode{
	string data;
	Bnode* left;
	Bnode* right;
};

void inorder(Bnode* root){
	if(root != NULL){
		inorder(root -> left);
		cout << root -> data << endl;
		inorder(root -> right);
	}
}

void add(Bnode*& root, string item){
	if(root == NULL){
		root = new Bnode;
		root -> data = item;
		root -> left = root -> right = NULL;
	}
	else if (item <= root -> data)
		add(root -> left, item);
	else
		add(root -> right, item);
}

int size(Bnode* root){
	if(root == NULL) return 0;
	else
	return size(root -> left) + size(root -> right) + 1;
}

int search(Bnode*& root, string target) {
	if (root == NULL) {
	return 0;
	} else if (target == root -> data) {
	return search(root -> left, target) + 1;
	} else if (target < root -> data) {
		return search(root -> left, target);
	} else {
		return search(root -> right, target);
	}
}

int search_above(Bnode*& root, string target) {
	if (root == NULL) {
	return 0;
	} else if (target == root -> data) {
	return size(root -> right) + search_above(root -> left, target);
	} else if (target < root -> data) {
		return search_above(root -> left, target);
	} else {
		return search_above(root -> right, target);
	}
}

int main(){
Bnode* tree = NULL;
string idata;
string target;
int targetnum = 0;
int treesize = 0;
ifstream fin;
ofstream fout;


fin.open("names.txt");
if (fin.fail()) {cout << "\nFile failed to open."; return 0;}

while (!fin.eof()) {
	//while (fin.peek() == ' ' || fin.peek() == '\n') {fin.ignore();}
    getline(fin, idata);
    add(tree, idata);
}
fin.close();
//inorder(tree);
cout << "Please input a name to be searched: ";
cin >> target;
targetnum = search(tree, target);
treesize = search_above(tree, target);
target = target + " "; //NEED TO RUN THE FUNCTIONS TWICE SINCE SOME OF THE NAMES HAVE RANDOM SPACES AFTER THEM
treesize += search_above(tree, target);
targetnum += search(tree, target);
cout << target << "Appeared " << targetnum << " times in the list: " << treesize << " Names come after " << target << "in this list.";

	return 0;
}