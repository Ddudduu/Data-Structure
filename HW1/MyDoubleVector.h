#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

class MyDoubleVector {
public:

	// pre: x
	// post: private member 초기화
	MyDoubleVector();

	// pre: const MyDoubleVector 객체
	// post: 복사 생성자를 통한 깊은 복사(deep copy)를 한다.
	MyDoubleVector(const MyDoubleVector& v);

	// pre: x
	// post: 사용량을 0 으로 설정하고 data 를 delete 해 메모리를 해제한다.
	~MyDoubleVector();

	// pre: const MyDoubleVector& 객체
	// post: member 를 인자로 전달 받은 것으로 초기화한다.
	void operator=(const MyDoubleVector &source);

	// pre: const MyDoubleVector& 객체
	// post: RHS 를 LHS 에 추가한다.
	void operator+=(const MyDoubleVector& add);

	// pre: position >0 이고 position< used 이어야 한다. 그렇지 않으면 종료
	// post: position 번째 원소를 보여주며 double& 으로 리턴한다.
	double& operator[](const int position);

	// pre: const MyDoubleVector& 객체를 받으며 size 가 같아야 한다. 그렇지 않으면 종료
	// post: 각 원소를 더해 MyDoubleVecotr 형으로 리턴한다.
	MyDoubleVector operator+(const MyDoubleVector& v1);

	// pre: const MyDoubleVector& 객체를 받으며 size 가 같아야 한다. 그렇지 않으면 종료
	// post: 각 원소를 빼 MyDoubleVecotr 형으로 리턴한다.
	MyDoubleVector operator-(const MyDoubleVector& v2);

	// pre: const MyDoubleVector& 객체를 받으며 size 가 같아야 한다. 그렇지 않으면 종료
	// post: 각 원소를 곱해 MyDoubleVecotr 형으로 리턴한다.
	MyDoubleVector operator*(const MyDoubleVector& v3);

	// pre: x
	// post: 각 원소에 -1 을 곱해 MyDoubleVector 형으로 리턴한다.
	MyDoubleVector operator-();

	// pre: const MyDoubleVector& 객체를 받으며 size 가 같아야 한다. 그렇지 않으면 종료
	// post: 두 벡터의 원소를 모두 같으면 true 를, 그렇지 않으면 false 를 리턴한다.
	bool operator==(const MyDoubleVector& v5);

	// pre: double형 value 를 전달 받아야 한다.
	// post: 모든 원소를 value 값으로 저장한다.
	void operator()(double value);

	// pre: x
	// post: used 를 1 감소 시켜 마지막 원소를 삭제한다.
	void pop_back();

	// pre: 벡터 끝에 저장할 double형 x 를 인자로 전달 받는다.
	// post: 벡터의 used 가 꽉 찼다면 capacity 를 늘리고, 벡터의 가장 끝에 x 를 저장한다. 
	void push_back(double x);

	// pre: x
	// post: 벡터의 capacity 를 반환한다.
	size_t capcacity() const {

		return capacity;
	};

	// pre: x
	// post: 벡터의 size 를 반환한다.
	size_t size() const {

		return used;
	};

	// pre: 새롭게 정의할 capacity 를 size_t 타입으로 인자로 전달 받는다.
	// post: used 와 capacity 가 같다면 현재 벡터를 리턴, used 가 더 크다면 크기를 키워 벡터를 할당하고, data 의 값을 복사한다. 
	// 원래 벡터를 삭제하고 같은 이름의 벡터를 만들어 크기를 키운 벡터를 copy constructor와 동일한 방식으로 저장한다.
	void reverse(size_t new_capacity);

	// pre: x			
	// post: 벡터가 비어있으면 true, 아니면 false 를 리턴한다.
	bool empty() const;

	// pre: x
	// post: used=0 으로 설정하고 data 를 삭제한 후, 새로운 벡터를 할당한다.
	void clear();


private:
	size_t capacity;
	size_t used;
	double *data;

};