N = int(input())
H = list(map(int, input().split()))

count = 0
lst = []
for i in range(N): 
    lst.append(0)

while(H != lst):
    big = max(H)
    max_index = H.index(big)
    H[max_index] = 0
    for i in range(1, N):
        if (max_index + 1 < N and big - i >= 1):
            if big - i == H[max_index + 1]:
                H[max_index + 1] = 0
                max_index += 1
            else:
                max_index += 1
        else:
            break
    count += 1

print(count)


