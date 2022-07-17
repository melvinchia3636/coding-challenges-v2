M, N = map(int, input().split())
[print("WELCOME".center(N, "-") if i == M//2 else ('.|.'*min(i*2+1, (M-i)*2-1)).center(N, "-")) for i in range(M)]
