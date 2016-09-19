#include <iostream>
#include <vector>

using namespace std;

long long lcs3(vector<long long> &a, vector<long long> &b, vector<long long> &c) {
  long long la=a.size(), lb=b.size(), lc=c.size();
  vector<vector<vector<long long>>> arr(la+1, vector<vector<long long>>(lb+1, vector<long long>(lc+1)));
  for(long long i=0; i<=la; i++){
      arr[i][0][0]=0;
  }
  for(long long i=0; i<=lb; i++){
      arr[0][i][0]=0;
  }
  for(long long i=0; i<=lc; i++){
      arr[0][0][i]=0;
  }
  for(long long i=1; i<=la; i++){
      for(long long j=1; j<=lb; j++){
          for(long long k=1; k<=lc; k++){
              long long csmin=max(max(max(max(max(arr[i-1][j-1][k], arr[i-1][j][k-1]), arr[i-1][j][k]), arr[i][j-1][k]), arr[i][j-1][k-1]), arr[i][j][k-1]);
              if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
                  arr[i][j][k]=arr[i-1][j-1][k-1]+1;
              }
              else{
                  arr[i][j][k]=csmin;
              }
          }
      }
  }
  return arr[la][lb][lc];
}

int main() {
  for(int i=0; i<10; i++){
      int an=rand()%8+2;
      cout<<an<<endl;
      vector<long long> a(an);
      for (int i = 0; i < an; i++) {
        a[i]=rand()%2+1;
        cout<<a[i]<<' ';
      }
      cout<<endl;
      int bn=rand()%8+2;
      cout<<bn<<endl;
      vector<long long> b(bn);
      for (int i = 0; i < bn; i++) {
        b[i]=rand()%2+1;
        cout<<b[i]<<' ';
      }
      cout<<endl;
      int cn=rand()%8+2;
      cout<<cn<<endl;
      vector<long long> c(cn);
      for (int i = 0; i < cn; i++) {
        c[i]=rand()%2+1;
        cout<<c[i]<<' ';
      }
      cout<<endl;
      cout << lcs3(a, b, c) << endl;
  }
}
