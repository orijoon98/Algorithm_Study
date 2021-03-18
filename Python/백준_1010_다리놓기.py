# 백준 1010번 다리놓기 실버5

def maxBridge(west, east):
# eastCwest 조합
    n_fac = factorial(east)
    r_fac = factorial(west)
    nr_fac = factorial(east - west)
    return n_fac//(nr_fac * r_fac)

def factorial(n):
    if(n == 1 or n == 0): 
        return 1
    return n * factorial(n-1)

case = int(input())

for i in range(case):
    west, east = map(int, input().split())
    print(maxBridge(west, east))

    

