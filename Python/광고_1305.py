# 백준 1305 광고 시간초과 코드

size = int(input())
view = str(input())

def min_ad():
    for i in range(len(view)):
        ad_size = i + 1
        if(ad_size == len(view)):
            return(ad_size)
        else:
            for j in range(len(view)):
                if(j + ad_size < len(view)):
                    if(view[j] == view[j + ad_size]):
                        if((j + ad_size) == len(view) - 1):
                            return(ad_size)
                    else:
                        break

print(min_ad())

