class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counter(n+1,0);
        for ( int i =1; i <= n;i++){
            counter[i] = counter[i >> 1] + (i%2);
        }
        return counter;
    }
};