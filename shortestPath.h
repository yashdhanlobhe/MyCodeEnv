#include <bits/stdc++.h>
using namespace std;
class shortestPath
{
public:
	// ****MAIN USES*******
	// Finding the shortest path + 

	// 1. Dijkstra’s -> find the shortest path most optimised but cant find in the negative cycles
	// 2. BellmanFord -> overcome the problem of negative cycles but not that much optimised still cant find in negative undircted cylces
	// 3. floydWarshell -> can work in any graph but time complexity is more and give solution of each vertex with another one


	// if matrix representation  = O(V^2) for adjecency list = O(E log V)
	//Greedy Algorithm
	//Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree. 
	//can done by using key and visited vector OR using set OR priority queue (here the key point is add in priority queue directly dont check for that pair is currently present in priority queue or not)
	//The code calculates the shortest distance but doesn’t calculate the path information. We can create a parent array, update the parent array when distance is updated
	//The code is for undirected graphs, the same Dijkstra function can be used for directed graphs also.
	//Time Complexity of the implementation is O(V^2). If the input graph is represented using adjacency list, it can be reduced to O(E log V) with the help of a binary heap.

	//Dijkstra’s algorithm doesn’t work for graphs with negative weight cycles. It may give correct results for a graph with negative edges but you must allow a vertex can be visited multiple times and that version will lose its fast time complexity. For graphs with negative weight edges and cycles, Bellman–Ford algorithm can be used, 
	//ans - > NO :: 
	static vector<int> dijkstra(vector<vector<int>> &g , int source){
		vector<int> dist(g.size() , INT_MAX);
		
		set<pair<int , int>> st;
		st.insert({0 , source});
		
		dist[source] = 0;

		while(!st.empty()){
			auto cur = *st.begin();
			st.erase(cur);
			int u = cur.second;

			for(int i = 0 ; i < g.size() ; i++){
				int v = i;
				int weight = g[u][i];
				if(weight == INT_MAX || u == v) continue;
				
				if(u + weight < dist[v]){
					if(dist[v] != INT_MAX){
						st.erase({dist[v] , v});
					}
					dist[v] = u + weight;
					st.insert({dist[v] , v});
				}
			}
		}
		return dist;
	}


	//Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. The graph may contain negative weight edges.
	//Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems. But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra. 
	// Bellman-Ford does not work with undirected graph with negative edges as it will declared as negative cycle.
	//Bellman-Ford works better (better than Dijkstra’s) for distributed systems. Unlike Dijkstra’s where we need to find the minimum value of all vertices, in Bellman-Ford, edges are considered one by one. 
 	static vector<int> bellmanFord(vector<vector<int>> &g , int source){

		vector<int> dist(g.size() , INT_MAX);
		vector<vector<int>> edges;
		for (int i = 0; i < g.size(); ++i)
		{
			for (int j = i+1; j < g.size(); ++j)
			{
				if(g[i][j] == INT_MAX) continue;
				edges.push_back({i , j ,  g[i][j]});
			}
		}
		dist[source] = 0;
		for (int i = 0; i < g.size() - 1; ++i)
		{
			for(auto x : edges){
				int u = x[0];
				int v = x[1];
				int weight = x[2];
				if((dist[u] != INT_MAX) && (dist[u] + weight < dist[v])){
					dist[v] = dist[u] + weight;
				}
			}
		}

		return dist ;
	}

	

	//Time Complexity: O(V^3)
	//The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. 
	//The above program only prints the shortest distances. We can modify the solution to print the shortest paths also by storing the predecessor information in a separate 2D matrix. 
	// Also, the value of INF can be taken as INT_MAX from limits.h to make sure that we handle maximum possible value. When we take INF as INT_MAX, we need to change the if condition in the above program to avoid arithmetic overflow. 
	static vector<vector<int>> floydWarshell(vector<vector<int>> &g , int source){
		vector<vector<int>> dist(g.size() , vector<int>(g.size() , INT_MAX));
		for (int i = 0; i < g.size(); ++i)
		{
			for (int j = 0; j < g.size(); ++j)
			{
				dist[i][j] = g[i][j];
			}
		}

		for (int i = 0; i < g.size(); ++i)
		{
			for (int j = 0; j < g.size(); ++j)
			{
				for (int k = 0; k < g.size(); ++k)
				{
					if(i == j){
						dist[i][j] = 0;
						continue;
					}
					if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&( dist[i][k] + dist[k][j] < dist[i][j])){
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		return dist;
	}
};