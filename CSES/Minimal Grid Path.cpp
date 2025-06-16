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

const int N = 3001;
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

    fori (i, 1, n + 1){
        cin >> v[i];
    }

    vvll dp (n + 1, vll(n + 1, INT_MAX));
    
    dp[1][0] = dp[0][1] = 0;
    fori (i, 1, n + 1){
        fori (j, 1, n + 1){
            int cost = v[i][j - 1] - 'A' + 1;
            dp[i][j] = min(dp[i - 1][j] + cost, dp[i][j - 1] + cost);
        }
    }
    int i = 1, j = 0;
    string res(1, v[i][j]);  
    while (i < n || j < n) {
        if (i == n) j++; 
        else if (j == n) i++;  
        else if (dp[i + 1][j] < dp[i][j + 1]) i++;
        else j++;

        res += v[i][j - 1];
    }

    cout << dp[n][n] << endl;

    cout << res << endl;

    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}