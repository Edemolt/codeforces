/***************************************
Name    : Demolt
Date    : 25/01/2026
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
    int N;
    cin >> N;
    vi A(N);
    for (auto& x : A) cin >> x;

    // Helper lambda to calculate sumOfK
    auto sumOfK = [&](const vi& A) {
        int n = A.size();
        vi last(n + 1, -1);
        int res = 0;
        for (int j = 0; j < n; ++j) {
            res += (j - last[A[j]]) * (n - j);
            last[A[j]] = j;
        }
        return res;
    };

    // Helper lambda to calculate sumOfMax or sumOfMin
    auto calculateSum = [&](const vi& A, bool findMax) {
        int n = A.size();
        vi left(n, -1), right(n, n);
        vector<int> st;

        // Process left bounds
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && (findMax ? A[st.back()] <= A[i] : A[st.back()] >= A[i])) st.pop_back();
            if (!st.empty()) left[i] = st.back();
            st.push_back(i);
        }

        st.clear();
        // Process right bounds
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && (findMax ? A[st.back()] < A[i] : A[st.back()] > A[i])) st.pop_back();
            if (!st.empty()) right[i] = st.back();
            st.push_back(i);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += A[i] * (i - left[i]) * (right[i] - i);
        }
        return res;
    };

    int sum_1 = N * (N + 1) / 2;
    int sum_k = sumOfK(A);
    int sum_max = calculateSum(A, true);
    int sum_min = calculateSum(A, false);

    int ans = (sum_max - sum_min) + sum_1 - sum_k;
    cout << ans << endl;
}

int32_t main() {
    Kushagra();
    fastio;
    int t = 1;

    // cin >> t; 

    while (t--) solve();
    return 0;
}