
# include <bits/stdc++.h>
using namespace std;
#define ll        long long 
#define pb     	  push_back	

int main()
{
	ios_base::sync_with_stdio(false); 
	
	cin.tie(NULL); 
	
	cout.tie(NULL);

	ll t,n;                    
	cin>>t;
	while(t--)
	{	
		cin>>n;
		
		vector<ll>v;
		v.pb(-1);
		for(ll i=1;i<=n;i++)
		  {
		  	ll x;
		  	cin>>x;
		  	v.pb(x);
		  }
		ll odd=0,e1=0,ei=0,te=0,ans=0,ze=0;
		for(int i=1;i<=n;i++)
			{
				if(i==1)
				{
					if(v[i]%2==0 && v[i]!=0)
					{
						if((v[i]/2)%2==0){
							ans=1;
							ei=i;
							te=1;
							
						}
						else
							e1=1;
					}
					else if(v[i]%2==1)
 					{
						odd++;
					}
					else
					ze=1;
				}
				else
				{	
					if(v[i]%2==0 && v[i]!=0)
					{
							if(v[i-1]%2!=0)
							{
								ans+=(odd*(odd+1)/2);
								if(ei>ze)
								ans+=((ei-ze)*odd);
								odd=0;
								
							}
							
							
							if((v[i]/2)%2==0)
							{
								if(i>ze)
								ans+=(i-ze);
								ei=i;
								e1=0;
								
							}
							else if(e1==0){
								if(ei>ze)
								ans+=(ei-ze);
								e1=i;
							}
							else if(e1!=0)
							{
								ei=e1;
								e1=i;
								if(ei>ze)
								ans+=(ei-ze);
							}
							
				    }
					else if(v[i]%2==1)
						odd++;
					else
					{
					            ans+=(odd*(odd+1)/2);
					            if(ei>ze)
								ans+=((ei-ze)*odd);
								odd=0;
								ei=0;
								e1=0;
								ze=i;
					}
				}
				//cout<<ans<<" ";
			}	
			//cout<<endl;
			if(v[n]%2==1)
				ans+=(odd*(odd+1)/2)+((ei-ze)*odd);
			cout<<ans<<endl;
 	} 
		return 0; 
}


