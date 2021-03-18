import sys
from collections import deque

n, k = [int(i) for i in sys.stdin.readline().split()]

d = [] 
v = dict()
for _ in range(2):
    d.append([int(i) for i in sys.stdin.readline().strip()])

q = deque()
q.append([0, 0, -1])
v[(0, 0)] = True

while q:
    line, x, time = q.popleft()

    newl, newx = (line + 1) % 2, x + k

    if newx >= n:
        print(1)
        sys.exit()
    if x <= time:
        continue
    if (newl, newx) not in v and d[newl][newx] == 1:
        q.append([newl, newx, time+1])
        v[(newl, newx)] = True

    newl, newx = line, x + 1
    if newx >= n:
        print(1)
        sys.exit()
    if x <= time:
        continue
    if (newl, newx) not in v and d[newl][newx] == 1:
        q.append([newl, newx, time+1])
        v[(newl, newx)] = True
    
    newl, newx = line, x - 1
    if newx >= n:
        print(1)
        sys.exit()
    if x <= time:
        continue
    if (newl, newx) not in v and d[newl][newx] == 1:
        q.append([newl, newx, time+1])
        v[(newl, newx)] = True

print(0)

