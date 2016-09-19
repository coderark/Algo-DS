#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<bool> visited;
int ans=0;

void reach(vector<list<int> > &adj, int x, int y) {
  visited[x]=true;
  for(list<int>::iterator it=adj[x].begin(); it!=adj[x].end() && !ans; it++){
      if(!visited[*it]){
          //cout<<(*it)<<' '<<y<<endl;
          if((*it)==y){
              ans=1;
          }
          if(ans){
              break;
          }
          reach(adj, (*it), y);
      }

  }
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  visited.resize(n, false);
  vector<list<int> > adj(n, list<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  reach(adj, x - 1, y - 1);
  std::cout << ans<<endl;
  // for(int i=0; i<n; i++){
  //     cout<<visited[i]<<' ';
  // }
}
