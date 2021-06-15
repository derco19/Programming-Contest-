#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool isConsecutive(string str)
{
	int start;

	int length = str.size();

	for (int i = 0; i < length / 2; i++) {

		string new_str = str.substr(0, i + 1);

		int num = atoi(new_str.c_str());

		start = num;

		while (new_str.size() < length) {

			num++;

			new_str = new_str + to_string(num);
		}

		if (new_str == str)
		return true;
	}

	return false;
}



int main()
{

      
    ll t=1,t1=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case #"<<t1<<": ";
        
        ll n;
        cin>>n;
        n++;
        string s=to_string(n);
        while(!(isConsecutive(s)))
        {
            n++;
            s=to_string(n);
        }
        cout<<n;
        cout<<"\n";
        t1++;
    }  
}

