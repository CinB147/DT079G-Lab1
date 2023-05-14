#include "int_sorted.h"
#include <cstdlib>
#include <iostream>

int_sorted::int_sorted(const int* source, size_t size) : buffer(source, size) {
    if (size > 1) {
        buffer = sort(source, source + size).buffer;
    }
}

size_t int_sorted::size() const {
    return buffer.size();

}

void int_sorted::insert(int value) {
    buffer = merge(int_sorted( & value, 1)).buffer;

}

const int* int_sorted::begin() const {
    return buffer.begin();

}

const int* int_sorted::end() const {
    return buffer.end();
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const {

    int_buffer c(size() + merge_with.size());
    const int* A_ptr = begin();
    const int* B_ptr = merge_with.begin();
    int a, b, num = 0;
    while (A_ptr != end() && B_ptr != merge_with.end()) {
        a = *A_ptr;
        b = *B_ptr;
        if (a < b) {
            c[num++] = *A_ptr;
            A_ptr++;
        }
        else {
            c[num++] = *B_ptr;
            B_ptr++;
        }
    }
    while (A_ptr != end()) {
        c[num++] = *A_ptr;
        a = *A_ptr++;
    }
    while (B_ptr != merge_with.end()) {
        c[num++] = *B_ptr;
        b = *B_ptr++;
    }
    int_sorted merg(nullptr, 0);
    merg.buffer = c;

    return merg;
}

int_sorted int_sorted::sort(const int* begin, const int* end) {
    if (begin == end) {
        return int_sorted(nullptr, 0);
    }
    if (begin == end - 1) {
        return int_sorted(begin, 1);
    }

    ptrdiff_t half = (end - begin) / 2; // pointer diff type
    const int* mid = begin + half;
    return  sort(begin, mid).merge(sort(mid, end));

}

