class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        r = len(height)-1

        higher = 0
        water = 0 

        while l < r:
            if height[l] <= height[r]:
                lowlevel = height[l]
                l += 1
            else:
                lowlevel = height[r]
                r -= 1
            higher =  higher if higher > lowlevel else lowlevel
            water += higher - lowlevel
        return water