num = int(input())

yksoo = list(map(int, input().split()))
yksoo = sorted(yksoo)

if(num % 2 == 0):
    N = yksoo[0] * yksoo[num - 1]
else:
    index = num//2
    N = yksoo[index] * yksoo[index]

print(N)
