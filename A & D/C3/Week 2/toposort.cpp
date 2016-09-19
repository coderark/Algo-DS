#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

long long c=0;
vector<int> order;

void reach(vector<list<int> > &adj, vector<bool> &used, int i){
    used[i]=true;
    for(list<int>::iterator it=adj[i].begin(); it!=adj[i].end(); it++){
        if(!used[(*it)]){
            reach(adj, used, *it);
        }
    }
    order.push_back(i);


}
vector<int> toposort(vector<list<int> > adj) {
  vector<bool> used(adj.size(), false);
  for(int i=0; i<adj.size(); i++){
      if(!used[i]){
          reach(adj, used, i);
      }
  }
  //write your code here
  return order;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<list<int> > adj(n, list<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (int i = order.size()-1; i >=0 ; i--) {
    cout << order[i] + 1 << " ";
  }
}
