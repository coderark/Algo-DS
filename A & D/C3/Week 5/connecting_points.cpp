#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

struct point{
    int x, y, id;
};

struct edge{
    int id1, id2;
    double l;
};

class disjoint{
private:
    vector<int> arr, rank;
    int n;

public:
    disjoint(int n): n(n){
        arr.resize(n);
        rank.resize(n, 1);
        for(int i=0; i<n; i++){
            arr[i]=i;
        }
    }

    int dfind(int i){
        if(arr[i]!=i){
            arr[i]=dfind(arr[i]);
        }
        return arr[i];
    }

    void dunion(int x, int y){
        int xp=dfind(x), yp=dfind(y);
        if(xp==yp){
            return;
        }
        if(rank[xp]==rank[yp]){
            arr[xp]=yp;
            rank[yp]++;
        }
        else if(rank[xp]<rank[yp]){
            arr[xp]=yp;
        }
        else{
            arr[yp]=xp;
        }
    }
};

bool comp(edge a, edge b){
    return a.l<b.l;
}

double dist(point a, point b){
    return sqrt(pow((a.x-b.x), 2)+pow((a.y-b.y), 2));
}

double minimum_distance(vector<point> pset) {
  double result = 0.;
  int n=pset.size();
  int le=n*(n-1)/2;
  vector<edge> eset(le);
  int c=0;
  for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++, c++){
          eset[c].id1=pset[i].id;
          eset[c].id2=pset[j].id;
          eset[c].l=dist(pset[i], pset[j]);
      }
  }
  // for(int i=0; i<le; i++){
  //     cout<<eset[i].l<<' ';
  // }
  // cout<<endl;
  sort(eset.begin(), eset.end(), comp);
  // for(int i=0; i<le; i++){
  //     cout<<eset[i].l<<' ';
  // }
  // cout<<endl;
  disjoint dset(n);
  for(int i=0; i<le; i++){
      int a=dset.dfind(eset[i].id1), b=dset.dfind(eset[i].id2);
      if(a!=b){
          //cout<<eset[i].l<<' ';
          result+=eset[i].l;
          dset.dunion(a, b);
      }
  }
  //cout<<endl;
  return result;
}

int main() {
  size_t n;
  cin >> n;
  vector<point> pset(n);
  for (size_t i = 0; i < n; i++) {
    cin >> pset[i].x >> pset[i].y;
    pset[i].id=i;
  }
  cout << setprecision(10) << minimum_distance(pset) << endl;
}
