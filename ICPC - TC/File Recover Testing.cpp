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

int lps(string s){
    int n = s.size();
    vi lpsv(n);
    lpsv[0] = 0;

    int len = 0;
    int i = 1;

    while (i < n){
        if (s[i] == s[len]){
            len ++;
            lpsv[i] = len;
            i++;            
        }

        else {
            if (len != 0){
                len = lpsv[len - 1];
            }
            else {
                lpsv[i] = 0;
                i++;
            }
        }
    }

    return lpsv[n - 1];
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    int k;
    while (cin >> k && k != -1){
        string s;
        cin >> s;
        int n = s.size();

        int l = n == 1 ? 1: lps(s);

        int rpsz = n - l;

        if (k < n) cout << "0\n";
        else{
            int res = 1;
            k -= n;
            res += (k / max(rpsz,1));
            cout << res << endl;
        }



    }
    
        
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}