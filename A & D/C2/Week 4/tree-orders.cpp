#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TreeOrders {
public:
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
  vector<int> pre_o, in_o, post_o;

  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  void in_order(int i) {
    if(i==-1){
        return ;
    }
    in_order(left[i]);
    in_o.push_back(key[i]);
    in_order(right[i]);
  }

  void pre_order(int i) {
      if(i==-1){
          return ;
      }
      pre_o.push_back(key[i]);
      pre_order(left[i]);
      pre_order(right[i]);
  }

  void post_order(int i) {
      if(i==-1){
          return ;
      }
      post_order(left[i]);
      post_order(right[i]);
      post_o.push_back(key[i]);
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  t.in_order(0);
  t.pre_order(0);
  t.post_order(0);
  print(t.in_o);
  print(t.pre_o);
  print(t.post_o);
  return 0;
}
