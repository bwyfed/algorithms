#include <iostream>
#include <cassert>

using namespace std;

template<typename Item>
class IndexMaxHeap {
private:
	Item* data;
	int* indexes; // �µ�����洢����
	int count;
	int capacity;

	void shiftUp(int k) {
		while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
			swap(indexes[k / 2], indexes[k]);
			k /= 2;
		}
	}
	void shiftDown(int k) {
		while (2 * k <= count) {
			int j = 2 * k;
			if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
				j += 1;
			if (data[indexes[k]] >= data[indexes[j]])
				break;

			swap(indexes[k], indexes[j]);
			k = j;
		}
	}
public:
	IndexMaxHeap(int capacity) {
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	~IndexMaxHeap() {
		delete[] data;
		delete[] indexes;
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		return count == 0;
	}
	// �����i�����ڶ��ԣ��Ǵ�����0��ʼ��
	void insert(int i, Item item) {
		assert(count + 1 <= capacity);
		assert(i + 1 >= 1 && i + 1 <= capacity); // ���������Ĳ��죬��֤����λ�ò�Խ��

		i += 1; //�ڲ�ʹ������1��ʼ
		data[i] = item;
		indexes[count + 1] = i;
		count++;
		shiftUp(count);
	}
	Item extractMax() {
		assert(count > 0);
		Item ret = data[indexes[1]];

		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);
		return ret;
	}
	int extractMaxIndex() {
		assert(count > 0);
		int ret = indexes[1] - 0;

		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);
		return ret;
	}
	Item getItem(int i) {
		return data[i + 1];
	}
	void change(int i, Item newItem) {
		i += 1;
		data[i] = newItem;
		// �ҵ�indexes[j] = i��j��ʾdata[i]�ڶ��е�λ��
		for (int j = 1; j <= count; j++)
			if (indexes[j] == i) {
				shiftUp(j);
				shiftDown(j);
				return;
			}
	}
};

int main() {
	return 0;
}