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

vector<string> grid;
const int N = 3001;
int visited[N][N];
int n;

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    IOS;

    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<pii> frontier;
    string res;

    res += grid[0][0];
    frontier.pb({0, 0});
    visited[0][0] = 1; 

    fori (k, 1, 2 * n - 1) {
        char mini = 'Z' + 1;
        
        for (auto p : frontier) {
            int row = p.first;
            int col = p.second;
            if (row + 1 < n) mini = min(mini, grid[row + 1][col]);
            if (col + 1 < n) mini = min(mini, grid[row][col + 1]);
        }
        
        res += mini;
        vector<pii> next_frontier;

        for (auto p : frontier) {
            int row = p.first;
            int col = p.second;
            
            if (row + 1 < n && grid[row + 1][col] == mini) {
                if (visited[row + 1][col] < k + 1) {
                    visited[row + 1][col] = k + 1;
                    next_frontier.pb({row + 1, col});
                }
            }
            
            if (col + 1 < n && grid[row][col + 1] == mini) {
                if (visited[row][col + 1] < k + 1) {
                    visited[row][col + 1] = k + 1;
                    next_frontier.pb({row, col + 1});
                }
            }
        }
        
        frontier = next_frontier;
    }

    cout << res << endl;

    return 0;
}