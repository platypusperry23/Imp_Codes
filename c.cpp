n=int(input())
a=list(map(int,input().split()))

pre=[1 for i in range(n)]
suf=[1 for i in range(n)]
maxa=1

for i in range(1,n):
    if a[i]>a[i-1]:
        pre[i]+=pre[i-1]
    maxa=max(maxa,pre[i])

for i in range(n-2,-1,-1):
    if a[i]<a[i+1]:
        suf[i]+=suf[i+1]

    maxa=max(maxa,suf[i])

for i in range(1,n-1):
    if a[i-1]<a[i+1]:
        maxa=max(maxa,pre[i-1]+suf[i+1])

print(maxa)
