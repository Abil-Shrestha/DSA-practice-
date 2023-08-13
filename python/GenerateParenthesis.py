class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
      res = []
      stack = []
      def dfs(left,right):
        if left == right == n:
              res.append("".join(stack))
              stack.pop
        if left < n:
            stack.append("(")
            dfs(left+1,right)
            stack.pop()
        if right < left:
            stack.append(")")
            dfs(left,right+1)
            stack.pop()
      dfs(0,0)
      return res
