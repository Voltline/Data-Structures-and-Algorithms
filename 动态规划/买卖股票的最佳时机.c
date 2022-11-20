int maxProfit(int* prices, int pricesSize){
    int dp[pricesSize][2];
    dp[0][1] = -prices[0];
    dp[0][0] = 0;
    for (int i = 1; i < pricesSize; i++) {
        dp[i][0] = dp[i-1][0] > dp[i-1][1] + prices[i] ? dp[i-1][0] : dp[i-1][1] + prices[i];
        dp[i][1] = dp[i-1][0]-prices[i] > dp[i-1][1] ? dp[i-1][0]-prices[i] : dp[i-1][1];
    }
    return dp[pricesSize-1][0] > dp[pricesSize-1][1] ? dp[pricesSize-1][0] : dp[pricesSize-1][1];
}