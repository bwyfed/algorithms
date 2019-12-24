#include <iostream>
#include <queue>

using namespace std;

template<typename Key, typename Value>
class BST {
private:
	struct Node
	{
		Key key;
		Value value;
		Node *left;
		Node *right;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};
	Node *root;
	int count; // BST�ж��ٸ����
public:
	BST() {
		root = NULL;
		count = 0;
	}
	~BST() {
		// TODO: ~BST()
		destroy(root);
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		return count == 0;
	}

	void insert(Key key, Value value) {
		root = insert(root, key, value);
	}

	bool contain(Key key) {
		return contain(root, key);
	}
	Value* search(Key key) {
		return search(root, key);
	}
	// ǰ�����
	void preOrder() {
		preOrder(root);
	}
	// �������
	void inOrder() {
		inOrder(root);
	}
	// ��������
	void postOrder() {
		postOrder(root);
	}
	// �������
	void levelOrder() {
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node *node = q.front();
			q.pop();
			cout << node->key << endl;
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}
private:
	// ����nodeΪ���Ķ����������У�������(key, value)
	// ���ز����½���Ķ����������ĸ�
	Node* insert(Node *node, Key key, Value value) {
		if (node == NULL) {
			count++;
			return new Node(key, value);
		}
		if (key == node->key)
			node->value = value;
		else if (key < node->key)
			node->left = insert(node->left, key, value);
		else // key > node->key
			node->right = insert(node->right, key, value);
		return node;
	}
	// �鿴��nodeΪ���Ķ������������Ƿ������ֵΪkey�Ľڵ�
	bool contain(Node *node, Key key) {
		if (node == NULL)
			return false;

		if (key == node->key)
			return true;
		else if (key < node->key)
			return contain(node->left, key);
		else // key > node->key
			return contain(node->right, key);
	}
	// ����nodeΪ���Ķ����������в���key����Ӧ��value
	Value* search(Node* node, Key key) {
		if (node == NULL)
			return NULL;

		if (key == node->key)
			return &(node->value);
		else if (key < node->key)
			return search(node->left, key);
		else // key > node->key
			return search(node->right, key);
	}
	// ����nodeΪ���Ķ�������������ǰ�����
	void preOrder(Node* node) {
		if (node != NULL) {
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	// ����nodeΪ���Ķ��������������������
	void inOrder(Node *node) {
		if (node != NULL) {
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}
	// ����nodeΪ���Ķ������������к������
	void postOrder(Node *node) {
		if (node != NULL) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}
	// ����nodeΪ���Ķ��������������ͷſռ�
	void destroy(Node* node) {
		if (node != NULL) {
			destroy(node->left);
			destroy(node->right);
			delete node;
			count--;
		}
	}
};
int main() {
	return 0;
}