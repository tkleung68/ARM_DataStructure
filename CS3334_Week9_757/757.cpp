#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct combine {
	int key;
	int info;

	combine(int key, int info) :key(key), info(info) {}
	combine() {}
};

struct compare {
	bool operator()(combine a, combine b) {
		return a.key > b.key;
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////

priority_queue<combine, vector<combine>, compare> minHeap;
combine a, b;

int calculate() {
	int tree_A, tree_B, Key_A, Key_B, tree, temp;
	while (minHeap.size() > 1) {

		a = minHeap.top();
		minHeap.pop();
		b = minHeap.top();
		minHeap.pop();

		tree_A = a.info;
		tree_B = b.info;

		Key_A = a.key;
		Key_B = b.key;

		temp = Key_A + Key_B;
		tree = tree_A + tree_B + temp;

		combine key = combine(temp, tree);
		minHeap.push(key);
	}
	return minHeap.top().info;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int testcase;
	
	while (cin >> testcase){

		int freq;
		for (int i = 0; i < testcase; i++){
			cin >> freq;
			combine key = combine(freq, 0);
			minHeap.push(key);
		}

		cout << calculate() << endl;
		minHeap.pop();

	}

	return 0;
}
