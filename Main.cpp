#include <iostream>
#include "buffer.h"
#include "int_sorted.h"
#include <algorithm>
#include <chrono>
#include <ctime>


void f(int_buffer buf);
void fa(int_buffer buf);
bool is_sort(int_sorted& value); 
void select_sort(int* begin, int* end);

void pause();

int main() {
	//--------------------------------------------------------------------//
	f(10);
	std::cout << "--------\n";
	pause();
	fa(10);
	std::cout << "--------\n";
	pause();
	//-------------------------------------------------------------------//
	int_sorted is(nullptr,0);
	for (int i = 0; i < 100; i++) {
		is.insert(rand()%999+1);
	}
	is_sort(is);
	std::cout << "--------\n";
	pause();

	//--------------------------------------------------------------------//
	int rand_num = 40000;
	int_buffer buf(rand_num);
	for (auto& e : buf) {
		e = rand() % 399999 + 1;
	}
	int_buffer buf_sort = buf;
	int_sorted buffer(buf.begin(), buf.size());
	int_sorted buffer2 = buffer;
	std::cout << "Sorting 400000 elements using sort..." << std::endl;

	auto start_a = std::chrono::high_resolution_clock::now();
	int_sorted sortedBuffer = buffer.sort(buffer.begin(), buffer.end());
	auto stop_a = std::chrono::high_resolution_clock::now();
	auto mergeSortTime_a = std::chrono::duration<double>(stop_a - start_a);
	/*for (auto& e : sortedBuffer) {
		std::cout << e << " \n";
	}*/
	std::cout << std::endl << "Estimated time: " << mergeSortTime_a.count() << " s" << std::endl;
	pause();

	//-----------------------------------------------------------------//
	std::cout << "Sorting 400000 elements using std::sort..." << std::endl;
	auto start_b = std::chrono::high_resolution_clock::now();
	std::sort(buf.begin(), buf.end());
	auto stop_b = std::chrono::high_resolution_clock::now();
	auto mergeSortTime_b = std::chrono::duration<double>(stop_b - start_b);
	/*for (auto& e : sortedBuffer) {
		std::cout << e << " \n";
	}*/
	std::cout << std::endl << "Estimated time: " << mergeSortTime_b.count() << " s" << std::endl;
	pause();

	//------------------------------------------------------------------//

	std::cout << "Sorting 400000 elements using selection sort..." << std::endl;
	auto start_c = std::chrono::high_resolution_clock::now();
	select_sort(buf_sort.begin(), buf_sort.end());
	auto stop_c = std::chrono::high_resolution_clock::now();
	auto mergeSortTime_c = std::chrono::duration<double>(stop_c - start_c);
	/*for (auto& e : sortedBuffer) {
		std::cout << e << " \n";
	}*/
	std::cout << std::endl << "Estimated time: " << mergeSortTime_c.count() << " s" << std::endl;
	pause();


	return 0;
}

void f(int_buffer buf) {
	
	int value = 1;
	for (int* i = buf.begin(); i != buf.end(); i++){
		*i = value++;
	}

	for (const int* i = buf.begin(); i != buf.end(); i++){
		std::cout << *i << '\n';
	}
}


void fa(int_buffer buf) {
	auto start = 1;
	for (auto& e : buf) {
		e = start++;
	}
	for (auto& e : buf) {
		std::cout << e << "\n";
	}
}


bool is_sort(int_sorted& value) {
	const int* first = value.begin();
	const int* next = value.begin() + 1;
	while (first != value.end() - 1) {
		next = first + 1;
		if (*first > *next) {
			std::cout << "Not sorted!\n";
			return false;
		}
		else  
			first = next; 
	}
	std::cout << "Sorted!!\n";
	return true;

}

void select_sort(int* begin, int* end) {

	for (int* ptr = begin; ptr != end - 1; ptr++)
	{
		int* low_ptr = ptr;

		for (int* jt = ptr + 1; jt != end; jt++)
		{
			if (*jt < *low_ptr) low_ptr = jt;
		}

		std::swap(*ptr, *low_ptr);
	}

}


void pause() {
	std::cout << "Press ENTER to resume";
	std::cin.get();
}
