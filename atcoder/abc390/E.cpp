#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back

struct Group {
    vector<int> dp;
    vector<int> max_sum;

    void compute(int X, const vector<pair<int, int>>& foods) {
        dp.assign(X + 1, -1e18);
        dp[0] = 0;
        for (auto& food : foods) {
            int a = food.first, c = food.second;
            for (int j = X; j >= c; --j) {
                if (dp[j - c] + a > dp[j]) {
                    dp[j] = dp[j - c] + a;
                }
            }
        }
        max_sum.resize(X + 1);
        max_sum[0] = dp[0];
        for (int j = 1; j <= X; ++j) {
            max_sum[j] = max(max_sum[j - 1], dp[j]);
        }
    }

    int get_min_cost(int K, int X) {
        if (max_sum[X] < K) return -1;
        int left = 0, right = X;
        int res = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (max_sum[mid] >= K) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};

void solve() {
    int N, X;
    cin >> N >> X;

    vector<pair<int, int>> groups[3];
    for (int i = 0; i < N; ++i) {
        int v, a, c;
        cin >> v >> a >> c;
        --v; // Convert to 0-based index
        groups[v].emplace_back(a, c);
    }

    Group g0, g1, g2;
    g0.compute(X, groups[0]);
    g1.compute(X, groups[1]);
    g2.compute(X, groups[2]);

    int upper = min({g0.max_sum[X], g1.max_sum[X], g2.max_sum[X]});
    if (upper < 0) upper = 0;

    int low = 0, high = upper;
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        int c0 = g0.get_min_cost(mid, X);
        int c1 = g1.get_min_cost(mid, X);
        int c2 = g2.get_min_cost(mid, X);

        if (c0 == -1 || c1 == -1 || c2 == -1) {
            high = mid - 1;
        } else {
            if (c0 + c1 + c2 <= X) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    cout << ans << endl;
}

int32_t main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}