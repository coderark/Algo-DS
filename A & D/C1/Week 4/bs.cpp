#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct seg{
    int left, right;
};

bool compL(seg x, seg y){
    return x.left<y.left;
}

bool compR(seg x, seg y){
    return x.right<y.right;
}

int bsl(vector<seg> &arr, int l, int r, int x){
    int m=l+(r-l+1)/2;
    if(arr[m].right>)
    if(arr[m].right<=x){
        return bsl(arr, m+1, r, x);
    }
    else{
        return bsl(arr, l, m, x);
    }
}
