class TreeAncestor {
public:
    
    // ROW = base value 2 4 8th parent
    // COL = for which number find base
     
    vector<vector<int>> table;
    int MAX = 17;
    
    TreeAncestor(int n, vector<int>& parent) {
        table.resize(MAX , vector<int>(n));
        
        for(int i = 0 ; i < n ; i++){
            table[0][i] =  parent[i];
        }
        
        for(int base = 1 ; base < MAX ; base++){
            for(int num = 0 ; num < n ; num++){
                
                // suppose we want 8 th parent then we can do 4 th parent of 4 th parent
                // 4 the means just above row becuase we are increaseing each time double of current
                // table[base-1][num] will give the 4 the parent of current num
                // and then we will find 4 th parent of that number
                if(table[base-1][num] == -1) table[base][num] = -1;
                else table[base][num] = table[base-1][table[base-1][num]];
            }
        }

    }
    
    int getKthAncestor(int node, int k) {
        
        for(int i = 0 ; i < MAX ; i++){
            int mask = (1<<i);
            if((mask&k) > 0){
                node = table[i][node];
                if(node == -1) return node;
            }
        }
        return node;
    }
};
