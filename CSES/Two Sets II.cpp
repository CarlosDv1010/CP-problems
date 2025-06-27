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


int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    IOS;

    ll n;
    cin >> n;

    const ll maxsum = n * (n + 1) / 2;
    if (maxsum & 1) {
        cout << 0 << endl;
        return 0;
    }

    ll target = maxsum / 2;

    vll curr (target + 1, 0);
    vll prev (target + 1, 0);

    fori (i, 1, n + 1){
        prev[0] = 1;
        fori (j, 1, target + 1){
            curr[j] = prev[j];
            if (j - i >= 0) curr[j] += prev[j - i];
            curr[j] %= MOD;
        }
        swap(prev, curr);
    }

    cout << (prev[target] * ((MOD + 1) / 2)) % MOD << endl;

    return 0;
}