// Set.hpp
// Jacob Reppeto


#ifndef SET_HPP
#define SET_HPP

#include <ostream>

class Set {
	friend std::ostream& operator<<(std::ostream& os, const Set& s);

public:
	/// default constructor
    Set();

	/// destructor
	~Set();

	/// copy constructor
	/// - Parameter set: set to copy
	Set(const Set& set);

    /// inserts x into set; returns true if newly inserted or false if x already in set
    /// - Parameter x: value to insert
    bool insert(int x);

    /// removes x from Set; returns true if x was in the Set or false if it was not
    /// - Parameter x: value to remove
    bool remove(int x);

    /// returns true if x is in the Set or false if it was not
    /// - Parameter x: value to check if in set
    bool contains(int x) const;

    /// number of elements in the set
    size_t count() const;

    // checking to see if capacity updates like supposted to.
    size_t capacity() const;

    /// returns a new set that is the intersection of the two sets
    /// - Parameter set: other set to intersect with this Set
    Set intersect(const Set& set) const;

    /// returrns a new Set that is the union of lhs and rhs
    /// - Parameters:
    ///   - lhs: left operand for union
    ///   - rhs: right operand for union
    
    friend Set operator-(const Set& lhs, const Set& rhs);

    /// returns a new Set that is the set difference of lhs and rhs (elements in lhs that are not in rhs)
    /// - Parameters:
    ///   - lhs: left operand for Set difference
    ///   - rhs: right operand for Set difference

    friend Set operator+(const Set& lhs, const Set& rhs);

	/// copy constructor
	/// - Parameter set: set to copy
	/// - Returns: a new Set that is a copy of the set
    Set& operator=(const Set& set);
    


private:
    
	/// resizes the internal array to the new capacity
    void resize(size_t newCapacity);
	/// copies the values from the given set to this set
    void _copy(const Set& set);

    int* _values;
    size_t _count;
	size_t _capacity;

};

/// output operator for set outputs of form: { 2, 4, 3 } (for empty leave one space between { })
 /// - Parameters:
 ///   - os: stream to output to
 ///   - s: set to output
std::ostream& operator<<(std::ostream& os, const Set& s);

#endif /* SET_HPP */