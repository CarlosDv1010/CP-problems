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
vvi G;
vi toposort;
vi vis;

void dfs(int u){
    if (vis[u] == 2) return;
    vis[u] = 1;

    for (int v: G[u]){
        if (vis[v] == 2) continue;
        if (vis[v] == 1){
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        dfs(v);
    }

    vis[u] = 2;
    toposort.eb(u);
}


int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    int n, m;
    cin >> n >> m;
    G.resize(n + 1);
    vis.assign(n + 1, 0);
    vll dist (n + 1);
    vi p(n + 1, -1), dp (n + 1, -1);
    fori (i, 0, m){
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
    }

    fori (i, 1, n + 1){
        if (vis[i] == 2) continue;
        dfs(i);
    }

    reverse(all(toposort));

    dist[1] = 0;
    p[1] = 1;
    dp[1] = 1;

    for (int u: toposort){
        for (int v: G[u]){
            if (dp[v] < dp[u] + 1 && dp[u] != -1){
                dp[v] = dp[u] + 1;
                p[v] = u;
            }
        }
    }
    

    if (dp[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dp[n] << endl;

    int curr = n;
    vi res;

    while (p[curr] != curr){
        res.pb(curr);
        curr = p[curr];
    }

    res.pb(1);
    reverse(all(res));

    for (int elem: res) cout << elem << " ";
       
    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}