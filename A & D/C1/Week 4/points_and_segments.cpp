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

// int fast_count_segments(vector<seg> &arr, int point) {
//
//
//   return cnt;
// }

// vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
//   vector<int> cnt(points.size());
//   for (size_t i = 0; i < points.size(); i++) {
//     for (size_t j = 0; j < starts.size(); j++) {
//       cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
//     }
//   }
//   return cnt;
// }


int main() {
  int n, m;
  cin >> n >> m;
  vector<seg> arr(n);
  for (size_t i = 0; i < arr.size(); i++) {
    cin >> arr[i].left >> arr[i].right;
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    cin >> points[i];
  }
  //use fast_count_segments
  //vector<int> cnt = naive_count_segments(starts, ends, points);
  sort(arr.begin(), arr.end(), compR);
  for (size_t i = 0; i < points.size(); i++) {


  }
}
