class Solution(object):
  def integerReplacement(self, n):
    ans = 0
    while n > 1:
      if (n % 2) == 0:
        n >>= 1
      elif n == 3 or ((n >> 1) & 1) == 0:
        n -= 1
      else:
        n += 1
      ans += 1

    return ans