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
int a[N];

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        clock_t T = clock();
    #endif
    IOS;
    int n, x;
    cin >> n >> x;

    map<int, int> mp;

    fori(i, 0, n){
        cin >> a[i];
        mp[a[i]]++;
    }

    if (n == 1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    bool found = false;

    fori(i, 0, n){
        int num1 = a[i];
        int num2 = x - a[i];
        if (num1 >= x) continue;
        if (num1 == num2 && mp[num1] > 1) {
            int pos1 = -1, pos2 = -1;
            fori (i, 0, n){
                if (a[i] == num1 && pos1 != -1){
                    pos2 = i;
                    break;
                }
                if (a[i] == num1 && pos1 == -1){
                    pos1 = i;
                }                
            }

            cout << pos1 + 1 << " " << pos2 + 1 << endl;
            found = true;
            break; 
        }
        if (mp[num2] >= 1){
            int pos2 = -1;
            fori(j, 0, n){
                if (i == j) continue;
                if (a[j] == num2){
                    pos2 = j;
                    break;
                }
            }
            if (pos2 == -1) continue;
            cout << i + 1 << " " << pos2 + 1 << endl;
            found = true;
            break;
        }
    } 

    if (!found){
        cout << "IMPOSSIBLE\n";
    }

    
    
    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}