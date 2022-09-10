#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



class DifferenceArray
{
public:
	ll sz;
	vector<ll> v;
	vector<ll> differenceArray;
	DifferenceArray(std::vector<ll> v){
		// a[i] = a[i-1] + d[i]
		// a[0] = d[0]

		this->v = v;
		sz = v.size();
		differenceArray.push_back(v[0]);

		for (ll i = 1; i < sz; ++i)
		{
			differenceArray.push_back(v[i] - v[i-1]);
		}

		differenceArray.push_back(0);
	}

	void update(ll l , ll r , ll val){
		differenceArray[l] += val;
		differenceArray[r+1] -= val;

	}

	vector<ll> getUpdatedArray(){
		v[0] = differenceArray[0];
		for (int i = 1; i < sz; ++i)
		{
			v[i] = v[i-1] + differenceArray[i];
		}
		return v;
	}

};