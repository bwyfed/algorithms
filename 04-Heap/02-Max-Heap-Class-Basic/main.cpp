#include <iostream>

using namespace std;

template<typename Item>
class MaxHeap {
private:
	Item *data;
	int count; // �����ж��ٸ�Ԫ��

public:
	// ���캯��, ����һ���ն�, ������capacity��Ԫ��
	MaxHeap(int capacity) {
		data = new Item[capacity + 1];
		count = 0;
	}
	~MaxHeap() {
		delete[] data;
	}
	// ���ض��е�Ԫ�ظ���
	int size() {
		return count;
	}
	// ����һ������ֵ, ��ʾ�����Ƿ�Ϊ��
	bool isEmpty() {
		return count == 0;
	}
};
int main() {
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout << maxheap.size() << endl;

	return 0;
}