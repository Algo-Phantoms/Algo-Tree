/*
    Find if there is negative cycle present in the weighted graph using Bellman–Ford algorithm
Approach:

* First take the input and we don't have to put it the matrix or edgelist form, we have to store them as per the given input. 

* Create the array which will store the weight till now iteration which will ne initialized by infinity(INT_MAX) except the source node which is 0 in our case will be initialized by 0.

* We have make two loops and make the first loop run for total vertex -1 times because the longest path in a connected path will be vertex-1 if we remove the cycles

* Second loop will run for the number of edges and in each iteration we will check if the current vertex is visited then it's weight + weight_to_vertex2 is less then weight 
  of the vertex edge the assign in the vertex2

* There is a count variable which take in acount if there is any change in weight of any node if there is no change then we simply break the loop

* If the count value is 0 means there is no negative cycle in graph.

* If the count value is not 0 then we will run a loop once again on the edge and check if there is any value change. 

* If count value is 0 means there is no negative cycle else there is a negative cycle.

*/



#include<bits/stdc++.h>
using namespace std;


int main()
{
    int node,edges,vertex1,vertex2,weight;
    //input number of nodes and edges
    cin>>node>>edges;
    vector<pair<int,pair<int,int>>>edgeList;

    //input in the edgeList
    while (edges--)
    {
        cin>>vertex1>>vertex2>>weight;
        edgeList.push_back({vertex1,{vertex2,weight}});
    }

    int weightChange=0;
    int weightArr[node];
    weightArr[0]=0;

    //array which is equal to infinity(INT_MAX)
    for(int i=1;i<node;i++)
    {
        weightArr[i]=INT_MAX;
    }



    for(int i=1;i<node;i++)
    {
        weightChange=0;
        for(int j=0;j<int(edgeList.size());j++)
        {
            vertex1=edgeList[j].first;
            vertex2=edgeList[j].second.first;
            weight=edgeList[j].second.second;
            
            //if current node is visited and it's weight + next edge is less then next node weight
            if( weightArr[vertex1]!=INT_MAX and weightArr[vertex1]+weight<weightArr[vertex2] )
            {
                weightChange++;
                weightArr[vertex2] = weightArr[vertex1]+weight;
            }
        }

        if(weightChange==0)
        {
            break;
        }
    }

    //if weightChange is zero means there is no cycle present
    if(weightChange==0)
    {
        cout<<"There is no negative cycle in the graph\n";
    }
    else{
        weightChange=0;
          for(int j=0;j<int(edgeList.size());j++)
        {
            vertex1=edgeList[j].first;
            vertex2=edgeList[j].second.first;
            weight=edgeList[j].second.second;
            
            if( weightArr[vertex1]!=INT_MAX and weightArr[vertex1]+weight<weightArr[vertex2] )
            {
                weightChange++;
                weightArr[vertex2] = weightArr[vertex1]+weight;
            }
        }

        //if weightChange is zero means there is no cycle present
        if(weightChange==0)
        {
            cout<<"There is no negative cycle in the graph\n";
        }
        //if weightChange is not 0 means negative cycle is present
        else{
            cout<<"There is a negative cycle in the graph\n";
        }
    }
    
    
    return 0;
}

/*
    Test Cases:
    
    Input 1:
    3 4
    0 1 -1
    1 2 3
    2 3 4
    3 0 -10

    Output 1:
    There is a negative cycle in the graph

    Input 2:
    3 4
    0 1 -1
    1 2 3
    2 3 4
    3 0 -4

    Output 2:
    There is no negative cycle in the graph
     

    Time Complexity  :    O(Vertex*Edges)
    Space Complexity :    with graph O(max(Edges,Vertex))

