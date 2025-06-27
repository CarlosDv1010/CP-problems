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

const int N = 1000002;



int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    IOS;
    int n, c;
    cin >> n >> c;
    vi weights(n);

    fori (i, 0, n) cin >> weights[i];

    vpii dp(1 << n);
    dp[0] = {1, 0};

    fori (mask, 1, 1 << n){
        dp[mask] = {30, 0};
        fori (i, 0, n){
            if ((1 << i) & mask){
                auto [rides, last] = dp[mask ^ (1 << i)];

                if (last + weights[i] <= c){
                    dp[mask] = min(dp[mask], {dp[mask ^ (1 << i)].ff, dp[mask ^ (1 << i)].ss + weights[i]});
                }
                
                else {
                    dp[mask] = min (dp[mask], {dp[mask ^ (1 << i)].ff + 1, min(weights[i], dp[mask ^ (1 << i)].ss)});
                }
            } 
        }
    }
    cout << dp[(1 << n) - 1].ff << endl;

    return 0;
}