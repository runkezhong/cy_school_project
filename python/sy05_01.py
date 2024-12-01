# 1.角谷猜想
def juegu(n: int):
    i = 0
    real_n = n
    while n!=1:
        if n%2==0:
            n = n/2
        else:
            n=n*3+1
        i+=1
    print(f"{real_n}经过{i}次变换后回到1")
    return i

juegu(25)