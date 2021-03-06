#pragma region Macros
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#pragma GCC target "sse4.2"
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size);  \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                       \
    vector<vector<type>> name(h, vector<type>(w)); \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...) \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
using namespace std;
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void yes(bool t = 1) { cout << yesno[t] << endl; }
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
#define si(c) (int)(c).size()
#define INT(...)     \
    int __VA_ARGS__; \
    IN(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    IN(__VA_ARGS__)
#define STR(...)        \
    string __VA_ARGS__; \
    IN(__VA_ARGS__)
#define CHR(...)      \
    char __VA_ARGS__; \
    IN(__VA_ARGS__)
#define DBL(...)        \
    double __VA_ARGS__; \
    IN(__VA_ARGS__)
int scan()
{
    return getchar();
}
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S>
void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T>
void scan(vector<T> &);
template <class T>
void scan(vector<T> &a)
{
    for (auto &i : a)
        scan(i);
}
template <class T>
void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &... tail)
{
    scan(head);
    IN(tail...);
}
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi iota(int n)
{
    vi a(n);
    iota(all(a), 0);
    return a;
}
template <typename T>
vi iota(vector<T> &a, bool greater = false)
{
    vi res(a.size());
    iota(all(res), 0);
    sort(all(res), [&](int i, int j) {
        if (greater)
            return a[i] > a[j];
        return a[i] < a[j];
    });
    return res;
}
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
template <class T>
T POW(T x, int n)
{
    T res = 1;
    for (; n; n >>= 1, x *= x)
        if (n & 1)
            res *= x;
    return res;
}
vector<pll> factor(ll x)
{
    vector<pll> ans;
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            ans.push_back({i, 1});
            while ((x /= i) % i == 0)
                ans.back().second++;
        }
    if (x != 1)
        ans.push_back({x, 1});
    return ans;
}
template <class T>
vector<T> divisor(T x)
{
    vector<T> ans;
    for (T i = 1; i * i <= x; i++)
        if (x % i == 0)
        {
            ans.pb(i);
            if (i * i != x)
                ans.pb(x / i);
        }
    return ans;
}
template <typename T>
void zip(vector<T> &x)
{
    vector<T> y = x;
    sort(all(y));
    for (int i = 0; i < x.size(); ++i)
    {
        x[i] = lb(y, x[i]);
    }
}
int popcount(ll x) { return __builtin_popcountll(x); }
int in()
{
    int x;
    cin >> x;
    return x;
}
ll lin()
{
    unsigned long long x;
    cin >> x;
    return x;
}

template <typename T>
struct edge
{
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;

using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T>
using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1)
{
    Tree res(n);
    if (m == -1)
        m = n - 1;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a -= margin, b -= margin;
        res[a].emplace_back(b);
        if (!directed)
            res[b].emplace_back(a);
    }
    return move(res);
}
template <class T>
Wgraph<T> getWg(int n, int m = -1, bool directed = false, int margin = 1)
{
    Wgraph<T> res(n);
    if (m == -1)
        m = n - 1;
    while (m--)
    {
        int a, b;
        T c;
        cin >> a >> b >> c;
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if (!directed)
            res[b].emplace_back(a, c);
    }
    return move(res);
}

#define i128 __int128_t
#define ull unsigned long long int
#define TEST        \
    INT(testcases); \
    while (testcases--)
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto it = begin(v); it != end(v); ++it)
    {
        if (it == begin(v))
            os << *it;
        else
            os << " " << *it;
    }
    return os;
}
template <class T, class S>
ostream &operator<<(ostream &os, const pair<T, S> &p)
{
    os << p.first << " " << p.second;
    return os;
}
template <class S, class T>
string to_string(pair<S, T> p) { return "(" + to_string(p.first) + "," + to_string(p.second) + ")"; }
template <class A>
string to_string(A v)
{
    if (v.empty())
        return "{}";
    string ret = "{";
    for (auto &x : v)
        ret += to_string(x) + ",";
    ret.back() = '}';
    return ret;
}

void dump() { cerr << endl; }
template <class Head, class... Tail>
void dump(Head head, Tail... tail)
{
    cerr << to_string(head) << " ";
    dump(tail...);
}
#define endl '\n'
#ifdef _LOCAL
#undef endl
#define debug(x)        \
    cout << #x << ": "; \
    dump(x)
#else
#define debug(x)
#endif

template <typename T>
static constexpr T inf = numeric_limits<T>::max() / 2;
struct Setup_io
{
    Setup_io()
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
#define drop(s) cout << #s << endl, exit(0)
#pragma endregion

//const int N = 300005;

int main()
{
    // ans 1 ******************
    /*
    INT(n);
    int c[10]{}, x, mn[3] = {10, 10, 10};
    while (n--)
    {
        x = in();
        c[x]++;
        mn[x % 3] = min(mn[x % 3], x);
    }
    if (!c[0])
    {
        puts("-1");
        exit(0);
    }
    int tar = 0; // 숫자 x 숫자의 개수
    rep(i, 10) tar = (tar + i * c[i]) % 3;
    if (tar)
    {
        if (mn[tar] < 10)
            c[mn[tar]]--;
        else
        {
            for (int i = 3 - tar, res = 2; res > 0; i += 3)
                while (res > 0 and c[i])
                {
                    c[i]--;
                    res--;
                }
        }
    }

    int pp = 0;
    // 특정 숫자 조합으로 조건성립하면
    // 숫자의 순서가 어떤순서여도 조건을 성립한다. 따라서
    rep3(i, 9, 1) while (c[i]--)
    {
        cout << i;
        pp = 1;
    }
    if (!pp) // 남은 c[1~9]가 한개도 없다면.. print 0
        c[0] = 1;
    while (c[0]--)
        cout << 0;
    */
    // ans 2 **************
    int n, x, c[10] = {};
    cin >> n;
    rep(i, n)
    {
        x = in();
        c[x]++;
    }
    if (!c[0])
        return puts("-1"), 0;
    int all = 0;
    rep(i, 10) all += i * c[i];
    // 하나 없애서 되는경우
    for (int i = 0; i < 10 && all % 3; i++)
        if (c[i] && (all - i) % 3 == 0)
            c[i]--, all -= i, n--;
    // 두개 없애야 하는 경우
    rep(i, 10) for (int j = 0; j < 10 && all % 3; j++) if (c[i] && c[j] && (i != j || c[i] > 1) && (all - i - j) % 3 == 0) c[i]--, c[j]--, all -= i + j, n -= 2;
    if (c[0] == n)
        return puts("0"), 0;
    rep3(i, 9, 0) while (c[i]--) cout << i;
    puts("");
    return 0;
}