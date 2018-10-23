#include <iostream>
using namespace std;


template <typename T> class Tree {
	struct Node {
		T value;
		Node* left = nullptr;
		Node* right = nullptr;
		Node(const T& value) :value(value) {}
	};

	Node* root = nullptr;
public:
	void insert(const T& val) {
		Node *n = new Node(val);
		if (root == nullptr) root = n;
		else {
			Node* parrent = root;
			while (true) {
				if (n->value < parrent->value) {
					if (parrent->left == nullptr) {
						parrent->left = n;
						break;
					}
					else parrent = parrent->left;
				}
				else {
					if (parrent->right == nullptr) {
						parrent->right = n;
						break;
					}
					else parrent = parrent->right;
				}
			}
		}
	}
	void _show(Node* elem) {
		if (elem == nullptr) return;
		_show(elem->left);
		cout << elem->value << endl;
		_show(elem->right);
	}


	void show() {
		_show(root);
	}

};




int main() {

	Tree<int> tree;

	tree.insert(20);
	tree.insert(18);
	tree.insert(18);
	tree.insert(41);
	tree.insert(5);
	tree.insert(2);
	tree.insert(11);
	tree.insert(30);

	tree.show();

	getchar();
	




	return 0;
}
