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

const int maxn = 200005;

struct Data{
    ll mini;
    Data() { mini = INT_MAX;}
    void merge (const Data& left, const Data& right) { 
        mini = min(left.mini, right.mini);
    }
};

struct Node{
    Data data;
};

struct SegmentTree
{
    Node st[4 * maxn];
    int size;    

    struct NodeIndex {
        int index, l, r;
        NodeIndex left() const {return {index * 2, l, mid()};};
        NodeIndex right() const {return {index * 2 + 1, mid(), r};};
        int mid() const {return (l + r) / 2;}
        int size() const {return r - l;}
        bool disjoint (int queryl, int queryr) const {return queryl >= r || queryr <= l;}
        bool full (int queryl, int queryr) const {return queryl <= l && queryr >= r;}
    };

    Node* preinit(int n){ 
        size = 1;
        while (size < n) size *= 2;
        fori (i, 0, 2 * size) st[i] = Node();
        return st + size;
    }

    void init() { 
        rfori(i, size - 1, 0) st[i].data.merge(st[i * 2].data, st[i * 2 + 1].data);
    }

    Data process(const NodeIndex &node, int queryl, int queryr){
        if (node.disjoint(queryl, queryr)) return Data();
        if (node.full(queryl, queryr)) {
            return st[node.index].data;
        }
        int mid = node.mid();
        Data leftData, rightData; 
        if (queryl < mid && queryr > mid){
            leftData = process(node.left(), queryl, mid);
            rightData = process(node.right(), mid, queryr);
        }
        else {
            leftData = process(node.left(), queryl, queryr);
            rightData = process(node.right(), queryl, queryr);
        }
        st[node.index].data.merge(st[2 * node.index].data, st[2 * node.index + 1].data);
        Data res;
        res.merge(leftData, rightData);
        return res;
    }
    NodeIndex root(){return {1, 0, size};}
    Data query (int queryl, int queryr) {return process(root(), queryl, queryr);}
};
 
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
    int n, q;
    cin >> n >> q;
    SegmentTree segmentTree;
    Node* v = segmentTree.preinit(n);
    fori (i, 0, n) cin >> v[i].data.mini;
    segmentTree.init();

    fori (i, 0, q){
        int l, r;
        cin >> l >> r;
        int res = segmentTree.query(l - 1, r).mini;
        cout << res << endl;
    }

    
    
    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}