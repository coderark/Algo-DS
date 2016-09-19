#include <iostream>
#include <vector>

using namespace std;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  int n=adj.size();
  vector<int> dist(adj.size(), 1000000);
  dist[0]=0;
  bool cycle=false;
  while(n--){
      bool ex=true;
      for(int i=0; i<adj.size(); i++){
          for(int j=0; j<adj[i].size(); j++){
              if(dist[adj[i][j]]>dist[i]+cost[i][j]){
                  dist[adj[i][j]]=dist[i]+cost[i][j];
                  ex=false;
              }
          }
      }
      if(ex){
          return 0;
      }
      else{
          if(n==1){
              return 1;
          }
      }
  }
  cout<<"Wrong"<<endl;
  return 0;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  cout << negative_cycle(adj, cost);
}
