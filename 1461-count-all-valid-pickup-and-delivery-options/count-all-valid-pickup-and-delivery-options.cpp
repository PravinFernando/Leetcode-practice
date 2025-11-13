class Solution {
public:
    int countOrders(int n) {
        const int MOD = 1000000007;
        long long res = 1;

        for (int slot = 1; slot <= 2 * n; slot++) {
            res *= slot;
            if (slot % 2 == 0) {
                res >>= 1;
            }
            res %= MOD;
        }
        return (int) res;
    }
};