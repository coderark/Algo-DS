#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

struct node{
    node(long long id, long long ft):
        id(id),
        ft(ft)
    {}
    long long id, ft;
};

bool priority(node a, node b){
    return ((a.ft<b.ft || a.ft>b.ft) ? a.ft>b.ft : a.id>b.id);
}

class JobQueue {
 private:
  long long num_workers_;
  vector<long long> jobs_;

  vector<long long> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (long long i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    long long m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(long long i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    priority_queue<node, vector<node>, function<bool(node, node)>> scd(priority);
    for (long long i = 0; i < num_workers_; i++) {
        scd.push(node(i, 0));
    }
    for (long long i = 0; i < jobs_.size(); ++i) {
      node no=scd.top();
      scd.pop();
      assigned_workers_[i] = no.id;
      start_times_[i] = no.ft;
      no.ft+=jobs_[i];
      scd.push(no);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
