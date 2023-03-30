class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int m = 0;
        int min = INT_MAX;
        for(int i=0;i<n;i++){
            if(prices[i] < min){
                min=prices[i];
            } else{
                m=max(m,prices[i]-min);
            }
        }
        return m;
    }
};