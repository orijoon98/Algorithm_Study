def special(n):
    for i in range(1, n+1):
        if i < 100: specials.add(i)
        else:
            a = str(i)
            dif = int(a[0]) - int(a[1]) 
            for j in range(len(a) - 1):
                if dif == int(a[j]) - int(a[j+1]):
                    if j == len(a) - 2:
                        specials.add(int(a))
                else:
                    break               
    print(len(specials))

N = int(input())
specials = set()

special(N)
