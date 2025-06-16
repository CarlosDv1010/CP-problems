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

const int N = 1005;
string v[N];

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    int n;
    cin >> n;

    vvll dp(n + 1, vll(n + 5, 0));
    dp[1][1] = 1;

    fori(i, 0, n){
        cin >> v[i];
    }

    fori (i, 0, n){
        fori (j, 0, v[i].size()){
            if (v[i][j] == '*') dp[i + 1][j + 1] = LLONG_MAX; 
        }
    }

    
    
    fori (i, 1, n + 1){
        fori (j, 1, n + 1){
            if (i == 1 && j == 1) continue;
            if (dp[i][j] == LLONG_MAX) continue;
            if (i > 1 && dp[i - 1][j] != LLONG_MAX) dp[i][j] += dp[i - 1][j];
            if (j > 1 && dp[i][j - 1] != LLONG_MAX) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    if (dp[n][n] == LLONG_MAX){
        cout << 0 << endl;
        return 0;
    }

    cout << dp[n][n] << endl;
    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}