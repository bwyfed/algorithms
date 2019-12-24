#pragma once
#include <iostream>
#include <cassert>

using namespace std;

// ˳����ұ�
template<typename Key, typename Value>
class SequenceST
{
private:
	// ˳����ұ�Ľڵ�Ϊ˽�еĽṹ�壬��粻��Ҫ�˽�˳����ұ��нڵ�ľ���ʵ��
	// ���ǵ�˳����ұ��ڲ���������һ������
	struct Node
	{
		Key key;
		Value value;
		Node *next;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->next = NULL;
		}
	};
	Node* head; // ��ͷ
	int count; // ˳����ұ��еĽڵ����
public:
	SequenceST() {
		head = NULL;
		count = 0;
	}
	~SequenceST() {
		while (head != NULL) {
			Node *node = head;
			head = head->next;
			delete node;
			count--;
		}
		assert(head == NULL && count == 0);
	}
	// ����˳����ұ��еĽڵ����
	int size() {
		return count;
	}
	// ����˳����ұ��Ƿ�Ϊ��
	bool isEmpty() {
		return count == 0;
	}
	// ��˳����ұ��в���һ���µ�(key, value)���ݶ�
	void insert(Key key, Value value) {
		// ����һ������˳����Ƿ����ͬ����С��key
		Node *node = head;
		while (node != NULL) {
			// ����˳������ҵ���ͬ����Сkey�Ľڵ�
			// ��ǰ�ڵ㲻��Ҫ���룬����key����Ӧ��ֵ����Ϊvalue�󷵻�
			if (key == node->key) {
				node->value = value;
				return;
			}
			node = node->next;
		}
		// ��˳�����û��ͬ����С��key���򴴽��µĽڵ㣬���½ڵ�ֱ�Ӳ��ڱ�ͷ
		Node *newNode = new Node(key, value);
		newNode->next = head;
		head = newNode;
		count++;
	}
	// �鿴˳����ұ����Ƿ������ֵΪkey�Ľڵ�
	bool contain(Key key) {
		Node *node = head;
		while (node != NULL) {
			if (key == node->key)
				return true;
			node = node->next;
		}
		return false;
	}
	// ��˳����ұ��в���key����Ӧ��value����value�����ڣ��򷵻�NULL
	Value* search(Key key) {
		Node *node = head;
		while (node != NULL) {
			if (key == node->key)
				return &(node->value);
			node = node->next;
		}
		return NULL;
	}
	// ��˳����ұ���ɾ��(key, value)����Ӧ�Ľڵ�
	void remove(Key key) {
		if (head == NULL)
			return;
		// �����ɾ���Ľڵ���ͷ�ڵ㣬����Ҫ���⴦��
		if (key == head->key) {
			Node *delNode = head;
			head = head->next;
			delete delNode;
			count--;
			return;
		}

		Node *node = head;
		while (node->next != NULL && node->next->key != key)
			node = node->next;

		if (node->next != NULL) {
			Node* delNode = node->next;
			node->next = delNode->next;
			delete delNode;
			count--;
			return;
		}
	}

};