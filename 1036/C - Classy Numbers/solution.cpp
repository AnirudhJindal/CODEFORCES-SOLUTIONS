#include <bits/stdc++.h>
using namespace std;
 
long long dp[20][4][2];
 
long long recurse(const string& lim,
                  int idx,
                  int count,
                  bool smaller) {
 
    if (count > 3)
        return 0;
 
    if (idx == lim.size())
        return 1;
 
    if (dp[idx][count][smaller] != -1)
        return dp[idx][count][smaller];
 
    long long ans = 0;
 
    if (smaller) {
 
        // Choose 0
        ans += recurse(
            lim,
            idx + 1,
            count,
            true
        );
 
        // Choose 1-9
        ans += 9 * recurse(
            lim,
            idx + 1,
            count + 1,
            true
        );
    }
 
    else {
 
        int digit = lim[idx] - '0';
 
        // Choose 0
        if (digit == 0) {
 
            ans += recurse(
                lim,
                idx + 1,
                count,
                false
            );
 
        } else {
 
            ans += recurse(
                lim,
                idx + 1,
                count,
                true
            );
        }
 
        // Choose 1 ... digit-1
        if (digit > 1) {
 
            ans += (digit - 1) *
                   recurse(
                       lim,
                       idx + 1,
                       count + 1,
                       true
                   );
        }
 
        // Choose exactly digit
        if (digit != 0) {
 
            ans += recurse(
                lim,
                idx + 1,
                count + 1,
                false
            );
        }
    }
 
    return dp[idx][count][smaller] = ans;
}
 
 
long long countClassy(long long x) {
 
    if (x < 0)
        return 0;
 
    string lim = to_string(x);
 
    memset(dp, -1, sizeof(dp));
 
    return recurse(lim, 0, 0, false);
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
 
        long long left, right;
        cin >> left >> right;
 
        cout << countClassy(right)
             - countClassy(left - 1)
             << '
';
    }
 
    return 0;
}