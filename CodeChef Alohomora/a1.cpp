#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	   vector< pair <ll,ll> > v;
	    vector< pair <ll,ll> > vb;
	   ll a[n],b[n];
	   for(ll i=0;i<n;i++){
	       cin>>a[i]>>b[i];
	       v.push_back(make_pair(a[i],b[i]));
	       vb.push_back(make_pair(b[i],a[i]));
	   }
	   sort(v.begin(),v.end());
	   sort(vb.begin(),vb.end());
	   
	   // a -> sort
	   // collinear parallel to x-axis
	   vector <ll> Areaasx;
	   ll temp=-1;
	   for(ll i=0;i<n;i++){
            ll area1=0;
	        ll area2=0;
	       if(v[i].second != temp){
	           area1 = (v[n-1].second - v[i].second)*(v[n-1].first - v[i].first);
	                     temp=v[i].second;
	           if(i!=0){
	               area2 = (v[i-1].second - v[0].second)*(v[i-1].first - v[0].first);
	           }
	           Areaasx.push_back(area1 + area2);
	       }
	   }
	   
	   // collinear parallel to y-axis
	   vector <ll> Areaasy;
	   temp=-1;
	   for(ll i=0;i<n;i++){
            ll area1=0;
	        ll area2=0;
	       if(v[i].first != temp){
	           area1 = (v[n-1].second - v[i].second)*(v[n-1].first - v[i].first);
	                     temp=v[i].first;
	           if(i!=0){
	               area2 = (v[i-1].second - v[0].second)*(v[i-1].first - v[0].first);
	           }
	           Areaasy.push_back(area1 + area2);
	       }
	   }


	   
	   //b -> sort
	   //collinear parallel to y-axis
	   vector <ll> RAreabsy;
	   temp=-1;
	   for(ll i=0;i<n;i++){
               ll area1=0;
	           ll area2=0;
	       if(vb[i].second != temp){
	           area1 = (vb[n-1].second - vb[i].second)*(vb[n-1].first - vb[i].first);
	                     temp=vb[i].second;
	           if(i!=0){
	               area2 = (vb[i-1].second - vb[0].second)*(vb[i-1].first - vb[0].first);
	           }
	           RAreabsy.push_back(area1 + area2);
	       }
	   }
	   
	   // collinear parallel to x-axis
	   vector <ll> RAreabsx;
	   temp=-1;
	   for(ll i=0;i<n;i++){
               ll area1=0;
	           ll area2=0;
	       if(vb[i].first != temp){
	           area1 = (vb[n-1].second - vb[i].second)*(vb[n-1].first - vb[i].first);
	                     temp=vb[i].first;
	           if(i!=0){
	               area2 = (vb[i-1].second - vb[0].second)*(vb[i-1].first - vb[0].first);
	           }
	           RAreabsx.push_back(area1 + area2);
	       }
	   }
	   sort(Areaasx.begin(),Areaasx.end());
	   sort(Areaasy.begin(),Areaasy.end());
	   sort(RAreabsy.begin(),RAreabsy.end());
	   sort(RAreabsx.begin(),RAreabsx.end());
	   
	   ll finalArea[4];
	   finalArea[0]=Areaasx[0];
	   finalArea[1]=Areaasy[0];
	   finalArea[2]=RAreabsy[0];
	   finalArea[3]=RAreabsx[0];
	   
	   sort(finalArea,finalArea + 4);
	   
	   cout<<finalArea[0]<<endl; 
	    
	}
	return 0;
}