#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
    // for(int i=0; i<data_.size(); i++){
    //     cout<<data_[i]<<' ';
    // }
    // cout<<"\n";
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void SiftDown(int i){
      int l=data_.size();
      if(l<2*i+1){
          return;
      }
      while((2*i+1<l && data_[2*i+1]<data_[i]) || (2*i+2<l && data_[2*i+2]<data_[i])){
          if(2*i+2<l){
              if(data_[2*i+1]<data_[2*i+2]){
                  swap(data_[2*i+1], data_[i]);
                  swaps_.push_back(make_pair(i, 2*i+1));
                  i=2*i+1;
              }
              else{
                  swap(data_[2*i+2], data_[i]);
                  swaps_.push_back(make_pair(i, 2*i+2));
                  i=2*i+2;
              }
          }
          else{
              swap(data_[2*i+1], data_[i]);
              swaps_.push_back(make_pair(i, 2*i+1));
              i=2*i+1;
          }
      }
  }

  void GenerateSwaps() {
    swaps_.clear();
    int l=data_.size();
    for(int i=l/2-1; i>=0; i--){
        SiftDown(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
