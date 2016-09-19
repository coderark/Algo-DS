#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};

bool comp(Segment a, Segment b){
    return a.end<b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end(), comp);
  //write your code here
  points.push_back(segments[0].end);
  for(int i=1; i<segments.size(); i++){
      if(points.back()>=segments[i].start){
          continue;
      }
      else{
          points.push_back(segments[i].end);
      }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
