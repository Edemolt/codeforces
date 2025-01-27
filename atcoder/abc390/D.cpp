/***************************************
Name    : Demolt
Date    : 2021/10/02 16:00:00
Platform: Atcoder
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
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> sum(1 << n, 0);
    for (int i = 0; i < (1 << n); ++i) {
        for (int i = 0; i < n; ++i) {
            if (i & (1 << i)) {
                sum[i] += arr[i];
            }
        }
    }

    vector<unordered_set<int>> dp(1 << n);
    dp[0].insert(0);

    for (int i = 1; i < (1 << n); ++i) {
        for (int s = i; s > 0; s = (s - 1) & i) {
            int rem = i ^ s;
            int currsum = sum[s];
            if (rem == 0) {
                dp[i].insert(currsum);
            } else {
                for (int x : dp[rem]) {
                    dp[i].insert(currsum ^ x);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1].size() << endl;
}

int32_t main() {
    Kushagra();
    fastio;
    int t = 1;

    // cin >> t; 

    while (t--) solve();
    return 0;
}