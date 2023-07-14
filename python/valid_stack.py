class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        n = len(popped)
        i = 0
        for num in pushed:
            stack.append(num)
            while stack and i < n and stack[-1]== popped[i]:
                stack.pop()
                i += 1
        return i == len(popped)