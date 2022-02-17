fibo = lambda n, c = [0, 1]: c if n == 2 else fibo(n-1, c+[c[-1]+c[-2]])

print(fibo(12))
