#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
#define endl '\n'
#define pb push_back
#define pf push_front
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fori(i, s, n) for(int i = s; i < n; ++i)
#define rfori(i, s, n) for(int i = s; i >= n; --i)
 
#define DBG(X) cout << #X << " = " << X << endl;
#define RAYA cout << " ========================= " << endl;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template<typename T>
ostream & operator <<(ostream &os, const vector<T> &v){
    os << "[";
    fori(i, 0, v.size()){
        if (i > 0) os << ",";
        os << v[i];
    }
    return os << "]";
}
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;
const ld EPS = 1e-9;

const int N = 5005;
ll a[N], dp[N][N], pref[N];

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    IOS;

    int n;
    cin >> n;
    fori (i, 1, n + 1) cin >> a[i];
    pref[1] = a[1];
    
    fori(i, 2, n + 1) pref[i] = pref[i - 1] + a[i];
    fori (i, 1, n + 1) dp[i][i] = a[i];

    fori (len, 2, n + 1){
        for (int i = 1; i + len - 2 < n; ++i){
            ll j = i + len - 1;
            ll leftscore = pref[j] - pref[i] - dp[i + 1][j];
            ll leftscore2 = pref[j - 1] - pref[i - 1] - dp[i][j - 1];
            dp[i][j] = max(leftscore + a[i], leftscore2 + a[j]); 
        }
    }
    

    cout << dp[1][n] << endl;
    return 0;
}