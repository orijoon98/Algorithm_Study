#평행사변형
import math

points = list(map(int, input().split()))
length = []
perimeter = []

if(points[0] == points[2] and points[2] == points[4]):
    print(-1)
else:
    if(points[0] != points[2] and points[2] != points[4]):
        a = (points[3] - points[1]) / (points[2] - points[0])
        b = (points[5] - points[3]) / (points[4] - points[2])
        if(a == b):
            print(-1)
        else:
            a = math.sqrt(math.pow(points[3] - points[1], 2) + math.pow(points[2] - points[0], 2))
            b = math.sqrt(math.pow(points[5] - points[3], 2) + math.pow(points[4] - points[2], 2))
            c = math.sqrt(math.pow(points[5] - points[1], 2) + math.pow(points[4] - points[0], 2))
            length.append(a)
            length.append(b)
            length.append(c)
            length.sort()
            a = length[0]
            b = length[1]
            c = length[2]
            perimeter.append(2*(a+b))
            perimeter.append(2*a + 2*c)
            perimeter.append(2*b + 2*c)
            print(max(perimeter) - min(perimeter))
    else:
        a = math.sqrt(math.pow(points[3] - points[1], 2) + math.pow(points[2] - points[0], 2))
        b = math.sqrt(math.pow(points[5] - points[3], 2) + math.pow(points[4] - points[2], 2))
        c = math.sqrt(math.pow(points[5] - points[1], 2) + math.pow(points[4] - points[0], 2))
        length.append(a)
        length.append(b)
        length.append(c)
        length.sort()
        a = length[0]
        b = length[1]
        c = length[2]
        perimeter.append(2*(a+b))
        perimeter.append(2*a + 2*c)
        perimeter.append(2*b + 2*c)
        print(max(perimeter) - min(perimeter))
