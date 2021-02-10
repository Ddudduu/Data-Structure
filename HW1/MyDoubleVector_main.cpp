#include "MyDoubleVector.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {

	MyDoubleVector vec1, vec2, vec4;
	double input = 0;

	cout << "vec1 의 원소 3가지 입력: " << endl << endl;
	for (int i = 0; i < 3; i++) {
		cin >> input;
		vec1.push_back(input);
		input = 0;
	}


	cout << "vec1 원소: " << endl;
	for (int i = 0; i < vec1.size(); i++) {
		cout << vec1[i] << " ";
	}
	cout << endl << endl;

	MyDoubleVector vec3(vec1);
	cout << " vec3(vec1)" << endl;
	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3[i] << " ";
	}
	cout << endl << endl;

	vec2 = vec1;
	cout << " vec2 = vec1 " << endl;
	for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i] << " ";
	}
	cout << endl << endl;

	vec1 += vec2;
	cout << " vec1 += vec2 " << endl;
	for (int i = 0; i < vec1.size(); i++) {
		cout << vec1[i] << " ";
	}
	cout << endl << endl;

	cout << " vec1 의 2번째 원소: " << vec1[1] << endl << endl;

	vec4.push_back(21);
	vec4.push_back(358);
	vec4.push_back(3.14);


	cout << " vec4 의 원소: " << endl;
	for (int i = 0; i < vec4.size(); i++) {
		cout << vec4[i] << " ";
	}
	cout << endl << endl;

	cout << " vec2+vec4 " << endl;
	for (int i = 0; i < (vec2 + vec4).size(); i++) {
		cout << (vec4 + vec2)[i] << " ";
	}
	cout << endl << endl;

	cout << " vec3-vec2 " << endl;
	for (int i = 0; i < (vec3 + vec2).size(); i++) {
		cout << (vec3 - vec2)[i] << " ";
	}
	cout << endl << endl;

	cout << " vec3*vec2 " << endl;
	for (int i = 0; i < (vec3*vec2).size(); i++) {
		cout << ((vec3)*(vec2))[i] << " ";
	}
	cout << endl << endl;

	cout << " - vec2 " << endl;
	for (int i = 0; i < (vec2).size(); i++) {
		cout << (-vec2)[i] << " ";
	}

	cout << endl << endl;

	cout << " vec2 과 vec3 비교: " << ((vec2 == vec3) ? "같음" : "다름") << endl << endl;
	cout << " ve2 과 vec4 비교: " << ((vec2 == vec4) ? "같음" : "다름") << endl << endl;

	vec2(10);
	cout << " vec2(10) 의 결과: " << endl;
	for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i] << " ";
	}
	cout << endl << endl;

	vec1.pop_back();
	cout << "vec1.pop_back() 의 결과: " << endl;
	for (int i = 0; i < vec1.size(); i++) {
		cout << vec1[i] << " ";
	}
	cout << endl;

	cout << "vec1 의 용량은 " << vec1.capcacity() << "입니다" << endl << endl;
	cout << "vec1 의 사용량은 " << vec1.size() << "입니다" << endl << endl;

	vec1.reverse(150);

	cout << "vec1.reverse(150) 실행 후 용량은 " << vec1.capcacity() << "입니다" << endl << endl;

	cout << "vec1 의 empyt 여부를 판정하여라: " << (vec1.empty() ? "참" : "거짓") << endl << endl;
	vec1.clear();
	cout << "clear() 후, vec1 의 empyt 여부를 판정하여라: " << (vec1.empty() ? "참" : "거짓") << endl << endl;

	return 0;
}