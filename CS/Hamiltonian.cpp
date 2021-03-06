// visits every node at ``least ONCE``
// and return to start. with shortest path(cost) ..
// similar to dijkstra but different.

// Also known as Travelling Salesman Problem.

// Since it is Very hard problem if given large input(NP hard)
// These problems are given with
//     !!``LOW INPUT VALUE constraint``!!

// naive approach will take O(n!)
// with will be time consuming.. (google 17! for this)
// Using DP it reduces to big O of O(n^2 * 2^n)
// this way is much faster for large inputs like 16 or 17..

// 2^n is for set of visited nodes. use 32-bit integer. 32 is enough
// n^2 of one n is for last visited node

// Basically it is DP.. just DP.

vector<vector<int>> dp(1 << k, vector<int>(k, inf));
// 1 << k for path. k for end node.
rep(i, k) dp[1 << i][i] = 1;             // initialize
for (int bit = 1; bit < 1 << k; bit++) { // path
    for (int i = 0; i < k; i++)
        if (bit & 1 << i) {          // if started from i
            int bit2 = bit ^ 1 << i; // path until now. except start
            for (int j = 0; j < k; j++)
                if (bit2 & 1 << j) {
                    chmin(dp[bit][i], dp[bit2][j] + cost[i][j]);
                    // e.g. path 0110(bit2) with starting in 0010(j)
                    // + the cost from (0001)i to (0010)j equals
                    // path 0111(bit) with starting in 0001(i);
                }
        }
}
int ans = *min_element(dp.back().begin(), dp.back().end());
// dp.back() ,, for visiting every node.
// from begin to end. for every starting node.

//another example with START in 0 END in 0;
int k = 1 << n;
vector<vi> dp(k, vi(n, inf));
dp[1 << 0][0] = 0; // 어디서든 시작할수 있는게 아니니까.
rep(i, k) rep(j, n) {
    if (dp[i][j] == inf)
        continue;
    rep(to, n) {
        if (i & (1 << to)) // chmin(dist[i][j], dist[i][k] + dist[k][j])
            continue;      //이거 미리 해놔서 돌아갔다 가는거 생략하는거다!
        chmin(dp[i ^ (1 << to)][to], dp[i][j] + cost[j][to]);
    }
}
int ans = inf;
rep(j, n) {
    chmin(ans, dp.back()[j] + cost[j][0]);
}