#백준 2750

n = int(input())
nums = []

for i in range(n):
    nums.append(int(input()))

for i in range(1, n):
    while (i>0) & (nums[i] < nums[i-1]) :
        nums[i], nums[i-1] = nums[i-1], nums[i]
        i -= 1

for i in range(n):
    print(nums[i])