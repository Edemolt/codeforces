/***************************************
Name    : Demolt
Date    : 26-01-2025
Contest : Codeforces
***************************************/

#include <bits/stdc++.h>
using namespace std;

// Optimize macros for Codeforces
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define fi first
#define se second
#define sz(x) (int)(x.size())

// Debugging
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e18;

// Utility functions
template<typename T> void printvec(const vector<T>& v) {
    for (const auto& x : v) cout << x << " ";
    cout << endl;
}

void Kushagra(){
    string str = "Just a feeble attempt to avoid getting plagiarism :)";
}

int fn(string &str){
    int n = str.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '1') cnt += 1;
    }

    return cnt;
}

void solve() {
    Kushagra();
    string str;
    cin >> str;
    int ans = fn(str);
    cout<<ans<<endl;
}

int32_t main() {
    Kushagra();
    fastio;
    int t = 1;

    cin >> t; 

    while (t--) solve();
    return 0;
}