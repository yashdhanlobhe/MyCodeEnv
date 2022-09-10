#include <bits/stdc++.h>
using namespace std;

class MST
{
public:

	//DSU CLASS for kruskals for more ref see dsu.h
	class DSU
	{
		private:
			vector<int> parent;
			vector<int> rank;
			DSU(){}
		public:
			DSU(int size){
				parent.clear();
				rank.clear();
				for(int i = 0; i <= size; i++){
					parent.push_back(i);
					rank.push_back(0);
				}
			}
			int getParent(int node){
				if(node == parent[node]){
					return node;
				}
				return parent[node] = getParent(parent[node]);
			}
			void makeUnion(int  u , int v){
				u = getParent(u);
				v = getParent(v);

				if(rank[u] < rank[v]){
					parent[u] = v;
				}else if(rank[u] > rank[v]){
					parent[v] = u;
				}else{
					parent[v] = u;
					rank[u]++;
				}
			}
		};


	//Greedy algorithm.
	//Time Complexity: O(ElogE) or O(ElogV)
	//A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph. 
	//Time Complexity: O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(LogV) time. So overall complexity is O(ELogE + ELogV) time. The value of E can be at most O(V2), so O(LogV) is O(LogE) the same. Therefore, the overall time complexity is O(ElogE) or O(ElogV)
    

	//This is very easy we know that n-1 edges will be there which wil connect all vertex so sort all edges according to their weights
	//and check each edge if the edge connecting two different set add it else not use DSU here which have comp. of constant 

    static vector<vector<int>> kruskals(vector<vector<int>> &g){
    	int sz = g.size();
    	vector<vector<int>> FinalEdges;
    	DSU dsu(sz);
    	
    	vector<vector<int>> edges;
		for (int i = 0; i < g.size(); ++i)
		{
			for (int j = i+1; j < g.size(); ++j)
			{
				if(g[i][j] == INT_MAX) continue;
				edges.push_back({g[i][j] , i , j});
			}
		}
		
		sort(edges.begin() , edges.end());

		int ptr = 0;
    	for (int i = 0; i < sz-1; ++i)
    	{
    		//this will not run anyway
    		if(ptr >= edges.size()) break;
    		auto edge = edges[ptr++];
    		FinalEdges.push_back(edge);
    		// cout<<edge[1]<<" "<<edge[2]<<" "<<edge[0]<<endl;
    		if(dsu.getParent(edge[1]) != dsu.getParent(edge[2])){
    			dsu.makeUnion(edge[1], edge[2]);
    		}	
    	}
    	return FinalEdges;
    }

    


    //help function for prims
	static int findMinKey(vector<int> &keys , vector<bool> &vis){
		int minIdx , minVal = INT_MAX;
		for(int i = 0 ; i < keys.size() ; i++){
			if(vis[i]) continue;
			if(minVal > keys[i]) {
				minVal = keys[i];
				minIdx = i;
			}
		}
		return minIdx;
	}



	//Time Complexity  is O(V^2). If the input graph is represented using adjacency list, then the time complexity of Prim’s algorithm can be reduced to O(E log V) with the help of binary heap
	//Prim’s algorithm is also a Greedy algorithm.
	//The idea behind Prim’s algorithm is simple, a spanning tree means all vertices must be connected. So the two disjoint subsets (discussed above) of vertices must be connected to make a Spanning Tree. And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.
	//It starts with an empty spanning tree. The idea is to maintain two sets of vertices. The first set contains the vertices already included in the MST, the other set contains the vertices not yet included. At every step, it considers all the edges that connect the two sets, and picks the minimum weight edge from these edges. After picking the edge, it moves the other endpoint of the edge to the set containing MST. 
	//A group of edges that connects two set of vertices in a graph is called cut in graph theory. So, at every step of Prim’s algorithm, we find a cut (of two sets, one contains the vertices already included in MST and other contains rest of the vertices), pick the minimum weight 
	//edge from the cut and include this vertex to MST Set (the set that contains already included vertices).
	//Time Complexity of the above program is O(V^2). If the input graph is represented using adjacency list, then the time complexity of Prim’s algorithm can be reduced to O(E log V) with the help of binary heap. Please see Prim’s MST for Adjacency List Representation for more details. 
	


	//This is also greddy same as the dikstraw each time take the minimum not visited vetex and each time asign value to vertex the minimum 
	// from the all visited vertex for that each time mark the cur vertex as visited and check all there edges and update the edges which are 
	//lesser than current vertex distance other wise leave as it is
	static vector<int> prims(vector<vector<int>> &g){
		int sz = g.size();
		std::vector<int> parent(sz , -1);
		std::vector<int> keys(sz , INT_MAX);
		std::vector<bool> vis(sz , false);

		parent[0] = -1;
		keys[0] = 0;

		for (int i = 0; i < sz-1; ++i)
		{
			int u = findMinKey(keys , vis);
			vis[u] = true;
			// cout<<u;
			for (int v = 0; v < sz; ++v)
			{
				if(u == v || g[u][v] == INT_MAX || vis[v]) continue;
				if(keys[v] > g[u][v]) {
					keys[v] = g[u][v];
					parent[v] = u;	 
				}
			}
		}

		return parent;
	}
	




	
};



