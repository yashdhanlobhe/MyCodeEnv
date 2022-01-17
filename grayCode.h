#include<bits/stdc++.h>

using namespace std;

//This is also done in leetcode and have submitted in discussion also

class GrayCode{

//Gray Code is used in most of the computer becuase in each consequtive only one bit is changed

public:
	//we can genereate this list using recursion like calling n-1 becuase if we have for one bit we can create for n + 1 bit
	//    0   1						   // we can take previous bit as it is  
	//    0   1  10  11                // and add one in starting and reverse it
	//    0   1  10  11  111  110  100
	//    0   1  10  11  111  110  100  1100  1110  1111  111  110  11  10
	vector<int> getGrayCodeVector(int n){
		if(n == 1) return {0 ,  1};
		vector<int> v =  getGrayCodeVector(n - 1);
		for (int i = v.size() - 1; i >= 0; --i)
		{
			v.push_back((1<<(n-1))|v[i]);
		}
		return v;
	}

	//see leetcode 
	//and getsmasher

	/*
	for random number write number in binary ex.    1 1 0 1 (n1 , n2 , n3 , n4)  =>  (n1 , n1^n2 , n2^n3 , n3^n4 )  ans => 1 0 1 1
	for gray code to the number              ex.    1 0 1 1 (n1 , n2 , n3 , n4)  =>  (n1 , v1^n2 , v2^n3 , v3^n4 )  ans => 1 1 0 1 
																					  v1     v2      v3      v4
	*/				


};