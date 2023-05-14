#pragma once
#ifndef INT_SORTED_H
#define INT_SORTED_H

#include "buffer.h"

class int_sorted {
public:
	explicit int_sorted(const int* source, size_t size);
	size_t size() const;
	void insert(int value);
	const int* begin() const;
	const int* end() const;
	int_sorted merge(const int_sorted&merge_with) const;
	int_sorted sort(const int* begin, const int* end);

private:
	int_buffer buffer;
};


#endif // !INT_SORTED_H

