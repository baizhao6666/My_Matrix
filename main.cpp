/**------------------------------------------
Test cases for Program 3: My Matrix
Course: CS 251, Spring 2023, UIC
System: CLion on MacOs
Author: Baizhao Zhao
-------------------------------------------*/

#include <iostream>
#include "mymatrix.h"

using namespace std;

/**
 * test for initial size
 * @return
 */
bool sizeTest1() {
    mymatrix<int> M;

    if (M.size() == 16) {
        return true;
    }
    return false;
}



/**
 * test for growing a colum to larger size
 * @return
 */
bool sizeTest2() {
    mymatrix<int> M;

    M.growcols(2, 8);

    if (M.size() == 20) {
        return true;
    }
    return false;
}

/**
 * test for growing the whole matrix to larger size
 * @return
 */
bool sizeTest3() {
    mymatrix<int> M;

    M.grow(6, 5);

    if (M.size() == 30) {
        return true;
    }
    return false;
}

/**
 * test for growing a colum to smaller size, which the size will remain
 * @return
 */
bool sizeTest4() {
    mymatrix<int> M;

    M.growcols(1, 2);

    if (M.size() == 16) {
        return true;
    }
    return false;
}

/**
 * test for growing the whole matrix to smaller size, which the size will remain
 * @return
 */
bool sizeTest5() {
    mymatrix<int> M;

    M.grow(3, 3);

    if (M.size() == 16) {
        return true;
    }
    return false;
}

/**
 * test for grow() function when the row argument is invalid
 * @return
 */
bool sizeTest6() {
    try {
        mymatrix<int> M;
        M.grow(0, 4);
    } catch (invalid_argument &exception) {
        return true;
    }
    return false;
}

/**
 * test for grow() function when the colum argument is invalid
 * @return
 */
bool sizeTest7() {
    try {
        mymatrix<int> M;
        M.grow(4, 0);
    } catch (invalid_argument &exception) {
        return true;
    }
    return false;
}

/**
 * test for growcols() function when the row argument is invalid
 * @return
 */
bool sizeTest8() {
    try {
        mymatrix<int> M;
        M.growcols(-1, 6);
    } catch (invalid_argument &exception) {
        return true;
    }
    return false;
}

/**
 * test for growcols() function when the row argument is invalid
 * @return
 */
bool sizeTest9() {
    try {
        mymatrix<int> M;
        M.growcols(5, 6);
    } catch (invalid_argument &exception) {
        return true;
    }
    return false;
}

/**
 * test for growcols() function when the col argument is invalid
 * @return
 */
bool sizeTest10() {
    try {
        mymatrix<int> M;
        M.growcols(1, 0);
    } catch (invalid_argument &exception) {
        return true;
    }
    return false;
}

/**
 * test for parameterized constructor
 * @return
 */
bool constructorTest1() {
    mymatrix<int> M1(5, 6);
    mymatrix<int> M2(8, 3);

    if (M1.size() == 30 && M2.size() == 24) {
        return true;
    }

    return false;
}

/**
 * test for copy constructor and operator()
 * @return
 */
bool constructorTest2() {
    mymatrix<int> M1;
    M1(0, 0) = 123;

    mymatrix<int> M2 = M1;

    if (M2.size() == M1.size() && M2(0, 0) == M1(0, 0)) {
        return true;
    }
    return false;
}

/**
 * test for copy constructor and growcols()
 * @return
 */
bool constructorTest3() {
    mymatrix<int> M1;
    M1.growcols(2, 6);

    mymatrix<int> M2(M1);

    if (M2.size() == M1.size()) {
        return true;
    }
    return false;
}

/**
 * test for parameterized constructor and numrows() function
 * @return
 */
bool constructorTest4() {
    mymatrix<int> M1(3, 8);
    bool initial = false;

    if (M1.size() == 24) {
        initial = true;
    }

    M1.growcols(2, 10);
    bool resize = false;

    if (M1.numcols(2) == 10) {
        resize = true;
    }

    return (initial && resize);
}

/**
 * test for at() function
 * @return
 */
bool atTest1() {
    mymatrix<int> M;
    M.at(2, 3) = 20;

    if (M(2, 3) == 20) {
        return true;
    }
    return false;
}

/**
 * test for at() function when arguments are invalid
 * @return
 */
bool atTest2() {
    try {
        mymatrix<int> M;
        M.at(5, 3) = 10;
    } catch (invalid_argument &exception) {
        return true;
    }
    return false;
}

bool atTest3() {
    try {
        mymatrix<int> M;
        M(2, 6) = 5;
    } catch (invalid_argument &exception) {
        return true;
    }
    return false;
}

/**
 * test for scalar multiplication, operator(), numrows(), numcols()
 * @return
 */
bool multiTest1() {
    mymatrix<int> M1;
    M1(0, 0) = 2;
    M1(1, 1) = 4;
    M1(2, 2) = 6;
    M1(3, 3) = 8;

    mymatrix<int> M2 = M1 * 2;

    for (int r = 0; r < M2.numrows(); ++r) {
        for (int c = 0; c < M2.numcols(r); ++c) {
            if (M2(r, c) != 2 * M1(r, c)) {
                return false;
            }
        }
    }

    return true;
}

/**
 * test for scalar multiplication, at(), numrows(), numcols(), copy constructor
 * @return
 */
bool multiTest2() {
    mymatrix<int> M1;
    M1.at(0, 0) = 7;
    M1.at(2, 1) = 2;
    M1.at(1, 3) = 9;
    M1.at(3, 2) = 5;

    mymatrix<int> M2(M1 * 2);

    for (int r = 0; r < M2.numrows(); ++r) {
        for (int c = 0; c < M2.numcols(r); ++c) {
            if (M2(r, c) != 2 * M1(r, c)) {
                return false;
            }
        }
    }

    return true;
}

/**
 * test for matrix multiplication when "this" matrix is not rectangular
 * @return
 */
bool multiTest3() {
    try {
        mymatrix<int> M1;
        M1.growcols(3, 6);
        mymatrix<int> M2;
        mymatrix<int> M3 = M1 * M2;
    } catch (runtime_error &error) {
        return true;
    }
    return false;
}

/**
 * test for matrix multiplication when "other" matrix is not rectangular
 * @return
 */
bool multiTest4() {
    try {
        mymatrix<int> M1;
        mymatrix<int> M2;
        M2.growcols(3, 6);
        mymatrix<int> M3 = M1 * M2;
    } catch (runtime_error &error) {
        return true;
    }
    return false;
}

/**
 * test for matrix multiplication when the sizes are not match
 * @return
 */
bool multiTest5() {
    try {
        mymatrix<int> M1(3, 2);
        mymatrix<int> M2;

        mymatrix<int> M3 = M1 * M2;
    } catch (runtime_error &error) {
        return true;
    }
    return false;
}

/**
 * test for matrix multiplication
 * @return
 */
bool multiTest6() {
    mymatrix<int> M1(3, 5);
    mymatrix<int> M2(5, 6);
    mymatrix<int> M3 = M1 * M2;
    if (M3.size() == 18) {
        return true;
    }
    return false;
}

int main() {
    int passed = 0;
    int failed = 0;

    if (sizeTest1()) {
        passed++;
    } else {
        failed++;
        cout << "sizeTest1 failed" << endl;
    }
    if (sizeTest2()) {
        passed++;
    } else {
        failed++;
        cout << "sizeTest2 failed" << endl;
    }
    if (sizeTest3()) {
        passed++;
    } else {
        failed++;
        cout << "sizeTest3 failed" << endl;
    }
    if (sizeTest4()) {
        passed++;
    } else {
        failed++;
        cout << "sizeTest4 failed" << endl;
    }
    if (sizeTest5()) {
        passed++;
    } else {
        failed++;
        cout << "sizeTest5 failed" << endl;
    }
    if (sizeTest6()) {
        passed++;
    } else {
        failed++;
        cout << "sizeTest6 failed" << endl;
    }
    if (sizeTest7()) {
        passed++;
    } else {
        failed++;
        cout << "sizeTest7 failed" << endl;
    }
    if (sizeTest8()) {
        passed++;
    } else {
        failed++;
        cout << "sizeTest8 failed" << endl;
    }
    if (sizeTest9()) {
        passed++;
    } else {
        failed++;
        cout << "sizeTest9 failed" << endl;
    }
    if (sizeTest10()) {
        passed++;
    } else {
        failed++;
        cout << "sizeTest10 failed" << endl;
    }

    if (constructorTest1()) {
        passed++;
    } else {
        failed++;
        cout << "constructorTest1 failed" << endl;
    }
    if (constructorTest2()) {
        passed++;
    } else {
        failed++;
        cout << "constructorTest2 failed" << endl;
    }
    if (constructorTest3()) {
        passed++;
    } else {
        failed++;
        cout << "constructorTest3 failed" << endl;
    }
    if (constructorTest4()) {
        passed++;
    } else {
        failed++;
        cout << "constructorTest4 failed" << endl;
    }

    if (atTest1()) {
        passed++;
    } else {
        failed++;
        cout << "atTest1 failed" << endl;
    }
    if (atTest2()) {
        passed++;
    } else {
        failed++;
        cout << "atTest2 failed" << endl;
    }
    if (atTest3()) {
        passed++;
    } else {
        failed++;
        cout << "atTest3 failed" << endl;
    }

    if (multiTest1()) {
        passed++;
    } else {
        failed++;
        cout << "multiTest1 failed" << endl;
    }
    if (multiTest2()) {
        passed++;
    } else {
        failed++;
        cout << "multiTest2 failed" << endl;
    }
    if (multiTest3()) {
        passed++;
    } else {
        failed++;
        cout << "multiTest3 failed" << endl;
    }
    if (multiTest4()) {
        passed++;
    } else {
        failed++;
        cout << "multiTest4 failed" << endl;
    }
    if (multiTest5()) {
        passed++;
    } else {
        failed++;
        cout << "multiTest5 failed" << endl;
    }
    if (multiTest6()) {
        passed++;
    } else {
        failed++;
        cout << "multiTest6 failed" << endl;
    }

    // expected passed: 23, failed: 0
    cout << "Test passed: " << passed << endl;
    cout << "Test failed: " << failed << endl;

    return 0;
}
