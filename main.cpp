// main.cpp
// Jacob Reppeto

#include <iostream>
#include "Set.hpp"

using namespace std;

int main() {
    // Create empty sets for testing
    Set a, b, c;

    // Test 1: Insert into empty set
    cout << "\nTest 1: Insert into empty set" << endl;
    a.insert(5);
    cout << "\nSet A after inserting 5: " << a << endl; // Expected: { 5 }

    // Test 2: Insert duplicate value
    cout << "\nTest 2: Insert duplicate value" << endl;
    cout << "\nSet A: " << a << endl; // Expected: { 5 }

    // Test 3: Insert until resize (capacity doubles from 8)
    cout << "\nTest 3: Insert until resize" << endl;
    for (int i = 1; i <= 9; i++) {
        a.insert(i);
    }
    cout << "\nSet A after inserting 1 to 9: " << a << endl; // Expected: { 5, 1, 2, 3, 4, 6, 7, 8, 9 }
    cout << "\nCapacity after inserts: " << a.capacity() << endl; // Expected: 16

    // Test 4: Remove existing value
    cout << "\nTest 4: Remove existing value" << endl;
    bool rem = a.remove(5);
    cout << "\nRemoving 5: " << (rem ? "Removed" : "Not Found") << endl; // Expected: Removed
    cout << "\nSet A after removal: " << a << endl; // Expected: { 9, 1, 2, 3, 4, 6, 7, 8 }

    // Test 5: Remove non-existing value
    cout << "\nTest 5: Remove non-existing value" << endl;
    rem = a.remove(100);
    cout << "\nRemoving 100 (not in set): " << (rem ? "Removed" : "Not found") << endl; // Expected: Not found
    cout << "\nSet A: " << a << endl; // Expected: { 9, 1, 2, 3, 4, 6, 7, 8 }

    // Test 6: Empty set operations
    cout << "\nTest 6: Empty set operations" << endl;
    Set empty;
    cout << "\nEmpty set: " << empty << endl; // Expected: { }
    cout << "\nCount of empty set: " << empty.count() << endl; // Expected: 0
    cout << "\nUnion with empty: " << (a + empty) << endl; // Expected: { 9, 1, 2, 3, 4, 6, 7, 8 }
    cout << "\nIntersection with empty: " << a.intersect(empty) << endl; // Expected: { }
    cout << "\nDifference (A - empty): " << (a - empty) << endl; // Expected: { 9, 1, 2, 3, 4, 6, 7, 8 }
    cout << "\nDifference (empty - A): " << (empty - a) << endl; // Expected: { }

    // Test 7: Self-assignment
    cout << "\nTest 7: Self-assignment" << endl;
    a = a;
    cout << "\nSet A after self-assignment: " << a << endl; // Expected: { 9, 1, 2, 3, 4, 6, 7, 8 }

    // Test 8: Copy constructor with empty set
    cout << "\nTest 8: Copy constructor with empty set" << endl;
    Set emptyCopy = empty;
    cout << "\nCopied empty set: " << emptyCopy << endl; // Expected: { }

    // Test 9: Union of identical sets
    cout << "\nTest 9: Union of identical sets" << endl;
    b = a;
    c = a + b;
    cout << "\nUnion of A and B (identical): " << c << endl; // Expected: { 9, 1, 2, 3, 4, 6, 7, 8 }

    // Test 10: Intersection with no common elements
    cout << "\nTest 10: Intersection with no common elements" << endl;
    Set d;
    d.insert(10);
    d.insert(11);
    cout << "\nSet D: " << d << endl; // Expected: { 10, 11 }
    cout << "\nIntersection of A and D (no common elements): " << a.intersect(d) << endl; // Expected: { }

    // Test 11: Difference with identical sets
    cout << "\nTest 11: Difference with identical sets" << endl;
    cout << "\nDifference (A - A): " << (a - a) << endl; // Expected: { }

    // Test 12: Large number of insertions
    cout << "\nTest 12: Large number of insertions" << endl;
    Set large;
    for (int i = 0; i < 1000; i++) {
        large.insert(i);
    }
    cout << "\nLarge set count: " << large.count() << endl; // Expected: 1000
    cout << "\nLarge set capacity: " << large.capacity() << endl; // Expected: 1024

    // Test 13: Union with partial overlap
    cout << "\nTest 13: Union with partial overlap" << endl;
    Set e, f;
    e.insert(1);
    e.insert(2);
    e.insert(3);
    f.insert(2);
    f.insert(3);
    f.insert(4);
    cout << "\nSet E: " << e << endl; // Expected: { 1, 2, 3 }
    cout << "\nSet F: " << f << endl; // Expected: { 2, 3, 4 }
    cout << "\nUnion of E and F: " << (e + f) << endl; // Expected: { 1, 2, 3, 4 }

    // Test 14: Intersection with partial overlap
    cout << "\nTest 14: Intersection with partial overlap" << endl;
    cout << "\nSet E: " << e << endl; // Expected: { 1, 2, 3 }
    cout << "\nSet F: " << f << endl; // Expected: { 2, 3, 4 }
    cout << "\nIntersection of E and F: " << e.intersect(f) << endl; // Expected: { 2, 3 }

    // Test 15: Difference with partial overlap
    cout << "\nTest 15: Difference with partial overlap" << endl;
    cout << "\nSet E: " << e << endl; // Expected: { 1, 2, 3 }
    cout << "\nSet F: " << f << endl; // Expected: { 2, 3, 4 }
    cout << "\nDifference (E - F): " << (e - f) << endl; // Expected: { 1 }
    cout << "\nDifference (F - E): " << (f - e) << endl; // Expected: { 4 }

    return 0;
}