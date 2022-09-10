#include <bits/stdc++.h>
using namespace std;




void solve(){
	string key;
	cout<<"Enter Key ";
	cin>>key;
	
	set<char> st;
	for(auto x : key) {
		if((x) == 'j') continue;
		st.insert(x);
	}

	vector<vector<char>> table(5 , vector<char>(5));
	
	for (int i = 0; i < key.length(); ++i)
	{
		table[i/5][i%5] = key[i];
	}

	
	int idx = key.length();
	for (int i = 0; i < 26; ++i)
	{
		if((i + 'a') == 'j') continue;
		if(st.find((i + 'a')) != st.end()) 
			continue;
		table[idx/5][idx%5] = ('a' + i);
		idx++;
	}


	for(auto x : table){
		for(auto y : x){
			cout<<y<<" ";
		}
		cout<<endl;
	}

	//add filler letter
	string text;
	cout<<"Enter plain text : ";
	cin>>text;

	string textF = "";
	for(auto x : text){
		if(textF == "") {
			textF.push_back(x);
			continue;
		} else{
			if(textF.back() == x) {
				textF.push_back('x');
			}
			textF.push_back(x);
		}
	}
	if(textF.length()&1) textF.push_back('x');
	cout<<"Text With filled : ";
	cout<<textF<<endl;
	map<char , pair<int , int>> mp;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			mp[table[i][j]] = {i , j};
		}
	}
	string encrypt = "";

	for (int i = 1; i < textF.length(); i+=2)
	{
		char a = textF[i-1];
		char b = textF[i];
		auto apos = mp[a];
		auto bpos = mp[b];
		if(apos.first == bpos.first || apos.second == bpos.second){
			//in same coloumn or row
			if(apos.first == bpos.first){
				//same row
				encrypt += table[(apos.first)][(apos.second+1)%5];
				encrypt += table[(bpos.first)][(bpos.second+1)%5];
			}else{
				//same column
				encrypt += table[(apos.first+1)%5][(apos.second)];
				encrypt += table[(bpos.first+1)%5][(bpos.second)];
			}
		}else{
			//diferent column
			encrypt += table[apos.first][bpos.second];
			encrypt += table[bpos.first][apos.second];
		}
	}
	cout<<"Encrypted Text :  "<<encrypt<<endl;

}




int main() {
    solve();    
    return 0;
}