
class Node{
    private:
    Node* links[26];
    int preCount = 0;
    int end = 0;
    public:
    bool contains(char c){
        if(links[c-'a'] == NULL) return false;
        return true;
    }
    
    Node* insert(char c){
        if(!contains(c)) links[c-'a'] = new Node();
        links[c-'a']->preCount++;
        return links[c-'a'];
    }
    void setEnd(){
        end++;
    }
    Node* getNode(char c){
        return links[c-'a'];
    }
    int endings(){
        return end;
    }
    int startings(){
        return preCount;
    }
    Node* remove(char c){
        links[c-'a']->preCount--;
        return links[c-'a'];
    }
    void removeEnd(){
        end--;
    }
};



class Trie{

    private:
    Node* root;
    
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* temp = root;
        for(auto x : word){
            temp = temp->insert(x);
        }
        temp->setEnd();
    }

    int countWordsEqualTo(string &word){
        Node* temp = root;
        for(auto x : word){
            if(!temp->contains(x)) return 0;
            temp = temp->getNode(x);
        }
        return temp->endings();
    }

    int countWordsStartingWith(string &word){
        Node* temp = root;
        for(auto x : word){
            if(!temp->contains(x)) return 0;
            temp = temp->getNode(x);
        }
        return temp->startings();
    }

    void erase(string &word){
        Node* temp = root;
        for(auto x : word){
            temp = temp->remove(x);
        }
        temp->removeEnd();
    }
};
