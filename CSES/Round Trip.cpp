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
vvi G;
vi dist, p;


int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    cin >> n >> m;
    G.resize(n + 1);
    dist.assign(n + 1, -1);
    p.assign(n + 1, -1);
    fori (i, 0, m){
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    int start = -1;
    vi res;

    fori (i, 1, n + 1){
        if (dist[i] == -1){
            queue<int> q;
            q.push(i);
            dist[i] = 0;

            while (!q.empty()){
                int u = q.front();
                q.pop();

                for (int v: G[u]){
                    if (dist[v] == -1){
                        dist[v] = dist[u] + 1;
                        p[v] = u;
                        q.push(v);
                    }
                    else if (v != p[u]) {
                        vi path_u, path_v;
                        int x = u, y = v;
                        while (x != y){
                            if (dist[x] > dist[y]){
                                path_u.pb(x);
                                x = p[x];
                            } else {
                                path_v.pb(y);
                                y = p[y];
                            }
                        }
                        path_u.pb(x);
        
                        reverse(all(path_v));
                        for (int node : path_v) path_u.pb(node);
                        path_u.pb(path_u[0]);
        
                        cout << path_u.size() << endl;
                        for (int node : path_u) cout << node << " ";
                        cout << endl;
                        return 0;
                    } 
                }
            }
        }        
    }

    cout << "IMPOSSIBLE\n";



    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}