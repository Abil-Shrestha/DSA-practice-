class Solution {
public:
    int minDistance(string word1, string word2) {
      int m = word1.length();
      int n = word2.length();
      if(m == 0) return n;
      if (n == 0) return m;
      int Arr[m+1][n+1];

      for(int i = 0; i<=m ; i++) Arr[i][0]=i;
      for(int i = 0; i<=n ; i++) Arr[0][i]=i;
      
      for(int i = 1; i<= m; i++){
        char first = word1[i-1];
        for(int j = 1; j<= n; j++){
          char second = word2[j-1];
          int cost = (first == second) ? 0 : 1;
          Arr[i][j] = min(min(Arr[i-1][j]+1,Arr[i][j-1]+1),Arr[i-1][j-1]+cost);
        }
      }
      return Arr[m][n];
    }
};