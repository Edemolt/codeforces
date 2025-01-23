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
    string str = "Hello I am Kushagra, here to save myself from plagirism :)";
}

void solve() {
    int n;
    cin >> n;
    vector<unordered_set<int>> adjoint(n + 1);
    vi deg_arr(n + 1, 0);
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adjoint[u].insert(v);
        adjoint[v].insert(u);
        deg_arr[u]++;
        deg_arr[v]++;
    }

    vi canditate_arr;
    if (n <= 200) {
        canditate_arr.resize(n);
        iota(all(canditate_arr), 1);
    } else {
        vpii nodes;
        for (int i = 1; i <= n; ++i) {
            nodes.emplace_back(deg_arr[i], i);
        }
        sort(all(nodes), [](const auto& a, const auto& b) {
            return a.fi > b.fi;
        });
        
        unordered_set<int> added;
        for (int i = 0; i < 200; ++i) {
            canditate_arr.pb(nodes[i].se);
            added.insert(nodes[i].se);
        }

        int u = canditate_arr[0];
        int max_adjoint_degree = 0, max_adjoint_node = -1;
        int max_non_adjoint_degree = 0, max_non_adjoint_node = -1;
        
        for (int i = 1; i <= n; ++i) {
            if (i == u || added.count(i)) continue;
            if (adjoint[u].count(i)) {
                if (deg_arr[i] > max_adjoint_degree) {
                    max_adjoint_degree = deg_arr[i];
                    max_adjoint_node = i;
                }
            } else {
                if (deg_arr[i] > max_non_adjoint_degree) {
                    max_non_adjoint_degree = deg_arr[i];
                    max_non_adjoint_node = i;
                }
            }
        }
        
        if (max_adjoint_node != -1) {
            canditate_arr.pb(max_adjoint_node);
            added.insert(max_adjoint_node);
        }
        if (max_non_adjoint_node != -1) {
            canditate_arr.pb(max_non_adjoint_node);
            added.insert(max_non_adjoint_node);
        }
    }

    int mx = 0;
    for (int i = 0; i < sz(canditate_arr); ++i) {
        int u = canditate_arr[i];
        for (int j = i + 1; j < sz(canditate_arr); ++j) {
            int v = canditate_arr[j];
            int overlap = adjoint[u].count(v) ? 1 : 0;
            int current = deg_arr[u] + deg_arr[v] - overlap;
            mx = max(mx, current);
        }
    }

    cout << max(mx - 1, 0LL) << '\n';
}

int32_t main() {
    Kushagra();
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}