# 백준 요세푸스 1158번

n, k = map(int,input().split())
nums = []
yp = []

for i in range(n):
    nums.append(i+1)

index = k-1

while(len(nums) > 0):
    yp.append(nums[index])
    nums.remove(nums[index])
    index += (k-1)
    if(index > (len(nums) - 1)):
        while(True):
            index -= len(nums)  
            if((index <= len(nums) - 1) or (len(nums) == 0)): 
                break

print(yp)

# answer = ""
# answer += "<"
# for i in range(len(yp)-1):
#     answer += str(yp[i])
#     answer += ", "
# answer += str(yp[len(yp)-1])
# answer += ">"
# print(answer)
