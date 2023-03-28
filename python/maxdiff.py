class Solution(object):
    def maxProfit(self, prices):
        diff = 0
        n = len(prices)
        if ( n==0 ):
            return diff
        for i in range(n):
            for j in range(i+1,n):
                if prices[j]>prices[i]:
                    diff=max(diff,prices[j]-prices[i])

        
        return diff
