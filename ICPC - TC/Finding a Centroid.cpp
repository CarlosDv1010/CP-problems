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

vi children, vis;
vvi G;
int n;

int dfs(int node) {
    vis[node] = 1;
    int size = 1;

    for (int v : G[node]) {
        if (!vis[v]) {
            size += dfs(v);
        }
    }

    children[node] = size;
    return size;
}

int centroid(int u, int p = -1) {
    for (int v : G[u]) {
        if (v != p && children[v] > n / 2) {
            return centroid(v, u);
        }
    }
    return u;
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
    G.resize(n + 1);
    children.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    
    fori (i, 0, n - 1){
        int u, v;
        cin >> u >> v;
        G[u].eb(v);
        G[v].eb(u);
    }

    dfs(1);

    int cnt = centroid(1);

    cout << cnt << endl;
    
        
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}