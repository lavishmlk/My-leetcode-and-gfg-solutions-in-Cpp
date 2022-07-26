//lec9
//earlier method was easier
// Memoization - Approach 2
// Time - O(Amount * Coins), Space - O(Amount * Coins) for DP table
// Recursion Call Stack -> O(Coins) Height, O(Amount) Calls/Breadth
//we are considering whether coin will come or not and if it will come should we take 1 or 2 coins or 3 coins etc
//2 variable states therefore 2 base cases
class Solution {
    
        public int memo(int amount, int idx, int[] coins, int[][] dp) {
        if (amount == 0)
            return 0;
        if (idx == coins.length)
            return Integer.MAX_VALUE;
        if (dp[amount][idx] != -1)
            return dp[amount][idx];

        int minCoins = Integer.MAX_VALUE;
        for (int coin = 0; amount >= coins[idx] * coin; coin++) {
            int ans = memo(amount - coins[idx] * coin, idx + 1, coins, dp);
            if (ans < Integer.MAX_VALUE)
                ans += coin;
            minCoins = Math.min(minCoins, ans);
        }

        return dp[amount][idx] = minCoins;
    }
    
    public int coinChange(int[] coins, int amount) {
                int[][] dp = new int[amount + 1][coins.length];
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                dp[i][j] = -1;
            }
        }

        int ans = memo(amount, 0, coins, dp);
        if (ans == Integer.MAX_VALUE)
            return -1;
        return ans;
    }
}