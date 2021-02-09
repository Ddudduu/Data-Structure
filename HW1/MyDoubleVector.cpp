#include "MyDoubleVector.h"
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>

MyDoubleVector::MyDoubleVector() {

	capacity = 100;
	used = 0;
	data = new double[capacity];
}


MyDoubleVector::MyDoubleVector(const MyDoubleVector& source) {
	data = new double[source.capacity];
	capacity = source.capacity;
	used = source.size();

	std::copy(source.data, source.data + used, data);
}


MyDoubleVector::~MyDoubleVector() {
	used = 0;
	delete[] data;
}

void MyDoubleVector::operator=(const MyDoubleVector &source) {
	if (this == &source)
		return;

	if (capacity != source.capacity) {

		delete[] data;
		data = new double[source.capacity];
		capacity = source.capacity;

	}

	used = source.size();
	std::copy(source.data, source.data + used, data);
}

void MyDoubleVector::operator+=(const MyDoubleVector& add) {
	assert(size() + add.size() <= capacity);

	std::copy(add.data, add.data + add.used, data + used);
	used += add.size();

}

double& MyDoubleVector::operator[](const int position) {
	if (position >= 0 || position < used)
		return data[position];

}

MyDoubleVector MyDoubleVector::operator+(const MyDoubleVector& v1) {

	assert(used == v1.size());

	MyDoubleVector answer = *this;

	for (int i = 0; i < used; i++) {
		answer[i] += v1.data[i];
	}

	return answer;
}

MyDoubleVector MyDoubleVector::operator-(const MyDoubleVector & v2)
{
	assert(used == v2.size());

	MyDoubleVector answer = *this;

	for (int i = 0; i < used; i++) {
		answer[i] -= v2.data[i];
	}

	return answer;
}

MyDoubleVector MyDoubleVector::operator*(const MyDoubleVector& v3) {

	assert(used == v3.size());

	MyDoubleVector answer = *this;

	for (int i = 0; i < used; i++) {
		answer[i] *= v3.data[i];
	}

	return answer;

}

MyDoubleVector MyDoubleVector::operator-() {

	MyDoubleVector answer = *this;

	for (int i = 0; i < used; i++) {
		answer[i] *= -1;
	}

	return answer;
}

bool MyDoubleVector::operator==(const MyDoubleVector& v5) {
	assert(used == v5.size());

	for (int i = 0; i < size(); i++) {
		for (int j = 0; v5.data[j] != data[i]; j++) {
			if (j == v5.size())
				return false;
		}
	}
	return true;


}

void MyDoubleVector::operator()(double value) {
	for (int i = 0; i < used; i++)
		data[i] = value;
}

void MyDoubleVector::pop_back() {
	--used;

}

void MyDoubleVector::push_back(double x) {
	if (used == capacity)
		reverse(used * 2);

	data[used] = x;
	++used;
}

void MyDoubleVector::reverse(size_t new_capacity) {
	double *larger_array;

	if (new_capacity == capacity)
		return;

	if (new_capacity < used)
		new_capacity = used;

	larger_array = new double[new_capacity];
	std::copy(data, data + used, larger_array);
	delete[] data;
	data = larger_array;
	capacity = new_capacity;
}

bool MyDoubleVector::empty() const {
	if (used == 0)
		return true;
	else
		return false;
}

void MyDoubleVector::clear() {
	used = 0;
	delete[] data;
	data = new double[capacity];
}



