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

const int N = 26;

int a[N];

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    string s;
    cin >> s;

    fori (i, 0, N) a[i] = 0;

    fori(i, 0, s.size()) {
        a[s[i] - 'A']++;
    }

    int odd = 0;
    
    fori(i, 0, N) {
        if (a[i] == 0) continue;
        if (a[i] & 1) odd++;     
    }

    if (odd > 1 || (s.size() % 2 == 0 && odd >= 1)){
        cout << "NO SOLUTION\n";
        return 0;
    }

    string res;
    char middle = 0;

    fori(i, 0, N){
        if (a[i] %2 == 1) middle = 'A' + i;
        int ocurr = a[i]/2;
        if (!ocurr) continue;
        char c = 'A' + i;
        fori (j, 0, ocurr){
            res += c;
        }
    }

    if (middle)res += middle;
    string half = res;

    int lim = (s.size() & 1)? res.size() - 2: res.size() - 1; 
    rfori (i, lim, 0){
        res += half[i];
    }

    cout << res << endl;


    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}