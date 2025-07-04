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
int n, m, k;
vvpii G;

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    cin >> n >> m >> k;
    priority_queue<pll, vpll, greater<pll>> pq;
    vvll dist (n + 1, vll(k + 1, INF));
    G.resize(n + 1);
    fori (i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({w, v});
    }

    pq.push({0LL, 1});
    dist[1][0] = 0;

    while (!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u][k - 1]) continue;        
        for (auto &[w, v]: G[u]){
            if (dist[v][k - 1] <= d + w) continue;
            dist[v][k - 1] = (d + w);
            sort(all(dist[v]));
            pq.push({d + w, v});
        }
    }

    fori (i, 0, k){
        cout << dist[n][i] << " ";
    }

    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}