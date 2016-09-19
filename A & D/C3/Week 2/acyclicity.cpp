#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>

using namespace std;

int c=0;
vector<int> order;

bool check(int x){
    for(vector<int>::iterator it=order.begin(); it!=order.end(); it++){
        if((*it)==x){
            c=1;
            return true;
        }
    }
    return false;
}

void reach(vector<list<int> > &adj, vector<bool> &used, int i){
    used[i]=true;
    for(list<int>::iterator it=adj[i].begin(); it!=adj[i].end() && c==0; it++){
        if(check(*it)){
            break;
        }
        if(!used[(*it)]){
            order.push_back(*it);
            reach(adj, used, *it);
            order.pop_back();
        }
    }

}
void toposort(vector<list<int> > adj) {
  vector<bool> used(adj.size(), false);
  for(int i=0; i<adj.size(); i++){
      if(!used[i]){
          order.push_back(i);
          reach(adj, used, i);
          order.pop_back();
      }
  }
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
  toposort(adj);
  cout<<c;
}
