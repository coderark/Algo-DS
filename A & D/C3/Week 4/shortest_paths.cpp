#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;


void bfs(vector<vector<long long> > &adj, queue<long long> &q, vector<long long> &shortest, vector<bool> &visited){
    while(!q.empty()){
        while(!q.empty() && !shortest[q.front()]){
            q.pop();
        }
        long long u;
        if(!q.empty()){
            u=q.front();
            q.pop();
        }
        shortest[u]=0;
        for(long long i=0; i<adj[u].size(); i++){
            if(!visited[adj[u][i]]){
                q.push(adj[u][i]);
                visited[adj[u][i]]=true;
            }
        }
    }
}

void shortest_paths(vector<vector<long long> > &adj, vector<vector<long long> > &cost, long long s, vector<long long> &distance, vector<long long> &reachable, vector<long long> &shortest) {
    long long n=adj.size();
    vector<bool> visited(adj.size(), false);
    distance[s]=0;
    reachable[s]=1;
    queue<long long> q;
    while(n>0){
        for(long long i=0; i<adj.size(); i++){
            for(long long j=0; j<adj[i].size(); j++){
                if(distance[i]!=numeric_limits<long long>::max()/2 && (distance[adj[i][j]]>distance[i]+cost[i][j])){
                    reachable[adj[i][j]]=1;
                    distance[adj[i][j]]=distance[i]+cost[i][j];
                    if(n==1){
                        q.push(adj[i][j]);
                        visited[adj[i][j]]=true;
                    }
                }
            }
        }
        n--;
    }
    bfs(adj, q, shortest, visited);

}

int main() {
  long long n, m, s;
  cin >> n >> m;
  vector<vector<long long> > adj(n, vector<long long>());
  vector<vector<long long> > cost(n, vector<long long>());
  for (long long i = 0; i < m; i++) {
    long long x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  cin >> s;
  s--;
  vector<long long> distance(n, numeric_limits<long long>::max()/2);
  vector<long long> reachable(n, 0);
  vector<long long> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (long long i = 0; i < n; i++) {
    if (!reachable[i]) {
      cout << "*\n";
    } else if (!shortest[i]) {
      cout << "-\n";
    } else {
      cout << distance[i] << "\n";
    }
  }
}
