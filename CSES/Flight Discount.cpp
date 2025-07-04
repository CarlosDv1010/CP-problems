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

vvpll G;

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    cin >> n >> m;

    G.resize(2 * n + 1); // [0, n - 1] -> Nodos {i, F}
                       // [n , 2n - 1] -> Nodos {i, T}
    vll dist (2 * n + 1, INF);

    fori (i, 0, m){
        int u, v, x;
        cin >> u >> v >> x;
        G[u].push_back({x, v}); // Arista {u, F} -> {v, F}
        G[u].push_back({x/2, v + n}); // Arista {u, F} -> {v, T}
        G[u + n].push_back({x, v + n}); // Arista {u, T} -> {v, T}
    }

    priority_queue<pll, vpll, greater<pll>> q;
    q.push({0, 1});
    dist[1] = 0;

    while (!q.empty()){
        auto [d, u] = q.top();
        q.pop();
        if (d > dist[u]) continue;
        for (auto [dst, v]: G[u]){
            if (dist[v] <= dist[u] + dst) continue;
            dist[v] = dist[u] + dst;
            q.push({dist[v], v});
        }
    }

    cout << dist[2 * n] << endl;
    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}