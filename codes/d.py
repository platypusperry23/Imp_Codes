
n=int(input())
arr = list(map(int,input().split()))
ls = -1
m=0
count=0
fl=0
for i in range(1,n):
    if arr[i]>ls:
        count+=1
        ls=arr[i]
    elif arr[i]<=ls and fl==0:
        fl=1
    else:
        if count > m:
            m=count
        if arr[i-1] < arr[i] :
            count=2
            ls=arr[i]
        else:
            count=1
            ls=arr[i]

if ((arr[n-1] > arr[n-2]) or (n > 2 and fl==1 and arr[n-3] < arr[n-1])):
    count+=1
    
if(count > m):
    m=count
print (m)