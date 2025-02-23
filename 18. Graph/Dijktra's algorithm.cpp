#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

//The below function is for selecting the minimum distance vertex
//If the vertex don't include in the shortest path graph and minimum value then we selecte the vertex


int Select_Vertex(int n,int value[],int vis[])
{
	int minimum=INT_MAX;
	int vertex;
	int i;
	for(i=0;i<n;i++)
	{
		if(vis[i]==0 && minimum>value[i])
		{
			vertex=i;
			minimum=value[i];
		}
	}
	return vertex;
}

void Dijktra(int **adj,int n,int source)
{
	int parent[n]; /// This for knowing the parent of all vertices of shortest path graph not need you can ignore it
	
	
	int vis[n];    /// This is for knowing the selected vertices is already include in the shortest path graph or not
/// I use visited array here just because if you didn't use visited array then after complie it 
// always it will select source veretex because later we will initialize distance from source to source
// is 0 so that the distance between source to source's adjacent vertex will change but rest of the vertex
// distance will remain INT_MAX then we get a wrong output	
	
	int value[n]; // This is for store the value of distance from source to destination
	
	
	parent[source]=-1; //I assume that 0 is the source vertex that's why initialize parent[0]=-1
	int i,j;
	for(i=0;i<n;i++)
	{
		vis[i]=0;
	}
	for(i=0;i<n;i++)
	{
		value[i]=INT_MAX;
	}
	
	value[source]=0;//I assume that 0 is the source vertex that's why initialize value[0]=0;
	
	// if you didn't initialize value[0] is equal to 0 then no vertex will not selcet then the algorithm
	// dosen't work
	
	for(i=0;i<n-1;i++)
	{
		int vertex=Select_Vertex(n,value,vis);
		vis[vertex]=1;
		
		for(j=0;j<n;j++)
		{
			if(adj[vertex][j]!=0 && vis[j]==0 && value[vertex]!=INT_MAX && 
			value[vertex]+adj[vertex][j]<value[j])
			{
				value[j]=value[vertex]+adj[vertex][j];
				parent[j]=vertex;
			}
		}
	}
//	for(i=0;i<n;i++)
//	cout<<value[i]<<"\n";
	
	cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
        cout  <<" "<< i << "  \t\t"<<value[i]<< endl;
}

int main()
{
	fstream infile;
	if (!infile)
    {
        cout << "Error to open the file";
        return 1;
    }
	infile.open("Dijktra's_algo.txt",ios::in);
	int n,e;
//	cout<<"Enter the number of vertices and number of edges"<<"\n";
	infile>>n;
	infile>>e;
	
	int **adj,i,j;//adjacency matrix 
	adj=new int*[n];
	for(i=0;i<n;i++)
	{
		adj[i]=new int[n];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		infile>>adj[i][j];
	}
	int source;
//	cout<<"Enter the source"<<"\n";
	infile>>source;
	cout<<"\n";
	Dijktra(adj,n,source);
}
