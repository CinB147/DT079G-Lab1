//Merge DT079G Programmertingsmetodik
//Alice Wijitchakhorn
//buffer.h (create: 16/11/22) (Lastest: 16/11/22)
//something something something sweet



#ifndef BUFFER_H
#define BUFFER_H

#include <cstdlib>

class int_buffer {
public:

	/// <summary>
	/// construct where this->first is a ptr that create new int[size] on first elements (create new arr[])
	/// this->last is last elememt of arr
	/// </summary>
	/// <param name="size">size of int bufffer</param>
	int_buffer(size_t size); // size_t is defined in cstdlib

	/// <summary>
	/// copy-ish contruct that 'copy' an existed array. Inizialize the source ranged in this case it's int_buffer(size)
	/// using std::copy from algorithm liabrary.
	/// std::copy( begin.source , end.source , result) - copy in range of source from begin to end 
	/// </summary>
	/// <param name="source"> const source from self (construct) </param>
	/// <param name="size">size of source arr[]</param>
	int_buffer(const int* source, size_t size);

	/// <summary>
	/// Copy contruct 
	/// </summary>
	/// <param name="rhs"> ref rhs of int_buffer </param>
	int_buffer(const int_buffer& rhs);//copy

	/// <summary>
	/// 
	/// </summary>
	/// <param name="rhs"></param>
	int_buffer(int_buffer&& rhs); //move

	/// <summary>
	/// 
	/// </summary>
	/// <param name="rhs"></param>
	/// <returns></returns>
	int_buffer& operator =(const int_buffer& rhs); // copy assign
	int_buffer& operator =(int_buffer&& rhs);// move assign
	int& operator [](size_t index);
	const int& operator [](size_t index) const;
	size_t size() const;
	int* begin();
	int* end();
	const int* begin() const;
	const int* end() const;

	~int_buffer();
private:
	void swap(int_buffer& rhs);
	int* buffer_first;
	int* buffer_last;

};
	



#endif // !1

