#연금술사 백준 19857
import sys

def MEX_bool(n):
    if n == 0:
        if len(stones) >= 1: return True
        else: return False
    elif n == 1:
        if 0 in stones: return True
        else: 
            if MEX_bool(0): return True
            else: return False
    else:
        for i in range(n):
            if i not in stones:
                if(MEX_bool(i)): 
                    MEX(i)
                    if(i == n-1): return True
                else: return False 
            if i == n - 1 : return True

def MEX(n):
    if n == 0:
        stones.remove(stones[-1])
        if 0 in MEXed:
            stones.append(0)
        else:    
            MEXed.append(0)
        
    elif n == 1:
        if 0 not in stones:
            if(MEX_bool(0)): MEX(0)
            MEXed.remove(0)
            MEXed.append(n)
        else:
            stones.remove(0)
            MEXed.append(n)
    else:
        for i in range(n):
            if i not in stones:
                if(MEX_bool(i)): 
                    MEX(i)
                else:
                    MEXed.sort()
                    print(MEXed[-1] + 1)
                    sys.exit()
            if i == n - 1 : 
                for a in range(n):
                    if a in stones:
                        stones.remove(a)
                    else:
                        MEXed.sort()
                        print(MEXed[-1] + 1)
                        sys.exit()
                MEXed.append(n)

N = int(input())
stones_number = list(map(int, input().split()))
stones = []
MEXed = [] 
stones_size = sum(stones_number)

i = 0

for stone in stones_number:
    for _ in range(stone):
        stones.append(i)
    i +=1

if len(stones) == 1 : 
    if(stones[0] == 0): print(1)
    else:
        print(stones[0])
else:
    for i in range(stones_size):
        if i in stones:
            stones.remove(i)
            MEXed.append(i)
        else:
            if(MEX_bool(i)):
                MEX(i)
            else:
                print(i)
                sys.exit()
