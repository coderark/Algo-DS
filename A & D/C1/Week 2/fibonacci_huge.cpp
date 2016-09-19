#include <iostream>

using namespace std;

long long get_fibonaccihuge(long long n, long long m) {
    int arr[m+1]={0};
    int prc=0;
    for(int i=2; i<=m; i++){
        if(arr[i]==0){
            prc++;
            for(int j=2*i; j<=m; j+=i){
                arr[j]=1;
            }
        }
    }
    int arr1[prc], c=0;
    for(int i=2; i<=m; i++){
        if(arr[i]==0){
            arr1[c]=i;
            c++;
        }
    }
    return 0;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
}
