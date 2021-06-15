#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			cout<<i<<" ";
			cout<<"\n";
			continue;
		}
		if(k>(n-1)/2 || n<=2)
        {
			cout<<"-1"<<"\n";
			continue;
		}
		vector <int> v;
		v.push_back(1);
        for(int i=2;i<=n;i++){
            if(k>=2)
			{
				v.push_back(i+1);
				v.push_back(i);
				k--;
				i+=1;
			}
			else
			{
				for(int j=i;j<n-1;j++)
				{
					v.push_back(j);
				}
				v.push_back(n);
				v.push_back(n-1);
				break;
			}
        }
         for(auto u:v)
		 cout<<u<<" ";

        cout<<endl;
    }
}