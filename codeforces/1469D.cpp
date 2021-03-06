#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
using namespace std;
#define INT(...)     \
    int __VA_ARGS__; \
    IN(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size);  \
    IN(name)
int scan() { return getchar(); }
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
void scan(vector<T> &a) {
    for (auto &i : a)
        scan(i);
}
template <class T>
void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &...tail) {
    scan(head);
    IN(tail...);
}
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        INT(n);
        vector<pi> ans;
        while (n > 2) {            //ceil round floor 올림 반올림 내림
            int s = ceil(sqrt(n)); //sqrt 제곱근.
            for (int i = s + 1; i < n; ++i) {
                ans.emplace_back(i, i + 1);
            }
            ans.emplace_back(n, s);
            ans.emplace_back(n, s);
            n = s;
        }
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
            cout << x << " " << y << '\n';
        } // 나와 매우 흡사하나. 제곱수를 따로저장하지않고
    }     // 내장함수를 사용하여 깔끔하게 처리함.
    return 0;
}
/* my answer
        INT(n);
        // ceiling function (올림)
        vector<ll> data;
        ll mx = 2;
        while (n > mx) {
            data.push_back(mx);
            mx = mx * mx;
        }
        cout << n - 2 + data.size() << '\n';

        sort(data.rbegin(), data.rend());
        for (auto i : data) {
            rep2(j, i + 1, n - 1) {
                cout << j << " " << n << '\n';
            }
            cout << n << " " << i << '\n';
            cout << n << " " << i << '\n';
            n = i;
        }
*/