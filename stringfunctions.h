#include<bits/stdc++.h>

using namespace std;

class StringFunctions{
	public:

	//refer
	//https://www.youtube.com/watch?v=CpZh4eF8QBw&ab_channel=TusharRoy-CodingMadeSimple
	
	//we can also find the kmp algo using this below implementation
	static vector<long long> zfunction(string &s){
        int sz = s.length();
        
        vector<long long> ans(sz);
        ans[0] = sz;
        
        //intially all string will be same
        int left =0 , right = 0;
        //left to right window will be zero first

        for(int i = 1 ; i < sz ; i++){
            if(i > right){

            	//if (i > right) that this need to be calculated
               	//this is like regular only just maintain the left and right (window)
                
                left = right = i;
                
                while(right < sz && s[right - left] == s[right]){
                    right++;
                }
                
                //the size of window will be the answer
                
                ans[i] = right - left;
                right--;
            }else{
                int temp = i - left;
                //this is calculated just take previous ans (i - left) from zeroth idx

                if(ans[temp] + i < right + 1){
                    ans[i] = ans[temp]; 
                }else{

                	//note :: if the ans[temp] is greater than left + right window so we need to check will it satisfy the next values after right 
                    left =  i;
                    while(right < sz && s[right - left] == s[right]){
                        right++;
                    }
                    ans[i] = right - left;
                    right--;
                }
            }
        }
        return ans;
    }

    static vector<int> kmpAlgo(string &s , string &pattern){
    	string temp = pattern + "$" + s;
    	auto x = zfunction(temp);
    	vector<int> ans;
        cout<<(temp);
    	for(int i = pattern.length()+1; i < temp.length(); i++) 
		{
            if(x[i] >= pattern.length()) 
                ans.push_back(i-pattern.length()-1);
        }
    	return ans;
    }
    
};