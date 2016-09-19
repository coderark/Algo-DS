#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<bool> visited;


void reach(vector<list<int> > &adj, int x) {
  visited[x]=true;
  for(list<int>::iterator it=adj[x].begin(); it!=adj[x].end(); it++){
      if(!visited[*it]){
          reach(adj, (*it));
      }

  }
}

int number_of_components(vector<list<int> > &adj) {
  int res = 0;
  for(int i=0; i<adj.size(); i++){
      if(!visited[i]){
          reach(adj, i);
          res++;
      }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<list<int> > adj(n, list<int>());
  visited.resize(n, false);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
