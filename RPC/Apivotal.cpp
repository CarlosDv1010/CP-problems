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

const int N = 1000005;
int a[N];


int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    int n;
    cin >> n;
    fori (i, 1, n + 1){
        cin >> a[i];
    }

    vi suffix(n + 2);
    vi pref(n + 1);
    vi res;
    suffix[n + 1] = INT_MAX;
    pref[0] = -1;

    fori(i, 1, n + 1){
        pref[i] = max(pref[i - 1], a[i]);
    }

    rfori(i, n, 1){
        suffix[i] = min(suffix[i + 1], a[i]);
    }

    fori(i, 1, n + 1){
        if (suffix[i + 1] > a[i] && pref[i - 1] < a[i]) res.eb(a[i]);
    }

    cout << res.size();

    int lim = min((int)res.size(), 100);

    if (lim > 0) {
        cout << " "; 
        fori (i, 0, lim) {
            cout << res[i] << (i == lim - 1 ? "" : " ");
        }
    }

    cout << endl;

    return 0;
}