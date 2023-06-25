class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char,int>mp;
        int count = 0;
        for(auto e : tasks)
        {
            mp[e]++;
            if(count > mp[e]) count = count;
            else count = mp[e];
        }
        
        int ans = (count-1)*(n+1);
        for(auto e : mp) if(e.second == count) ans++;
        if(ans > tasks.size()) return ans;
        return (int)tasks.size();
    }
};