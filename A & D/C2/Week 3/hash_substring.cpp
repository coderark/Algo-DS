#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const vector<long long>& output) {
    for (long long i = 0; i < output.size(); ++i)
        cout << output[i] << " ";
    cout << "\n";
}

long long hash_func(string &s) {
    static const long long multiplier = 263;
    static const long long prime = 1000000007;
    unsigned long long hash = 0;
    for (long long i =0; i < s.size(); ++i)
        hash = (hash * multiplier + s[i]) % prime;
    return hash;
}

bool match(string &a, string &b){
    if(a.length()!=b.length()){
        return false;
    }
    for(long long i=0; i<a.length(); i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}

vector<long long> get_occurrences(const Data& input) {
    string s = input.pattern, t = input.text;
    long long sl=s.length(), tl=t.length();
    vector<long long> ans, hash(tl-sl+1);
    long long shash=hash_func(s);
    //cout<<shash<<endl;
    string s1=t.substr(0, sl);
    hash[0]=hash_func(s1);
    //cout<<hash[0]<<' ';
    static const long long multiplier = 263;
    static const long long prime = 1000000007;
    long long con=1;
    for(long long i=0; i<sl; i++){
        con=(con*multiplier)%prime;
    }
    if(hash[0]==shash && match(s, s1)){
        ans.push_back(0);
    }
    for (long long i = 1; i + sl <= tl; ++i){
        hash[i]= (((hash[i-1]*multiplier+t[i+sl-1]-con*t[i-1])%prime)+prime)%prime;
        //cout<<hash[i]<<' ';

        if(hash[i]==shash){
            string si=t.substr(i, sl);
            if(match(s, si)){
                ans.push_back(i);
            }

        }
    }
    //cout<<endl;
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
