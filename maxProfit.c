// 122. 买卖股票的最佳时机 II
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

int maxProfit(int* prices, int pricesSize){
    if(pricesSize < 1) return 0;

    int sum = 0;
    for(int i=1; i < pricesSize; i++){
        if(prices[i] > prices[i-1])
            sum += prices[i] - prices[i-1];
    }
    return sum;
}
