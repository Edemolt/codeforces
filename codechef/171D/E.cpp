/***************************************
Name    : Demolt
Date    : 29/01/2025
Contest : Codechef
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
    int n, p;
    cin >> n >> p;
    vector<int> arr(n);
    vector<int> time(n, 1e9);

    for(int i = 0; i < n; i++){
        cin >> arr[i];   
        if(arr[i] == 0) time[i] = 0;
    }

    int last_volcano = -1, current_max = 0;

    // Left to Right Pass
    for(int i = 0; i < n; i++){
        if(arr[i] == 0) {
            last_volcano = i;
            current_max = 0;
        } else if (last_volcano != -1) {
            current_max = max(current_max, arr[i]);
            time[i] = min(time[i], (current_max + p - 1) / p);
        }
    }

    last_volcano = -1;
    current_max = 0;

    // Right to Left Pass
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] == 0) {
            last_volcano = i;
            current_max = 0;
        } else if (last_volcano != -1) {
            current_max = max(current_max, arr[i]);
            time[i] = min(time[i], (current_max + p - 1) / p);
        }
    }

    // Print result
    for(int i = 0; i < n; i++) {
        cout << time[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    Kushagra();
    fastio;
    int t = 1;

    cin >> t; 

    while (t--) solve();
    return 0;
}