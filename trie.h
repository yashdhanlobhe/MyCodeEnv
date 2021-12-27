/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class Node{
    Node* links[26];
    bool flag = false;
    public:
    Node* insert(char c){
        if(links[c - 'a'] == NULL) 
            links[c-'a'] = new Node();
        return links[c-'a'];
    }
    bool containsNode(char c){
        if(links[c - 'a'] == NULL) return false;
        return true;
    }
    Node* getNode(char c){
        return links[c-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
    
};

class Trie {
	Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
		root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
		Node* temp = root;
        for(int i= 0 ; i <word.length() ; i++){
            temp = temp->insert(word[i]);
        }
        temp->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
		Node* temp = root;
        for(int i = 0 ; i < word.length() ; i++){
            char c = word[i];
            if(!temp->containsNode(c)) return false;
            temp = temp->getNode(c);
        }
        return temp->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		Node* temp = root;
        for(int i = 0 ; i < prefix.length() ; i++){
            char c = prefix[i];
            if(!temp->containsNode(c)) return false;
            temp = temp->getNode(c);
        }
        return true;
    }
};