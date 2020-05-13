#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a[n+1],b[n+1],las[n+1],lass[n+1];
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=-1;
        las[i]=-1;
        lass[i]=-1;
    }
    int q;
    cin>>q;
    long long r=q;
    long long bbb[r+5];
    int cc=0;
    bbb[r+1]=-1;
    while(q--)
    {
        cc++;
        int type;
        long long aa,bb;
        cin>>type;
        long long g;
        if(type==1)
        {
            g=-1;
            cin>>aa>>bb;
            las[aa]=bb;
            lass[aa]=cc;
        }
        else
        {
            cin>>aa;
            g=aa;
        }
        bbb[cc]=g;
    }
    for(i=r;i>=1;i--)
    {
        bbb[i]=max(bbb[i+1],bbb[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(las[i]==-1)
        {
            cout<<max(bbb[1],a[i])<<" ";
        }
        else
        {
            if(bbb[lass[i]+1]>=las[i])
            {
                cout<<bbb[lass[i]+1]<<" ";
            }
            else
                cout<<las[i]<<" ";
        }
    }
}
