#include "MyDoubleVector.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {

	MyDoubleVector vec1, vec2, vec4;
	double input = 0;

	cout << "vec1 �� ���� 3���� �Է�: " << endl << endl;
	for (int i = 0; i < 3; i++) {
		cin >> input;
		vec1.push_back(input);
		input = 0;
	}


	cout << "vec1 ����: " << endl;
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

	cout << " vec1 �� 2��° ����: " << vec1[1] << endl << endl;

	vec4.push_back(21);
	vec4.push_back(358);
	vec4.push_back(3.14);


	cout << " vec4 �� ����: " << endl;
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

	cout << " vec2 �� vec3 ��: " << ((vec2 == vec3) ? "����" : "�ٸ�") << endl << endl;
	cout << " ve2 �� vec4 ��: " << ((vec2 == vec4) ? "����" : "�ٸ�") << endl << endl;

	vec2(10);
	cout << " vec2(10) �� ���: " << endl;
	for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i] << " ";
	}
	cout << endl << endl;

	vec1.pop_back();
	cout << "vec1.pop_back() �� ���: " << endl;
	for (int i = 0; i < vec1.size(); i++) {
		cout << vec1[i] << " ";
	}
	cout << endl;

	cout << "vec1 �� �뷮�� " << vec1.capcacity() << "�Դϴ�" << endl << endl;
	cout << "vec1 �� ��뷮�� " << vec1.size() << "�Դϴ�" << endl << endl;

	vec1.reverse(150);

	cout << "vec1.reverse(150) ���� �� �뷮�� " << vec1.capcacity() << "�Դϴ�" << endl << endl;

	cout << "vec1 �� empyt ���θ� �����Ͽ���: " << (vec1.empty() ? "��" : "����") << endl << endl;
	vec1.clear();
	cout << "clear() ��, vec1 �� empyt ���θ� �����Ͽ���: " << (vec1.empty() ? "��" : "����") << endl << endl;

	return 0;
}