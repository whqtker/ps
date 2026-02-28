import sys

input=sys.stdin.readline

n,k=map(int,input().split())

coins=[]
for _ in range(n):
    coins.append(int(input()))

dp=[1e9]*(k+1) # dp[i]: i원 만드는 데 필요한 동전의 수
dp[0]=0

# 하나의 동전으로 만들 수 있는 금액에 대해 dp 초기화
for c in coins:
    cur=0
    for target in range(c,k+1,c):
        cur+=1
        dp[target]=min(dp[target],cur)

# k원을 만드는 두 금액 a,b (a+b=k) 경우 탐색
for tar in range(2,k+1):
    for i in range(tar//2):
        j=tar-i
        dp[tar]=min(dp[tar],dp[i]+dp[j])

print(-1 if dp[k]==1e9 else dp[k])