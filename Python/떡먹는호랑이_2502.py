def fibo_a(n):
    if(n == 1):
        return 1
    elif(n == 2):
        return 0
    elif(n == 3):
        return 1
    else:
        return fibo_a(n-1) + fibo_a(n-2)

def fibo_b(n):
    if(n == 1):
        return 0
    elif(n == 2):
        return 1
    else:
        return fibo_b(n-1) + fibo_b(n-2)

day, riceCake = map(int, input().split())
save = riceCake
a = fibo_a(day)
b = fibo_b(day)

while(True):
    n = riceCake//b
    for i in range(1, n+1):
        riceCake = save
        riceCake -= b*i
        if riceCake % a == 0:
            answer_a = riceCake // a
            answer_b = i
            if(answer_a <= answer_b):
                print(answer_a)
                print(answer_b)
                break
    break




