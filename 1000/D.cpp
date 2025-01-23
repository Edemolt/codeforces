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

vi getThoseBloodyPairsMyMan(vi &arr) {
    sort(all(arr));
    int k = sz(arr);
    int n = k / 2;
    vi v;
    for (int i = 0; i < n; i++) {
        int j = k - 1 - i;
        v.pb(arr[j] - arr[i]);
    }
    return v;
}

vi getMeThatBloodyPrefix(vi &arr) {
    vi v(sz(arr) + 1, 0);
    for (int i = 0; i < sz(arr); i++) {
        v[i+1] = v[i] + arr[i];
    }
    return v;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    
    auto arr1 = getThoseBloodyPairsMyMan(a);
    auto arr2 = getThoseBloodyPairsMyMan(b);
    
    int pa = sz(arr1), pb = sz(arr2);
    auto a_arr = getMeThatBloodyPrefix(arr1);
    auto b_arr = getMeThatBloodyPrefix(arr2);
    
    // Compute mx1
    int l = 0, r = (n + m) / 3;
    int mx1 = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int mnx = max(2 * mid - m, 0LL);
        int mxx = min(n - mid, mid);
        if (mnx <= mxx) {
            mx1 = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << mx1 << '\n';
    if (mx1 == 0) return;
    
    vi ans;
    for (int s = 1; s <= mx1; s++) {
        int mnx = max(2 * s - m, 0LL);
        mnx = max(mnx, s - pb);
        int mxx = min(n - s, s);
        mxx = min(mxx, pa);
        mxx = min(mxx, s);
        
        int answer = 0;
        int tl = mnx, tr = mxx;
        while (tl <= tr) {
            int m1 = tl + (tr - tl) / 3;
            int m2 = tr - (tr - tl) / 3;
            int s1 = a_arr[min(m1, pa)] + b_arr[min(s - m1, pb)];
            int s2 = a_arr[min(m2, pa)] + b_arr[min(s - m2, pb)];
            answer = max(answer, max(s1, s2));
            if (s1 < s2) {
                tl = m1 + 1;
            } else {
                tr = m2 - 1;
            }
        }
        answer = max(answer, a_arr[min(mnx, pa)] + b_arr[min(s - mnx, pb)]);
        answer = max(answer, a_arr[min(mxx, pa)] + b_arr[min(s - mxx, pb)]);
        ans.pb(answer);
    }
    
    for (int i = 0; i < sz(ans); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
}

int32_t main() {
    Kushagra();
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
