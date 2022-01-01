class LRUCache {

public:
    class Node{
        public:
        Node *prev,*next;
        int val;
        int key;
        Node(int key , int val){
            this->val = val;
            this->key = key;
        }
    };
    
    Node* head = new Node(-1 , -1);
    Node* tail = new Node(-1 , -1);
    int capacity;
    map<int  , Node*> mp;
     
    void addNode(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
    }
    
    void deleteNode(Node* node){
        Node *front = node->prev;
        Node *next = node->next;
        front->next = next;
        next->prev = front;
    }
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        mp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* ansNode = mp[key];
        deleteNode(ansNode);
        addNode(ansNode);
        mp.erase(key);
        mp[key] = head->next;
        return mp[key]->val;
        
    } 
    
    void put(int key, int value) {
        //if the value contains then delete it and keep in first
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
            mp.erase(key);
            
        }
        //if capacity is full empty the size
        if(mp.size() == capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key , value);
        addNode(newNode);
        mp[key] = newNode;
    }
};
