#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TreeHeight {
  int n;
  vector<int> parent;
  vector<vector<int>> arr;

public:
  int r;
  void read() {
    cin >> n;
    parent.resize(n);
    arr.resize(n);
    for (int i = 0; i < n; i++){
        cin >> parent[i];
        if(parent[i]==-1){
            r=i;
        }
        else{
            arr[parent[i]].push_back(i);
        }
    }

  }

  int compute_height(int i) {
    if(arr[i].empty()){
        return 1;
    }
    int l=arr[i].size(), res=-1;
    for(int j=0; j<l; j++){
        int ch=compute_height(arr[i][j]);
        if(ch>res){
            res=ch;
        }
    }
    return 1+res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  cout << tree.compute_height(tree.r) << endl;
}
