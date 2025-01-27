/***************************************
Name    : Demolt
Date    : 26-01-2025
Contest : Codeforces
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

vector<int> fn2( vi &arr){
    vi diff;
    for(int i = 0; i < sz(arr) - 1; i++){
        diff.pb(arr[i + 1] - arr[i]);
    }
    return diff;
}

int fn3( vi &arr1, vi &arr2){
    int n = arr1.size();
    for(int i = 0; i < n; i++){
        if(arr1[i] != arr2[i]) return arr1[i] > arr2[i];
    }
    return 0;
}

int fn(vi &arr, int n){
    int sum = 0;
    for(int num : arr) sum += num;

    vi curr = arr;

    for(int i = 0; i < n - 1; i++){
        vi reverse(rall(curr));
        vi diff1 = fn2(curr);
        vi diff2 = fn2(reverse);

        int sum1 = 0, sum2 = 0;
        for(int num : diff1) sum1 += num;
        for(int num : diff2) sum2 += num;

        vi v;
        if(sum1 > sum2) v = diff1;
        else if(sum2 > sum1) v = diff2;
        else{
            if(fn3(diff1, diff2)) v = diff1;
            else v = diff2;
        }

        curr = v;
        int currsum = 0;
        for(int it: curr) currsum += it;
        
        sum = max( sum, currsum);

        if(curr.size() == 1) break;
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    if(n == 1){
        cout<<arr[0]<<endl;
        return;
    }
    
    int ans = fn(arr, n);
    cout<<ans<<endl;
}

int32_t main() {
    Kushagra();
    fastio;
    int t = 1;

    cin >> t; 

    while (t--) solve();
    return 0;
}