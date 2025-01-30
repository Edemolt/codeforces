/***************************************
Name    : Demolt
Date    : [Insert Date Here]
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

void solve() {
    int m, k;
    cin >> m >> k;
    string str;
    cin>>str;

    vector<int> prefix(m+1, 0);

    for(int i = 1; i <= m; i++){
        prefix[i] = prefix[i-1] + (str[i-1] == 'S' ? 1 : 0);
    }

    int sum = prefix[m];

    int flag = 1;
    for(int i = 1; i < m; i++){
        if( prefix[i] + (m - i) < k){
            flag = 0;
            break;
        }
    }

    int ans1 = flag ? m : -1;

    int mn = -1e9;

    if(m > 1){
        for(int i = 1; i < m; i++){
            int curr = k - prefix[i] + i;
            mn = max( mn, curr);
        }
    }
    int temp = k - sum + m - 1;
    int ans2 = -1;

    if( temp >= mn && temp >= m) ans2 = temp;

    cout<<max(ans1, ans2)<<endl;

}

int32_t main() {
    Kushagra();
    fastio;
    int t = 1;

    cin >> t; 

    while (t--) solve();
    return 0;
}