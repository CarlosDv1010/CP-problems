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

bool valid(const string &s){
    ll sum = 0, num = 10, hyphens = 0;
    bool ans = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='X' && i!=s.size()-1) return false;
        else if(s[i]=='X') sum += 10 * num--;
        else if(s[i] != '-') sum += (s[i] - '0') * num--;
        else{
            hyphens++;
            if(num == 10 || num == 0 || s[i-1] == '-') return false;
        }
    }
    if((hyphens == 3 && s[s.size()-2] != '-') || hyphens > 3) return false;
    return num==0 && sum % 11 == 0;
}

string isbn13(string s) {
    string ans = "978-";
    string clean = "";

    for (ll i = 0; i < s.size()-1; i++) {
        if (s[i] != '-') {
            clean += s[i];
        }
        ans += s[i];
    }

    string nums = "978" + clean;
    ll sum = 0;
    for (ll i = 0; i < 12; i++) {
        ll digit = nums[i] - '0';
        sum += (i % 2 == 0) ? digit : 3 * digit;
    }
    ll checkDigit = (10 - (sum % 10)) % 10;
    ans += char('0' + checkDigit);
    return ans;
}


int main(){
    ll t;
    scanf("%lld", &t);
    for(int i = 0; i < t; i++){
        string old;
        cin >> old;
        if(valid(old)){
            cout << isbn13(old) << '\n';
        }
        else cout << "invalid" << '\n';
    }
    return 0;
}