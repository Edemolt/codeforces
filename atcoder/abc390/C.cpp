/***************************************
Name    : Demolt
Date    : 25-01-2025
Plateform : Atcoder
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
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    vector<pair<int, int>> hashes;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '#') {
                hashes.emplace_back(i, j);
            }
        }
    }

    int min_row = h, max_row = -1;
    int min_col = w, max_col = -1;
    for (auto& p : hashes) {
        int i = p.first;
        int j = p.second;
        min_row = min(min_row, i);
        max_row = max(max_row, i);
        min_col = min(min_col, j);
        max_col = max(max_col, j);
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            bool inside = (i >= min_row) && (i <= max_row) && (j >= min_col) && (j <= max_col);
            if (inside) {
                if (grid[i][j] == '.') {
                    cout << "No\n";
                    return;
                }
            } else {
                if (grid[i][j] == '#') {
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    cout << "Yes\n";
}

int32_t main() {
    Kushagra();
    fastio;
    int t = 1;

    // cin >> t; 

    while (t--) solve();
    return 0;
}