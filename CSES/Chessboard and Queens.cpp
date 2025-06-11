#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
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

bitset<8> reserved[8]; 
bitset<8> v[8];
bitset<15> rightDiag, leftDiag;

ll res = 0;

bool attack (int i, int j){
    if (v[i].any()) return true;
    if (rightDiag[i + j]) return true;
    if (leftDiag[i - j + 8]) return true;
    return false;
}

void f(int col){
    if (col == 8){
        res ++;
        return;
    }

    fori(i, 0, 8){
        if (attack(i, col) || reserved[i][col]) continue;
        v[i][col] = 1;
        rightDiag[i + col] = 1; 
        leftDiag[i - col + 8] = 1;
        f (col + 1);
        rightDiag[i + col] = 0;
        leftDiag[i - col + 8] = 0;
        v[i][col] = 0;
    }
}


int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    

    fori (i, 0, 8){
        string s;
        cin >> s;
        fori(j, 0, 8){
            if (s[j] == '*') reserved[i][j] = 1;
        }
    }

    f(0);

    cout << res << endl;    



    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}