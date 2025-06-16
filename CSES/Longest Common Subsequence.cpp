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
int a[N], b[N];
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
    fori (i, 0, n) cin >> a[i];
    fori (i, 0, m) cin >> b[i];

    vvi dp(n + 1, vi (m + 1, 0));

    rfori (i, n - 1, 0){
        rfori(j, m - 1, 0){
            if (a[i] == b[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
            else dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }

    int res = dp[0][0];
    cout << res << endl;

    int i = 0, j = 0;
    vector<int> v;

    while (i < n && j < m) {
        if (a[i] == b[j]) {
            v.push_back(a[i]);
            i++; j++;
        } else if (dp[i+1][j] >= dp[i][j+1]) {
            i++;
        } else {
            j++;
        }
    }

    for (auto elem: v){
        cout << elem << " ";
    }

    cout << endl;


    


            
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}