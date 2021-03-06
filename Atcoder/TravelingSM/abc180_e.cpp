#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int inf = 1e9;
// constexpr int_64t inf = 1e18;
// const int N = 100 * 1000 + 5;
// const int mod = 1e9 + 7;

void Conpairu() {
    int n;
    cin >> n;
    vector<vi> cost(n, vi(n));
    // n^2
    vi x(n), y(n), z(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> z[i];
    }
    rep(i, n) rep(j, n) {
        cost[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0, z[i] - z[j]);
    }
    rep(k, n) rep(i, n) rep(j, n) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    }
    int k = 1 << n;
    vector<vi> dp(k, vi(n, inf));
    dp[1 << 0][0] = 0; // 어디서든 시작할수 있는게 아니니까.
    rep(i, k) rep(j, n) {
        if (dp[i][j] == inf)
            continue;
        rep(to, n) {
            if (i & (1 << to))
                continue;
            chmin(dp[i ^ (1 << to)][to], dp[i][j] + cost[j][to]);
        }
    }
    int ans = inf;
    rep(j, n) {
        chmin(ans, dp.back()[j] + cost[j][0]);
    }
    cout << ans << endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        Conpairu();
    }
    return 0;
}