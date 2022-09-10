#include <bits/stdc++.h>
using namespace std;


int main()
{	
	int empSz;
	int projectSz;
	cin>>empSz>>projectSz;

	vector<int> parent(empSz), project(projectSz);
	for (int i = 0; i < empSz; ++i)
	{
		cin>>parent[i];
	}

	for (int i = 0; i < projectSz; ++i)
	{
		cin>>project[i];
	}
	vector<bool> vis(empSz , false);
	
	for (int i = 0; i < projectSz; ++i)
	{
		int curEmp = project[i];
		// curEmp--;

		while(curEmp != 0 && !vis[parent[curEmp]]){
			curEmp = parent[curEmp];
		}
		vis[curEmp] = true;
	}

	for (int i = 0; i < empSz; ++i)
	{
		if(!vis[empSz]) cout<<i+1<<" ";
	}

	return 0;
}