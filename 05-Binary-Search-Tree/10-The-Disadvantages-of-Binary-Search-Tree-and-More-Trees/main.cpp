#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "BST.h"
#include "SequenceST.h"
#include "FileOps.h"

using namespace std;

int main() {
	// 使用文本量更小的共产主义宣言进行试验:)
	string filename = "communist.txt";
	vector<string> words;
	if (FileOps::readFile(filename, words)) {
		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;

		// 测试1,我们按照文本原有顺序插入进BST
		time_t startTime = clock();
		// 统计共产主义宣言中所有词的词频
		// 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
		// 在这里只做性能测试用
		BST<string, int> *bst = new BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = (*bst).search(*iter);
			if (res == NULL)
				(*bst).insert(*iter, 1);
			else
				(*res)++;
		}
		// 输出共产主义宣言中的 unite 一词出现的频率
		if ((*bst).contain("unite"))
			cout << "'unite' : " << *(*bst).search("unite") << endl;
		else
			cout << "No word 'unite' in " << filename << endl;
		time_t endTime = clock();
		cout << "BST, time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete bst;

		// 测试2，我们按照文本原有顺序插入进顺序查找表 SST
		startTime = clock();

		// 统计共产主义宣言中所有词的词频
		// 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
		// 在这里只做性能测试用
		SequenceST<string, int> sst = SequenceST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = sst.search(*iter);
			if (res == NULL)
				sst.insert(*iter, 1);
			else
				(*res)++;
		}
		// 我们查看 unite 一词的词频
		if (sst.contain("unite"))
			cout << "'unite' : " << *sst.search("unite") << endl;
		else
			cout << "No word 'unite' in " << filename << endl;
		endTime = clock();
		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;
	
		// 测试3，我们将原文本排序后插入BST，查看其效率
		startTime = clock();
		BST<string, int> *bst2 = new BST<string, int>();
		sort(words.begin(), words.end());
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = (*bst2).search(*iter);
			if (res == NULL)
				(*bst2).insert(*iter, 1);
			else
				(*res)++;
		}
		// 我们查看unite一词的词频
		cout << "'unite' : " << *(*bst2).search("unite") << endl;
		endTime = clock();

		cout << "BST2 , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete bst2;
	}

	return 0;
}