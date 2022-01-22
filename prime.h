#include <bits/stdc++.h>

using namespace std;

class Prime{
	vector<bool> isPrimeV;
	public:
	Prime(int n){
		vector<bool> v(n+1 , true);
		isPrimeV = v;

		isPrimeV[0] = isPrimeV[1] = false;
		for (int i = 2; i <= n; ++i)
		{
			if(isPrimeV[i]){
				for (long long j = i*i; j <= n; j+=i)
				{
					isPrimeV[j] = false;
				}
			}
		}
	}

	vector<bool> getAllPrimes(){
		return isPrimeV;
	}
	
	bool isPrime(int n){
		return isPrimeV[n];
	}

};