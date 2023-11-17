#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    cout << "Enter the number of terms: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}

\*

If n is 0 or 1, the function returns n directly. This is because the Fibonacci sequence starts with 0 and 1.

If n is greater than 1, the function recursively calls itself twice with n - 1 and n - 2 until it reaches the base case.

Now, let's go through the calculation for fibonacci(4) step by step:

fibonacci(4) calls fibonacci(3) + fibonacci(2)
fibonacci(3) calls fibonacci(2) + fibonacci(1)
fibonacci(2) calls fibonacci(1) + fibonacci(0)
fibonacci(1) returns 1
fibonacci(0) returns 0
So, fibonacci(2) returns 1 + 0 = 1
fibonacci(1) returns 1
So, fibonacci(3) returns 1 + 1 = 2
fibonacci(2) calls fibonacci(1) + fibonacci(0)
fibonacci(1) returns 1
fibonacci(0) returns 0
So, fibonacci(2) returns 1 + 0 = 1
So, fibonacci(4) returns 2 + 1 = 3



*/