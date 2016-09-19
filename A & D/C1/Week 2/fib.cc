#include <iostream>

using namespace std;

long long calc_fib(int n) {
    long long arr[n+1];
    arr[0]=0, arr[1]=1;
    for(int i=2; i<=n; i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << calc_fib(n) << '\n';
    return 0;
}
