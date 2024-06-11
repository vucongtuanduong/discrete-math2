#include<iostream>
#include<vector>
using namespace std;
int n,s;
int a[100][100];
int d[100];
int pre[100];
void outp()
{
	for(int i=1;i<=n;i++)
    {
    	if(d[i]>900)
    	{
    	cout<<"K/c "<<s<<" -> "<<i<<" = "<<"INF;"<<endl;
    	}
    	else
    	{
    		if(i==s)
    		{
    			cout<<"K/c "<<s<<" -> "<<i<<" = "<<"0"<<";       ";
    			cout<<s<<" <- "<<s<<endl;
    			continue;
			}
    	cout<<"K/c "<<s<<" -> "<<i<<" = "<<d[i]<<";       ";
		int tmp=i;
		while(tmp!=s)
		{
			cout<<tmp<<" <- ";
			tmp=pre[tmp];
		}
		cout<<tmp<<endl;	
		}
	}
}
void Bell(int s)
{
    int k=n-2;
    while(k--)
    {
        for(int i=1;i<=n;i++)
        {
            if(i!=s)
            {
                for(int j=1;j<=n;j++)
                {
                    if(d[i]>d[j]+a[j][i])
                    {
                        d[i]=d[j]+a[j][i];
                        pre[i]=j;
                    }
                }
            }
                
        }
    }
    outp();
    
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin>>n>>s;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]==0)
                {
                    a[i][j]=1000;
                }
            }
        }
        d[s]=0;
        pre[s]=s;
        for(int i=1;i<=n;i++)
        {
            if(i!=s)
            {
                d[i]=a[s][i];
                pre[i]=s;
            }
        }
        Bell(s);
    }
    
    
}