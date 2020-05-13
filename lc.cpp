#include <bits/stdc++.h>
using namespace std;

 string lp(string s) 
    {
        int n=s.length();
        if(n==0)
            return s;
        map<int,map<int,int> >dp;
        int max=1,sind=0,eind=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                {
                    dp[i][j]=1;
                    continue;
                }
                if(s[i]!=s[j])
                    dp[i][j]=0;
                else if(abs(i-j)==1)
                    dp[i][j]=2;
                else if(s[i]==s[j])
                {
                    if(dp[i+1][j-1]==0)
                        dp[i][j]=0;
                    else 
                        dp[i][j]=dp[i+1][j-1]+2;
                }
                if(dp[i][j]>max)
                {
                    max=dp[i][j];
                    sind=i;
                    eind=j;
                    
                }
            }
        }
            string w;
        for(int i=sind;i<=eind;i++)
            w+=s[i];
      
        return w;
    }
int main()
{
    string s;
    cin>>s;
    string w;
    w+=lp(s);
    cout<<w<<endl;
    return 0;
}
