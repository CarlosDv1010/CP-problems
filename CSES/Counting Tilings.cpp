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
#define is_on(x, a) (x & (1 << (a)))
 
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

const int N = 200005;
int n, m;



int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    
    cin >> n >> m;

    vvll dp(m + 1, vll (1 << n, 0));
    dp[0][0] = 1;

    fori (j, 0, m){
        fori (mask, 0, 1 << n){
            if (dp[j][mask] == 0) continue;
            function<void(int,int)> fill = [&](int i, int nextmask){
                if (i == n){
                    dp[j + 1][nextmask] = (dp[j + 1][nextmask] + dp[j][mask]) % MOD;
                    return;
                }
                if (mask & (1 << i)){
                    fill(i + 1, nextmask );
                }
                else {
                    fill(i + 1, nextmask | (1 << i));
                    if (i + 1 < n && !is_on(mask, i + 1)){
                        fill (i + 2, nextmask);
                    }
                }
            };
            fill(0, 0);
        }
    }

    cout << dp[m][0];

    

    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}