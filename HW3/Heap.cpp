#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class heap {
public:
	vector<char>vec_heap;
	char V[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	char** H_tree;

	void print1(int index, int depth) {
		if (index < vec_heap.size()) {
			print1(index * 2 + 2, depth + 1);
			cout << setw(2 * depth) << "" << vec_heap[index] << endl;
			print1(index * 2 + 1, depth + 1);
		}
	}

	void print2() {
		int index = 0;
		int depth = (int)(log((vec_heap.size() - 1) + 1) / log(2.0)) + 1;

		for (int i = 0; i < depth; i++) {
			index = pow(2, i) - 1;

			for (int p = 0; p < pow(2, depth - 1 - i) - 1; p++)cout << " ";
			for (int j = 0; j < pow(2, i); j++) {
				cout << vec_heap[index + j];

				for (int p = 0; p < pow(2, depth - i) - 1; p++)cout << " ";

				if (index + j == vec_heap.size() - 1) {
					cout << endl << endl << endl << endl;
					return;
				}

				if ((i != depth - 1)) {
					if ((int)((index + j - 1) / 2) != (int)((index + j + 1 - 1) / 2))
						cout << " ";
					else
						cout << "\b";
				}
			}
			cout << endl << endl;
		}
	}

	void print3_recur(int index, int i, int j, int d, int U, int D, int R, int L)
	{
		if (index > vec_heap.size())
			return;
		H_tree[i][j] = vec_heap[index - 1];

		if (2 * index <= vec_heap.size()) {
			H_tree[i + d * V[L][0]][j + d * V[L][1]] = vec_heap[2 * index - 1];
			print3_recur(4 * index, i + d * (V[L][0] + V[U][0]),
				j + d * (V[L][1] + V[U][1]), d / 2, D, U, L, R);
			print3_recur(4 * index + 1, i + d * (V[L][0] + V[D][0]),
				j + d * (V[L][1] + V[D][1]), d / 2, U, D, R, L);
		}

		if (2 * index + 1 <= vec_heap.size()) {
			H_tree[i + d * V[R][0]][j + d * V[R][1]] = vec_heap[2 * index];
			print3_recur(4 * index + 2, i + d * (V[R][0] + V[D][0]),
				j + d * (V[R][1] + V[D][1]), d / 2, U, D, R, L);
			print3_recur(4 * index + 3, i + d * (V[R][0] + V[U][0]),
				j + d * (V[R][1] + V[U][1]), d / 2, D, U, L, R);
		}
	}
	void print3() {
		H_tree = new char*[vec_heap.size()];

		for (int k = 0; k < vec_heap.size(); k++) {
			H_tree[k] = new char[vec_heap.size()];
			memset(H_tree[k], ' ', sizeof(char) * vec_heap.size());
		}

		print3_recur(1, center(vec_heap.size()), center(vec_heap.size()), depth(vec_heap.size()), 0, 1, 2, 3);

		for (int k = 0; k < vec_heap.size(); k++) {
			for (int j = 0; j < vec_heap.size(); j++) {
				cout << H_tree[k][j] << " ";
			}
			cout << endl;
		}
	}
	int center(int n) { return n <= 1 ? 0 : 2 * center(n / 4) + 1; }
	int depth(int n) { return n <= 7 ? 1 : 2 * depth(n / 4); }
};


int main() {
	heap h;
	char* input = (char*)malloc(sizeof(char) * 10);
	char command;

	while (1) {
		cin >> input;

		if (!strcmp(input, "INS")) {
			cin >> command;
			h.vec_heap.push_back(command);
			push_heap(h.vec_heap.begin(), h.vec_heap.end());
			if (h.vec_heap.size() >= 200)
				break;
		}
		else if (!strcmp(input, "DEL")) {
			pop_heap(h.vec_heap.begin(), h.vec_heap.end());
			h.vec_heap.pop_back();
		}
		else if (!strcmp(input, "EOI")) {
			break;
		}

	}
	cout << endl << endl;

	cout << "1. rotated form" << endl;
	h.print1(0, 1);
	cout << endl << endl;

	cout << "2. not-rotated form" << endl;
	h.print2();
	cout << endl << endl;

	cout << "3. H-tree form" << endl;
	h.print3();
	cout << endl << endl;

}