//ceil(a/b) is equal to (a+b-1)/b
#include<bits/stdc++.h>
 
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define int long long int
 
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vec vector <int>
#define pr vector<pair<int,int>> 
#define vecv vector <vec>
#define vecs vector <string>
#define vecc vector <char>
 
#define pi 3.141592653589793238
#define mod 1000000007
#define Mod 998244353
#define inf 1e16
#define precise(i) fixed << setprecision(10) << i
#define endl "\n"
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define one cout<<-1<<endl;

#define err1(a) cout<<#a<<" "<<a<<endl;
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl;
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl;
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define all(a) a.begin(),a.end()
#define show(a) for(auto xyz:a)cout<<xyz<<" ";cout<<endl;
#define show_nl(a) for(auto xyz:a)cout<<xyz<<endl;
#define loop(a) for(auto xyz:a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=b;i>=a;i--)

const long double eps = 1e-8;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

#define lb lower_bound  //THIS GIVES THE ITR TO THE ELEMENT IN RANGE [SI,EI) THAT IS >= OUR VALUE 
#define ub upper_bound  //THIS GIVES THE ITR TO THE ELEMENT IN RANGE [SI,EI) THAT IS > OUR VALUE 
 
using namespace std;
 
signed main() {
     fastio
     int t=1;
     cin>>t;
     f(tt,1,t+1)
     {
         int n,m;
         
        cin>>n>>m;
        set <int> s;
        map<int,int> en;
        f(i,0,n)
        {
            int a,b;
            cin>>a>>b;
            s.insert(a); en[a]=b;
        }
        vec v(m);
        for(auto &i:v)
        cin>>i;
        vec ans;
        f(i,0,m)
        {
            if(s.find(v[i])!=s.end())
            {
                ans.pb(v[i]);
                s.erase(v[i]);
                int x=en[v[i]];
                if(x>=v[i]+1)
                {
                    s.insert(v[i]+1);
                    en[v[i]+1]=x;
                }
            }
            else
            {
            auto x=s.lower_bound(v[i]);
           // auto y=s.upper_bound(v[i]);
                if(x==s.end())
                {
                    x--;
                    int b=*x;
                    if(en[b]<=v[i])
                    {
                        int xx=en[b];
                        ans.pb(xx);
                        xx--;
                        if(xx>=b) en[b]=xx;
                        else s.erase(b);
                    }
                    else
                    {
                        int temp=en[b];
                        ans.pb(v[i]);
                        en[b]=v[i]-1;
                        if((v[i]+1)<=temp) 
                        {
                        s.insert(v[i]+1);
                        en[v[i]+1]=temp;
                        }
                    }
                }
                else if(x==s.begin())
                {
                    
                       int a=*x;
                       int b=en[a];
                       ans.pb(a);
                        s.erase(a);
                           // int z=en[v[i]];
                        if(b>=a+1)
                        {
                            s.insert(a+1);
                            en[a+1]=b;
                        }
                }
                else
                {
                    
                      
                        int a=*x;
                        x--;
                         auto y=x;
                    int b=*y;
                   // err1(b)
                    if(en[b]>=v[i]) 
                    {
                        int temp=en[b];
                        ans.pb(v[i]);
                        en[b]=v[i]-1;
                        if(v[i]+1<=temp) 
                        {
                        s.insert(v[i]+1);
                        en[v[i]+1]=temp;
                        }
                        //s.erase(y);
                    }
                    else if((v[i]-en[b])<=a-v[i])
                    {
                        ans.pb(en[b]);
                        en[b]--;
                        if(en[b]<b) s.erase(b);
                        
                    }
                    else
                    {
                         int bb=en[a];
                           ans.pb(a);
                            s.erase(a);
                               // int z=en[v[i]];
                            if(bb>=a+1)
                            {
                                s.insert(a+1);
                                en[a+1]=bb;
                            }
                    }
                }
            
            }
        }
        cout<<"Case #"<<tt<<": ";
        show(ans);
     }
}