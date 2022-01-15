#include<bits/stdc++.h>

using namespace std;

class Bridge{
private:
	//this will store the bridge ages
	vector<pair<int , int>> ans;
	
	//this will store the articulation point
	vector<int> ansPoint;

	//lowerMin = Min value at which the point get
	vector<int> lowerMin;

	//normalMin = current Minimum at which cur loop is running
	vector<int> normalMin;

	//the given graph the global varible only
	vector<vector<int>> graph;
	


	/*
	Core Idea : In this first we start from starting point and do just DFS traversal and set the normal min and the lower min as the timer
				in this way we will calcluate at what time we visited cur node in our path and then if we find any visited array we take 
				take there lower min and assign to the cur min that means at this point we can visit at lowerMin[i]. and if the lowerMin of
				child is more than the cur normal occurence then that edge will be added to the ans because this we cant visite that point without
				this edge.
	*/
	void getBridgesUtil(int cur , int &timer , int parent){
		lowerMin[cur] = normalMin[cur] = timer++;
		for(auto x : graph[cur]){

			// this will break if the x is cur becuase we are on same path and we cant go back other wise every lowerMin will be 1
			if(x == parent) continue;

			//if the point is already visited then that point we can visit already
			if(lowerMin[x] == -1){
				getBridgesUtil(x , timer , cur);
				// if this can't be visited then lowerMin of child will be always greater 
				if(lowerMin[x] > normalMin[cur]){
					ans.push_back({x , cur});
				}	
				//updating the cur minimum can we come from the child path
				lowerMin[cur] = min(lowerMin[cur] , lowerMin[x]);
			}else{
				lowerMin[cur] = min(lowerMin[cur] , lowerMin[x]);
			}
		}
	}


	//same as the above
	//diffrence is child
	//in this we are taking lowerMin[x] >= normalMin[cur] becuase if the lowerMin is equal to the curMin of parent then child is came from
	//it only so this is the articulation point

	//and another is child this is only useful in the  first point becuase always no one will have lower min than first point
	//so it will always take it in count but if the fist is connecting two different graph then it should be added so we added child
	//so if we will call this method again for another child of main then must be the other graph is different so it is articulation point
	//so added condition in the last
	void getArticulationPointsUtil(int cur , int &timer , int parent){
		lowerMin[cur] = normalMin[cur] = timer++;
		int child = 0;
		for(auto x : graph[cur]){
			if(x == parent) continue;
			if(lowerMin[x] == -1){
				child++;
				getArticulationPointsUtil(x , timer , cur);
				if(lowerMin[x] >= normalMin[cur] && parent != -1){
					ansPoint.push_back(cur);
				}	
				lowerMin[cur] = min(lowerMin[cur] , lowerMin[x]);
			}else{
				lowerMin[cur] = min(lowerMin[cur] , lowerMin[x]);
			}
		}
		if(parent == -1 && child > 1) ansPoint.push_back(cur);
	}


public:
	vector<pair<int  , int>> getBridges(vector<vector<int>> &graph){
		ans.clear();
		vector<int> lowerMin(graph.size() , -1) , normalMin(graph.size() , -1);
		
		this->graph = graph;
		this->lowerMin = lowerMin;
		this->normalMin = normalMin;
		int timer = 0;
		getBridgesUtil(0 , timer , -1);

		return ans;
	}
	vector<int> getArticulationPoints(vector<vector<int>> &graph){
		ansPoint.clear();
		vector<int> lowerMin(graph.size() , -1) , normalMin(graph.size() , -1);
		
		this->graph = graph;
		this->lowerMin = lowerMin;
		this->normalMin = normalMin;
		int timer = 0;
		getArticulationPointsUtil(0 , timer , -1);

		return ansPoint;
	}
};