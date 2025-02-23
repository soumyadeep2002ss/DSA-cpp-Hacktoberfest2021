#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
M coloring(Backtracking)
----------------------
Time Complexity:- O(m^n) where n is number of nodes of graph and m is number of colors
Space Complexity:- O(n)+O(n) due to color array and recursion stack
*/

static int possibility;

void printAdjacencyMatrix(int** adj,int n)
{
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}

bool isSafeToColor(int currentNode,int* colors,int** graph,int n,int currentColor)
{
    for(int i=0;i<n;i++)
    {
        if(i!=currentNode && graph[i][currentNode]==1 && colors[i]==currentColor)
            return false;
    }
    return true;
}

void colorGraphHelper(int currentNode,int* colors,int m,int n,int** graph)
{
    //Base case
    if(currentNode==n)
    {
        cout<<"Possibility "<<possibility+1<<": "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"valid Color of node "<<i<<" is "<<colors[i]<<endl;
        }
        possibility++;
        cout<<endl;
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            if(isSafeToColor(currentNode,colors,graph,n,i))
            {
                colors[currentNode]=i;
                colorGraphHelper(currentNode+1,colors,m,n,graph);
                colors[currentNode]=-1;
            }
        }
    }
}

void colorGraph(int** graph,int m,int n)
{
    int* colors=new int[m];
    for(int i=0;i<m;i++)
        colors[i]=-1;
    int initialNode=0;
    colorGraphHelper(initialNode,colors,m,n,graph);
    delete [] colors;
}

int main()
{
    fstream infile;

    infile.open("MColor.txt",ios::in);
    if (!infile)
    {
        cout << "Error to open the file";
        return 1;
    }
    int m;
    int n,e;
    cout<<"Enter number of vertices of graph: ";
    infile>>n;
    cout<<"Enter number of edges of graph: ";
    infile>>e;
    int** adj=new int*[n];
    for(int i=0;i<n;i++)
        adj[i]=new int[n];

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            infile>>adj[i][j];
    }

    cout<<"Enter number of colors: ";
    infile>>m;

    colorGraph(adj,m,n);

    cout<<"Number of posibilities to color the graph : "<<possibility<<endl;

    for(int i=0;i<n;i++)
        delete [] adj[i];
    delete [] adj;

    return 0;
}
