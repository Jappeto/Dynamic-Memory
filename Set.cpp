// Set.cpp
// Jacob Reppeto

#include "Set.hpp"

Set::Set() {
	_count = 0;
	_capacity = 8;
	_values = new int[_capacity];
}

Set::~Set() {
	delete[] _values;
}

Set::Set(const Set& set) {
	// copy constructor
	_copy(set);
}

void Set::resize(size_t newCapacity) {
	// allocate a new array with the new capacity
	int* temp;

	size_t i;
   _capacity = newCapacity; 
   temp = new int[_capacity];
   // copy the old values into the new array
   for (i = 0; i < _count; ++i) {  
       temp[i] = _values[i];  
   } 
   // delete the old array and point to the new one
   delete[] _values;  
   _values = temp;  
}

void Set::_copy(const Set& set) {
	// Sets the count to be the same
	_count = set._count;
	// Sets the capacity to be the same.
	_capacity = set._capacity;
	// Allocates a new array with the same capacity.
	_values = new int[_capacity];
	// Sets the values to be the same.
	for (size_t i = 0; i < set._count; ++i) {
		_values[i] = set._values[i];
	}

}

bool Set::insert(int x) {
	// Check if the value is already in the set.
	if (contains(x)) {
		return false;
	}
	// If the set is full, resize it to double its current capacity.
	if (_count == _capacity) {
		resize(2 * _capacity);
	}
	// Insert the new value into the set.
	_values[_count++] = x;
	return true;
}

bool Set::remove(int  x) {
	// Check if the value is in the set.
	for (int i = 0; i < _count; i++) {
		// If the value is found, remove it by replacing it with the last element.
		if (_values[i] == x) {
			_values[i] = _values[--_count];
			return true;
		}
	}
	return false;
}

bool Set::contains(int x) const {
	// Check if the value is in the set.
	for (int i = 0; i < _count; ++i) {
		if (_values[i] == x){
			return true;
		}
	}
	return false;
}

size_t Set::count() const {
	return _count;
}

size_t Set::capacity() const {
	return _capacity;
}

Set Set::intersect(const Set& set) const {  
   Set result;  
   for (int i = 0; i < _count; ++i) { 
	   // Check if the current value is in the other set.
       if (set.contains(_values[i])) {  
		   // If it is, insert it into the result set.
           result.insert(_values[i]);  
       }  
   }  
   return result;  
}  

Set operator-(const Set& lhs, const Set& rhs) {
	Set result;
	for (int i = 0; i < lhs._count; ++i) {
		// Check if the current value is not in the right-hand set.
		if (!rhs.contains(lhs._values[i])) {
			// If it is not, insert it into the result set.
			result.insert(lhs._values[i]);
		}
	}
	return result;
}

Set operator+(const Set& lhs, const Set& rhs) {
	Set result;
	// Add all elements from the left-hand set.
	for (int i = 0; i < lhs._count; ++i) {
		result.insert(lhs._values[i]);
	}
	// Add elements from the right-hand set that are not already in the result.
	for (int i = 0; i < rhs._count; ++i) {
		if (!result.contains(rhs._values[i])) {
			result.insert(rhs._values[i]);
		}
	}
	return result;
}

Set& Set::operator=(const Set& set) {
	if (&set != this) {
		//dealocate existing dynamic array
		delete[] _values;
		// copy values
		_copy(set);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Set& s) {
	// if the set is empty, output an empty set.
	if (s._count == 0) {
		return os << "{ }";
	}
	os << "{ ";
	// Output all elements in the set, separated by commas.
	for (int i = 0; i < s._count; ++i) {
		os << s._values[i];
		// If not the last element, add a comma and space.
		if (i < s._count - 1) {
			os << ", ";
		}
	}
	os << " }";
	return os;
}