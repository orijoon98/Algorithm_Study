# 백준 1107 리모컨

N = int(input())
M = int(input())

if M != 0:
    broken = list(map(int, input().split()))
else:
    broken = []

answer = abs(N - 100)
for i in range(1000001):
    numArr = list(str(i))
    able = False

    for j in numArr:
        if int(j) in broken:
            able = True
            break
    
    if able:
        continue

    else:
        answer = min(answer, abs(N - i) + len(str(i)))

print(answer)
