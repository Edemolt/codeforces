/***************************************
Name    : Demolt
Date    : 2023-09-28
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
const int MAXN = 3e5 + 5;

// Global variables
vector<int> adj[MAXN];
int depth[MAXN], subtree_size[MAXN];
int freq[MAXN], suffix_sum[MAXN];

// Utility functions
template<typename T> void printvec(const vector<T>& v) {
    for (const auto& x : v) cout << x << " ";
    cout << endl;
}

void dfs(int u, int parent_u, int current_depth) {
    depth[u] = current_depth;
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v != parent_u) {
            dfs(v, u, current_depth + 1);
            subtree_size[u] += subtree_size[v];
        }
    }
}

void solve() {
    int n;
    cin >> n;

    // Reset structures
    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
        freq[i] = 0;
        suffix_sum[i] = 0;
    }

    // Read tree
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // Compute depth and subtree sizes
    dfs(1, -1, 0);

    // Calculate frequency of each depth
    int max_depth = 0;
    for (int i = 1; i <= n; ++i) {
        freq[depth[i]]++;
        max_depth = max(max_depth, depth[i]);
    }

    // Compute suffix sums
    suffix_sum[max_depth] = freq[max_depth];
    for (int d = max_depth-1; d >= 0; --d)
        suffix_sum[d] = suffix_sum[d+1] + freq[d];

    // Calculate sum1
    long long sum1 = 0;
    for (int u = 1; u <= n; ++u)
        sum1 += 2LL * depth[u] * (suffix_sum[depth[u]] - subtree_size[u]);

    // Calculate sum2
    long long sum2 = 0;
    for (int d = 0; d <= max_depth; ++d) {
        long long cnt = freq[d];
        sum2 += 2LL * d * (cnt * (cnt - 1) / 2);
    }

    // Calculate sum3
    long long sum3 = 0;
    for (int w = 1; w <= n; ++w) {
        long long S = subtree_size[w] - 1;
        if (S <= 0) continue;

        long long temp = 0;
        for (int child : adj[w]) {
            if (depth[child] == depth[w] + 1) // Ensure child is direct child
                temp += subtree_size[child] * (S - subtree_size[child]);
        }

        sum3 += (2LL * depth[w] + 1) * temp;
    }
    sum3 /= 2;

    // Final result
    cout << sum1 - sum2 - sum3 << '\n';
}

void Kushagra(){
    string str = "Just a feeble attempt to avoid getting plagiarism :)";
}

int32_t main() {
    Kushagra();
    fastio;
    int t = 1;
    cin >> t; 

    while (t--) solve();
    return 0;
}