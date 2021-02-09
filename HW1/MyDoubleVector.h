#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

class MyDoubleVector {
public:

	// pre: x
	// post: private member �ʱ�ȭ
	MyDoubleVector();

	// pre: const MyDoubleVector ��ü
	// post: ���� �����ڸ� ���� ���� ����(deep copy)�� �Ѵ�.
	MyDoubleVector(const MyDoubleVector& v);

	// pre: x
	// post: ��뷮�� 0 ���� �����ϰ� data �� delete �� �޸𸮸� �����Ѵ�.
	~MyDoubleVector();

	// pre: const MyDoubleVector& ��ü
	// post: member �� ���ڷ� ���� ���� ������ �ʱ�ȭ�Ѵ�.
	void operator=(const MyDoubleVector &source);

	// pre: const MyDoubleVector& ��ü
	// post: RHS �� LHS �� �߰��Ѵ�.
	void operator+=(const MyDoubleVector& add);

	// pre: position >0 �̰� position< used �̾�� �Ѵ�. �׷��� ������ ����
	// post: position ��° ���Ҹ� �����ָ� double& ���� �����Ѵ�.
	double& operator[](const int position);

	// pre: const MyDoubleVector& ��ü�� ������ size �� ���ƾ� �Ѵ�. �׷��� ������ ����
	// post: �� ���Ҹ� ���� MyDoubleVecotr ������ �����Ѵ�.
	MyDoubleVector operator+(const MyDoubleVector& v1);

	// pre: const MyDoubleVector& ��ü�� ������ size �� ���ƾ� �Ѵ�. �׷��� ������ ����
	// post: �� ���Ҹ� �� MyDoubleVecotr ������ �����Ѵ�.
	MyDoubleVector operator-(const MyDoubleVector& v2);

	// pre: const MyDoubleVector& ��ü�� ������ size �� ���ƾ� �Ѵ�. �׷��� ������ ����
	// post: �� ���Ҹ� ���� MyDoubleVecotr ������ �����Ѵ�.
	MyDoubleVector operator*(const MyDoubleVector& v3);

	// pre: x
	// post: �� ���ҿ� -1 �� ���� MyDoubleVector ������ �����Ѵ�.
	MyDoubleVector operator-();

	// pre: const MyDoubleVector& ��ü�� ������ size �� ���ƾ� �Ѵ�. �׷��� ������ ����
	// post: �� ������ ���Ҹ� ��� ������ true ��, �׷��� ������ false �� �����Ѵ�.
	bool operator==(const MyDoubleVector& v5);

	// pre: double�� value �� ���� �޾ƾ� �Ѵ�.
	// post: ��� ���Ҹ� value ������ �����Ѵ�.
	void operator()(double value);

	// pre: x
	// post: used �� 1 ���� ���� ������ ���Ҹ� �����Ѵ�.
	void pop_back();

	// pre: ���� ���� ������ double�� x �� ���ڷ� ���� �޴´�.
	// post: ������ used �� �� á�ٸ� capacity �� �ø���, ������ ���� ���� x �� �����Ѵ�. 
	void push_back(double x);

	// pre: x
	// post: ������ capacity �� ��ȯ�Ѵ�.
	size_t capcacity() const {

		return capacity;
	};

	// pre: x
	// post: ������ size �� ��ȯ�Ѵ�.
	size_t size() const {

		return used;
	};

	// pre: ���Ӱ� ������ capacity �� size_t Ÿ������ ���ڷ� ���� �޴´�.
	// post: used �� capacity �� ���ٸ� ���� ���͸� ����, used �� �� ũ�ٸ� ũ�⸦ Ű�� ���͸� �Ҵ��ϰ�, data �� ���� �����Ѵ�. 
	// ���� ���͸� �����ϰ� ���� �̸��� ���͸� ����� ũ�⸦ Ű�� ���͸� copy constructor�� ������ ������� �����Ѵ�.
	void reverse(size_t new_capacity);

	// pre: x			
	// post: ���Ͱ� ��������� true, �ƴϸ� false �� �����Ѵ�.
	bool empty() const;

	// pre: x
	// post: used=0 ���� �����ϰ� data �� ������ ��, ���ο� ���͸� �Ҵ��Ѵ�.
	void clear();


private:
	size_t capacity;
	size_t used;
	double *data;

};