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

const int N = 200005;
vector<tuple<int,int,ll>> v;
int n;

int search(int startday) {
    int r = n - 1;
    int l = 0;
    while (r - l > 1){
        int mid = (r + l) / 2;
        int curr_end = get<0>(v[mid]);
        if (curr_end >= startday){
            r = mid;
        }
        else {
            l = mid;
        } 
    }
    if (get<0>(v[l]) < startday) return l;
    return -1;
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    
    cin >> n;
    v.resize(n);

    fori (i, 0, n){
        int a, b, p;
        cin >> a >> b >> p;
        v[i] = {b, a, p};
    }

    sort (all(v));

    vpll dp(n + 1); // {beneficio, dia de finalización}
    dp[0] = {0, 0};
    ll res = 0;

    fori (i, 1, n + 1){
        dp[i] = dp[i - 1];
        int start = get<1>(v[i - 1]);
        
        int pos = search(start); // Posición a partir de la cual, 
        // todo a la izquierda tiene fecha de fin menor a la fecha de inicio de este proyecto
        dp[i] = max(dp[i], {get<2>(v[i - 1]) + dp[pos + 1].ff, get<0>(v[i - 1])});
        
        
        res = max(res, dp[i].ff);
    }

    cout << res << endl;    
    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}