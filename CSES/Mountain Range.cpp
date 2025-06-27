#pragma comment(linker, "/STACK:102400000,102400000") 
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


int main()
{
	IOS;
	int n;
	cin >> n;
	vpii v(n);
	vi l(n, -1), r(n, -1);
	fori (i, 0, n){
		cin >> v[i].ff;
		v[i].ss = i;
	}

	stack<int> st;

	fori (i, 0, n){
		while (!st.empty() && v[st.top()].ff <= v[i].ff){
			st.pop();
		}
		if (!st.empty()) l[i] = st.top();
		st.push(i);
	}

	while (!st.empty()) st.pop();

	rfori (i, n - 1, 0){
		while (!st.empty() && v[st.top()].ff <= v[i].ff){
			st.pop();
		}
		if (!st.empty()) r[i] = st.top();
		st.push(i);
	}

	sort(rall(v));

	vi dp(n + 1, 1);

	for (auto &[x, y] : v) {
        if (r[y] != -1) {
            dp[y] = max(dp[y], dp[r[y]] + 1);
        }
        if (l[y] != -1) {
            dp[y] = max(dp[y], dp[l[y]] + 1); 
        }
    }
	
	cout << *max_element(all(dp)) << endl; 

	return 0;
}