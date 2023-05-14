//Merge DT079G Programmertingsmetodik
//Alice Wijitchakhorn
//buffer.cpp (create: 16/11/22) (Lastest: 16/11/22)
//implementation for int_bufffer class

#include "buffer.h"
#include <iostream>
#include <algorithm>



int_buffer::int_buffer(size_t size) :buffer_first(new int[size]), buffer_last(buffer_first + size) { 
	//std::cerr << "Con \n";
}

int_buffer::int_buffer(const int* source, size_t size) :int_buffer(size){
	std::copy(source, source + size, buffer_first);
}

int_buffer::int_buffer(const int_buffer& rhs) :int_buffer(rhs.buffer_first, rhs.size()) {

}

int_buffer::int_buffer(int_buffer&& rhs) :buffer_first(nullptr), buffer_last(nullptr) {
	swap(rhs);
}

int_buffer& int_buffer::operator =(const int_buffer& rhs) {
	int_buffer copy(rhs);
	swap(copy);

	return *this;
}

int_buffer& int_buffer::operator =(int_buffer&& rhs) {

	swap(rhs);
	return *this;
}

int& int_buffer::operator [](size_t index) {

	return *(buffer_first + index);
}

const int& int_buffer::operator [](size_t index) const {

	return *(buffer_first + index);
}

size_t int_buffer::size() const {

	return std::distance(buffer_first, buffer_last);
}

int* int_buffer::begin() {

	return buffer_first;
}

int* int_buffer::end() {

	return buffer_last;
}

const int* int_buffer::begin() const {

	return buffer_first;
}

const int* int_buffer::end() const {

	return buffer_last;
}

void int_buffer::swap(int_buffer& rhs) {
	std::swap(buffer_first, rhs.buffer_first);
	std::swap(buffer_last, rhs.buffer_last);
}

int_buffer::~int_buffer() {
	//std::cerr << "Des \n";
	delete[] buffer_first;
}