
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

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie *t = new Trie();
    for(auto x : arr1) t->insert(x);
    int ans = 0;
    for(auto x : arr2){
//         cout<<t->getMax(x);
        ans = max(ans , t->getMax(x));
    }
    return ans;
}







