#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int solve (ll L, ll R, ll X) {
   // Write your code here
   
    ll c=1;
    ll ans=0,ans1=0,p;
    while(c<=R)
    {
        if(c>=L)
        {
            p=(c/X)*X;
            if(p==c)
            {
                p=p-X;
                ans1=ans1+max(p-max(c/2,L-1),0LL);
            }    
            else if(p!=c)
            {
                ans=ans+c-max(L-1,max(c/2,p));
                ans1=ans1+max(p-max(c/2,L-1),0LL);
            }    
        }
        c*=2;
    }
    p=(c/X)*X;
    if(c!=p)
    {
        ans=ans+R-max(min(R,p),L-1);
        ans1=ans1+max(min(R,p)-max(c/2,L-1),0LL);
    }
    else 
    {
        p=p-X;
        ans1=ans1+max(min(R,p)-max(c/2,L-1),0LL);
    }
    if(ans==ans1)
    return 0;
    else if(ans>ans1)
    return 1;
    else
    return 2;    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int L;
        cin >> L;
        int R;
        cin >> R;
        int X;
        cin >> X;

        int out_;
        out_ = solve(L, R, X);
        cout << out_;
        cout << "\n";
    }
}