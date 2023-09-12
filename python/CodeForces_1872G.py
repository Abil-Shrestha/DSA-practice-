''' 
Given an array a of n positive integers. You need to perform the following operation exactly once:

Choose 2 integers l and r(1≤l≤r≤n) and replace the subarray a[l…r] with the single element: the product of all elements in the subarray (al⋅…⋅ar)
.
For example, if an operation with parameters l=2,r=4
 is applied to the array [5,4,3,2,1]
, the array will turn into [5,24,1]
.

Your task is to maximize the sum of the array after applying this operation. Find the optimal subarray to apply this operation.

Input
Each test consists of multiple test cases. The first line contains a single integer t(1≤t≤104) — the number of test cases. This is followed by the description of the test cases.

The first line of each test case contains a single number n(1≤n≤2⋅105) — the length of the array a
.

The second line of each test case contains n integers a1,a2,…,an(1≤ai≤109).

It is guaranteed that the sum of the values of n for all test cases does not exceed 2⋅105
.

Output
For each test case, output 2 integers l and r (1≤l≤r≤n) — the boundaries of the subarray to be replaced with the product.

If there are multiple solutions, output any of them. '''

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    MAXP = 2 * n
    prod = 1
    for x in a:
        prod *= x
        if prod > MAXP:
            break
    if prod > MAXP:
        l = 0
        r = n - 1
        while l < n and a[l] == 1:
            l += 1
        while r >= 0 and a[r] == 1:
            r -= 1
        print(l + 1, r + 1)
        continue
    not1 = []
    for i in range(n):
        if a[i] > 1:
            not1.append(i)
    maxval = 0
    l = 0
    r = 0
    for x in range(len(not1)):
        p = 1
        s = 0
        for y in range(x, len(not1)):
            i = not1[x]
            j = not1[y]
            p *= a[j]
            s += a[j] - 1
            if maxval <= p - s - (j - i + 1):
                maxval = p - s - (j - i + 1)
                l = i
                r = j
    print(l + 1, r + 1)