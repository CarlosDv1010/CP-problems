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
vector<string> v;

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    
    cin >> n >> m;
    pii a, b;
    v.resize(n);
    fori (i, 0, n) cin >> v[i];
    fori (i, 0, n){
        fori(j, 0, m){
            if (v[i][j] == 'A') a = {i, j};
            else if (v[i][j] == 'B') b = {i, j};
        }
    }
    
    queue<pii> q;
    vvpii p(n + 1, vpii (m + 1, {-1, -1}));
    q.push(a);
    p[a.ff][a.ss] = a;
    while (!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        if (i > 0 && v[i - 1][j] != '#' && p[i - 1][j].ff == -1) {q.push({i - 1, j}); p[i - 1][j] = {i, j};}
        if (i < n - 1 && v[i + 1][j] != '#' && p[i + 1][j].ff == -1) {q.push({i + 1, j}); p[i + 1][j] = {i, j};}
        if (j > 0 && v[i][j - 1] != '#' && p[i][j - 1].ff == -1) {q.push({i, j - 1}); p[i][j - 1] = {i, j};}
        if (j < m - 1 && v[i][j + 1] != '#' && p[i][j + 1].ff == -1) {q.push({i, j + 1}); p[i][j + 1] = {i, j};}
    }

    if (p[b.ff][b.ss].ff == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        pii curr = b;
        string res;
        while (p[curr.ff][curr.ss] != curr) {
            pii father = p[curr.ff][curr.ss];
            if (father.ff == curr.ff - 1) res += 'D';
            else if (father.ff == curr.ff + 1) res += 'U';
            else if (father.ss == curr.ss - 1) res += 'R';
            else if (father.ss == curr.ss + 1) res += 'L';
            curr = father;
        }
        reverse(res.begin(), res.end());
        cout << res.size() << endl << res << endl;
    }

    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}