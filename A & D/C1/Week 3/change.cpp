#include <iostream>

int get_change(int n) {
    int a, b, c, d;
    a=n/10;
    b=n%10;
    c=b/5;
    d=b%5;
    return a+c+d;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << get_change(n) << '\n';
}
