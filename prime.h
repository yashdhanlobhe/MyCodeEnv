#include <bits/stdc++.h>

using namespace std;



class Prime{
	vector<bool> isPrimeV;
	public:
			//using prime to make non prime 
	Prime(int n){
		vector<bool> v(n+1 , true);
		isPrimeV = v;

		isPrimeV[0] = isPrimeV[1] = false;
		for (int i = 2; i <= n; ++i)
		{
			if(isPrimeV[i]){
				//start with i*i becuase all numbers before i is done suppose 5 then 5*1 is done as 1*5
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