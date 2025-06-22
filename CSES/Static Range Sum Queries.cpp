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
    ll sum;
    Data() { sum = 0;} // Neutro
    void merge (const Data& left, const Data& right) { // Construir al padre de acuerdo a los hijos
        sum = left.sum + right.sum;
    }
};

struct Lazy{
    ll add = 0;
    Lazy() {} // Neutro
    Lazy(ll sum) {add = sum;}
    void updateData (Data &data, int datalength) const { // Actualiza los datos producto de realizar la operación
        data.sum += datalength * add;  
    } 
    pair<Lazy, Lazy> split (int leftchildsize) const { // Hace el split de la operación 
        return {*this, *this};
    }
    void updateLazy (const Lazy& newOperation) { // Actualiza la operación actual cuando se realiza una nueva
        add += newOperation.add;
    }
};


struct Node{
    Data data;
    Lazy lazy;
};

struct SegmentTree
{
    Node st[4 * maxn];
    int size;    

    struct NodeIndex {
        int index, l, r; // Intervalo [l, r)
        NodeIndex left() const {return {index * 2, l, mid()};};
        NodeIndex right() const {return {index * 2 + 1, mid(), r};};
        int mid() const {return (l + r) / 2;}
        int size() const {return r - l;}
        bool disjoint (int queryl, int queryr) const {return queryl >= r || queryr <= l;}
        bool full (int queryl, int queryr) const {return queryl <= l && queryr >= r;}
    };

    Node* preinit(int n){ // Retorna puntero al primer nodo hoja 
        size = 1;
        while (size < n) size *= 2;
        fori (i, 0, 2 * size) st[i] = Node();
        return st + size;
    }

    void init() { // Construir el segment tree. De adelante hacia atrás 
        // porque primero se mergean las hojas y ahí se va subiendo en el árbol. st[size] contiene la primera hoja.
        rfori(i, size - 1, 0) st[i].data.merge(st[i * 2].data, st[i * 2 + 1].data);
    }

    void updateNode(const NodeIndex &node, const Lazy &lazy){ // Aplica la operación a un nodo en particular
        st[node.index].lazy.updateLazy(lazy);
        lazy.updateData(st[node.index].data, node.size());
    }

    void propagate (const NodeIndex &node){ // Divide la aplicación de la operación lazy a los hijos
        // de acuerdo con el split. Como ya se aplica a los hijos, el padre se "reinicia". Propiedad asociativa.
        pair<Lazy, Lazy> childrenLazy = st[node.index].lazy.split(node.size() / 2);
        updateNode(node.left(), childrenLazy.ff);
        updateNode(node.right(), childrenLazy.ss);
        st[node.index].lazy = Lazy();
    }

    Data process(const NodeIndex &node, int queryl, int queryr, const Lazy &lazy){
        if (node.disjoint(queryl, queryr)) return Data();
        if (node.full(queryl, queryr)) {
            updateNode(node, lazy);
            return st[node.index].data;
        }
        propagate(node); // Actualizar la parte relevante del lazy para el update/query
        int mid = node.mid();
        Data leftData, rightData; // Parte para queries
        if (queryl < mid && queryr > mid){
            auto splitLazy = lazy.split(mid - queryl);
            leftData = process(node.left(), queryl, mid, splitLazy.ff);
            rightData = process(node.right(), mid, queryr, splitLazy.ss);
        }
        else {
            leftData = process(node.left(), queryl, queryr, lazy);
            rightData = process(node.right(), queryl, queryr, lazy);
        }
        st[node.index].data.merge(st[2 * node.index].data, st[2 * node.index + 1].data);
        Data res;
        res.merge(leftData, rightData);
        return res; // Se devuelve el resultado de la query. Innecesario para updates
    }
    NodeIndex root(){return {1, 0, size};}
    Data update (int queryl, int queryr, const Lazy &lazy ){return process(root(), queryl, queryr, lazy);}
    Data query (int queryl, int queryr) {return process(root(), queryl, queryr, Lazy());}
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
    Node* v = segmentTree.preinit(n); // Apuntador al primer nodo hoja
    fori (i, 0, n){
        cin >> v[i].data.sum; // Esto es igual a acceder a la posición v + i, es decir, a la iesima hoja
    }
    segmentTree.init();
    
    fori (i, 0, q){
        int l, r;
        cin >> l >> r;
        auto res = segmentTree.query(l - 1, r);
        cout << res.sum << endl;
    }
    
    
    
    #ifdef LOCAL
        cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
    #endif

    return 0;
}