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

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;

    int t;
    cin >> t;
    while (t--){
        int x, n, m;
        cin >> x >> n >> m;        

        int its = 70;

        int cur = x;
        int curn = n, curm = m;
        int minx = x;
        while ((curn > 0 || curm > 0) && minx > 0 && its--) {
            if (curm > 0) {
                minx = (minx + 1) / 2;
                curm--;
            } else if (curn > 0) {
                minx = minx / 2;
                curn--;
            }
        }

        if (minx == 1 && curn) minx = 0; 

        curn = n, curm = m;
        its = 70;
        int maxx = x;
        while ((curn > 0 || curm > 0) && maxx > 0 && its--) {
            if (curn > 0) {
                maxx = maxx / 2;
                curn--;
            } else if (curm > 0) {
                maxx = (maxx + 1) / 2;
                curm--;
            }
        }

        if (maxx == 1 && curn) maxx = 0; 

        cout << minx << " " << maxx << '\n';
    }

    
        
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}