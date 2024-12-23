// Q.1. Given an array of integers, find sum of array elements using recursion. 
// Program Code:- 
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 3;
    cout << "F(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
