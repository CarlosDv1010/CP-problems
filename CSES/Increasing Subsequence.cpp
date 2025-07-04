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
 
const ll MOD = 998244353;
const ll INF = 1e18 + 1;
const ld EPS = 1e-9;
 
  
int main()
{
    int n;
    cin >> n;

    vi v(n);
    vi lis;
    fori (i, 0, n) cin >> v[i];
    lis.pb(v[0]);

    fori (i, 1, n) { 
        int pos = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        if ((pos >= lis.size() && v[i] > lis[pos - 1]) || (pos < lis.size() && lis[pos] < v[i])) {
            lis.pb(v[i]);
            continue;
        }
        lis[pos] = v[i];
    }

    cout << lis.size() << endl;



    cout << "\n";
}