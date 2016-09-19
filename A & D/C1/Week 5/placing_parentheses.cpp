#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  long long l=exp.length(), numd=(l+1)/2;
  vector<vector<long long>> minex(numd, vector<long long>(numd)), maxex(numd, vector<long long>(numd));
  for(long long i=0; i<numd; i++){
      minex[i][i]=exp[2*i]-'0';
      maxex[i][i]=exp[2*i]-'0';
  }
  for(long long k=0; k<numd; k++){
      for(long long i=0, j=k+1; j<numd; i++, j++){
          long long tmin=100000000, tmax=-100000000;
          for(long long z=i; z<j; z++){
              long long a=eval(minex[i][z], minex[z+1][j], exp[2*z+1]);
              long long b=eval(minex[i][z], maxex[z+1][j], exp[2*z+1]);
              long long c=eval(maxex[i][z], minex[z+1][j], exp[2*z+1]);
              long long d=eval(maxex[i][z], maxex[z+1][j], exp[2*z+1]);
              long long smin=min(min(min(a, b), c), d);
              long long smax=max(max(max(a, b), c), d);
              if(smin<tmin){
                  tmin=smin;
              }
              if(smax>tmax){
                  tmax=smax;
              }
          }
          minex[i][j]=tmin;
          maxex[i][j]=tmax;
      }
  }
  return maxex[0][numd-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
