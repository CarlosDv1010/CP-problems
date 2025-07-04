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
vi p;


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
    p.resize(n + 1, -1);
    fori (i, 0, m){
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    queue<int> q;
    q.push(1);
    p[1] = 1;
    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (int v: G[u]){
            if (p[v] == -1){
                q.push(v);
                p[v] = u;
            } 
        }
    }

    vi res;
    int curr = n;

    if (p[n] == -1) {
        cout << "IMPOSSIBLE\n" << endl;
        return 0;
    }
    
    res.pb(n);

    while (p[curr] != curr){
        curr = p[curr];
        res.pb(curr);
    }
    
    reverse(all(res));

    cout << res.size() << endl;
    fori (i, 0, res.size()) cout << res[i] << " ";
    cout << endl;


    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}