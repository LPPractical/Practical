#include <iostream>

using namespace std;

int main() {
    int n;
    int a = 0;
    int b = 1;
    int c;

    cout << "Enter the number of terms: ";
    cin >> n;
    cout<<a<<" "<<b<<" ";
    for (int i = 0; i < n-2; i++) {
        c = a + b;
        cout<<c<<" ";
        a = b;
        b = c;
    }

    return 0;
}
