/***************************************
Name    : Demolt
Date    : 23-01-2025
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
    string str = "Hello I am Kushagra, here to save myself from plagirism :)";
}

void solve() {
    int n, left, right;
    cin >> n >> left >> right;
    vi arr(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int rlength = right - left + 1;
    
    right = min(right, n);
    left = max(left, 1LL);
    int start = left - 1;
    
    rlength = min(rlength, right);
    rlength = min(rlength, n - start);
    
    vi l_part, r_part;

    for (int i = 0; i < right; i++) l_part.pb(arr[i]);
    for (int i = start; i < n; i++) r_part.pb(arr[i]);
    
    sort(all(l_part));
    sort(all(r_part));
    
    int lsum = 0, rsum = 0;
    for (int i = 0; i < rlength; i++) {
        if (i < sz(l_part)) lsum += l_part[i];
        if (i < sz(r_part)) rsum += r_part[i];
    }
    
    cout << min(lsum, rsum) << "\n";
}

int32_t main() {
    Kushagra();
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
