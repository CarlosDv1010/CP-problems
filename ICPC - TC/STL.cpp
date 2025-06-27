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
ostream & operator <<(ostream &os, const vector<T> &v) {
	os << "[";
	fori(i, 0, v.size()) {
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
	stack<int> st, comas;

	// 4 -> falta tipo,tipo>
	// 3 -> falta ,tipo>
	// 2 -> falta tipo>
	// 1 -> falta >

	int n;
	cin >> n;
	string s;
	string res;
	int processed_words = 0;
	while (cin >> s) {
	    processed_words++;
	    
		if (st.empty() && processed_words > 1) {
            cout << "Error occurred\n";
            return 0;
        }

		if (!st.empty() && st.top() == 1) {
			res += ',';
		}

		if (s == "pair") {
            res += "pair<";
            st.push(2); 
        } else { 
            res += "int";
            if (!st.empty()){
                st.top()--; 
            }
        }

		while (!st.empty() && st.top() == 0) {
			st.pop();
			res += '>';
			if (!st.empty()) {
				st.top()--;
			}
		}
	}

	if (!st.empty()){
        cout << "Error occurred\n";
        return 0;
    }

	if (res[res.size() - 1] == ',') res.pop_back();

	cout << res << endl;
#ifdef LOCAL
	cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
#endif

	return 0;
}