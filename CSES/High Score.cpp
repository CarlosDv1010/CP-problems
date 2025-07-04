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

struct Edge{
    int u, v;
    ll weight;
};

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    cin >> n >> m;
    vector<Edge> edges;
    vll dist (n + 1, INF);
    fori (i, 0, m){ 
        int u, v, x;
        cin >> u >> v >> x;
        edges.push_back({u,v,-x});
    }

    dist[1] = 0;

    fori (i, 0, n){
        for (auto edge: edges){
            if (dist[edge.u] == INF) continue;
            if (dist[edge.u] + edge.weight < dist[edge.v]){
                dist[edge.v] = dist[edge.u] + edge.weight;
                if (i == n - 1) dist[edge.v] = -INF; 
            }
        }
    }

    vll res = dist;
    
    fori (i, 0, n){
        for (auto edge: edges){
            if (dist[edge.u] == -INF) {
                dist[edge.v] = -INF;
            } 
        }
    }
    
    
    if (dist[n] == -INF){
        cout << -1 << endl;
    }
    else{
        cout << -res[n] << endl;
    }
    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}