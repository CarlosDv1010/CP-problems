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

struct Node {
    int x;
    int y;

    bool operator == (const Node& other) const {
        return x == other.x && y == other.y;
    }

    bool operator != (const Node& other) const {
        return !(*this == other);
    }
};

Node a;
vector<vector<Node>> p;

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    cin >> n >> m;
    
    v.resize(n);
    p.resize(n, vector<Node>(m, {-1, -1}));
    vvi t(n + 1, vi(m + 1, INT_MAX));
    vector<Node> monsters;
    
    
    fori (i, 0, n){
        cin >> v[i];
        fori (j, 0, m){
            if (v[i][j] == 'A') a = {i, j};
            if (v[i][j] == 'M') monsters.pb({i, j});
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    queue<Node> q;
    for (Node monster: monsters) {
        q.push(monster);
        t[monster.x][monster.y] = 0;
    }

    while (!q.empty()){
        Node curr = q.front(); q.pop();
        fori (i, 0, 4){
            int new_x = curr.x + dx[i];
            int new_y = curr.y + dy[i];
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && v[new_x][new_y] != '#' && t[new_x][new_y] == INT_MAX) {
                t[new_x][new_y] = t[curr.x][curr.y] + 1;
                q.push({new_x, new_y}); 
            }
        }
    }    
    
    q.push(a);
    p[a.x][a.y] = a;

    Node final_exit = {-1, -1};
    bool path_found = false;
    int timer = 0;
    while (!q.empty()) {
        int sz = q.size();
    
        for (int i = 0; i < sz; ++i) {
            Node curr = q.front(); q.pop();
    
            if (v[curr.x][curr.y] != '#' &&
                (curr.x == 0 || curr.x == n - 1 || curr.y == 0 || curr.y == m - 1) &&
                t[curr.x][curr.y] > timer) {
                final_exit = curr;
                path_found = true;
                break;
            }
    
            fori(j, 0, 4) {
                int new_x = curr.x + dx[j];
                int new_y = curr.y + dy[j];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m &&
                    v[new_x][new_y] != '#' && v[new_x][new_y] != 'M') {
                    if (p[new_x][new_y].x == -1) {
                        p[new_x][new_y] = curr;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
    
        timer++;
    }

    if (!path_found) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    
    string res;
    Node curr = final_exit;
    
    while (p[curr.x][curr.y] != curr) {
        Node parent = p[curr.x][curr.y];
        if (parent.x == curr.x + 1) res += 'U';
        else if (parent.x == curr.x - 1) res += 'D';
        else if (parent.y == curr.y + 1) res += 'L';
        else if (parent.y == curr.y - 1) res += 'R';
        curr = parent;
    }
    reverse(all(res));
    cout << res.size() << endl;
    cout << res << endl;
    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}