#include<bits/stdc++.h>

class Node{
    private :
    Node *links[2];
    public:
    bool contains(int a){
        return links[a] != NULL;
    }
    Node* insert(int a){
        if(!contains(a)){
            return links[a] = new Node();
        }
        return links[a];
    }
    Node* get(int a){
        return links[a];
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }
    int insert(int val){
        Node* temp = root;
        for(int i = 31 ; i >= 0 ; i--){
            int bit = (val>>i)&1;
//             cout<<bit;
            temp = temp->insert(bit);
        }
//         cout<<endl;
    }
    public:
    int getMax(int val){
        int ans = 0;
        Node* temp = root;
        for(int  i = 31 ; i >= 0 ; i--){
            int bit = (val>>i)&1;
//             cout<<bit;
            // This is one of the imp bit to switch the bit
            int oppo = 1 - bit;
            if(temp->contains(oppo)){
                ans = (ans | (1<<i));
//                 cout<<ans;
                temp = temp->get(oppo);
            }else{
                temp = temp->get(bit);
            }
        }
//         cout<<endl;
        return ans;
    }
};



vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    sort(arr.begin() , arr.end());
	Trie *t = new Trie();
    vector<int> ans(queries.size() , -1);
    vector<vector<int>> x(queries.size() , vector<int>(3));
    for(int i = 0 ; i < queries.size() ; i++){
        x[i][0] = queries[i][1];
        x[i][1] = queries[i][0];
        x[i][2] = i;
    }
    sort(x.begin() , x.end());
    int ptr = 0;
    for(int i = 0 ; i < x.size() ; i++){
        int val = x[i][0];
        while(ptr < arr.size() && val >= arr[ptr]){
            t->insert(arr[ptr]);
            ptr++;
        }
        int res = -1;
        if(ptr != 0)
        res = t->getMax(x[i][1]);
        
        ans[x[i][2]] = res; 
    }
    return ans;
    
}