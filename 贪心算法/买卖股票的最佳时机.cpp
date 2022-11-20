class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result{0};
        int index{0};
        while (index < prices.size()) {
            while (index < prices.size()-1 && prices[index+1] < prices[index]) {
                index++;
            }
            result -= prices[index];
            while (index < prices.size()-1 && prices[index+1] > prices[index]) {
                index++;
            }
            result += prices[index++];
        }
        return result;
    }
};