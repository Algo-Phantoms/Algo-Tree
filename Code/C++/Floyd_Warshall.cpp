// C++ Program for Floyd Warshall Algorithm (All source shortest path algorithm)
/*Floyd–Warshall algorithm is an algorithm for finding shortest paths between every pair of vertices in a directed weighted graph with positive or negative edge weights (but with no negative cycles).
It comes under Dynamic Programming paradigm. */
#include <bits/stdc++.h>
using namespace std;
 
#define INF 99999 

//Function to display the final resultant distance matrix
void displayDistanceMatrix(int dist[][20], int size); 
 
//Function to implement all pairs shortest path Algorithm
void floyd (int graph[][20], int size) 
{ 
    int dist[20][20], i, j, k; 
 
    for (i = 0; i < size; i++) 
        for (j = 0; j < size; j++) 
            dist[i][j] = graph[i][j]; 
 
    for (k = 0; k < size; k++) 
    { 
        for (i = 0; i < size; i++) 
        { 
            for (j = 0; j < size; j++) 
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j]; //DP Formula 
            } 
        } 
    } 
 
    // Display the shortest distance matrix 
    displayDistanceMatrix(dist, size); 
} 
 

void displayDistanceMatrix(int dist[][20], int size) 
{ 
    cout<<"\nThe final distance matrix with shortest distance "
            "between every pair of vertices : \n"; 
    for (int i = 0; i < size; i++) 
    { 
        for (int j = 0; j < size; j++) 
        { 
            if (dist[i][j] == INF) 
                cout<<"INF"<<"     "; 
            else
                cout<<dist[i][j]<<"     "; 
        } 
        cout<<endl; 
    } 
} 
 
int main() 
{ 
    int Graph[20][20], n, i, j;
    cout << "\nEnter the number of vertices : ";
    cin >> n;
    cout << "\nEnter the Adjacency Matrix : \n";
    for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        {
        cout << "Graph["<<i<<"]["<<j<<"] : "; 
        cin >> Graph[i][j];
        }          
    floyd(Graph, n); 
    return 0; 
}

/*
** Test Cases ** 

>> Case - 1

[INPUT]
Enter the number of vertices : 4

Enter the Adjacency Matrix : 
Graph[0][0] : 0
Graph[0][1] : 5
Graph[0][2] : 999
Graph[0][3] : 10
Graph[1][0] : 999
Graph[1][1] : 0
Graph[1][2] : 3
Graph[1][3] : 999
Graph[2][0] : 999
Graph[2][1] : 999
Graph[2][2] : 0
Graph[2][3] : 1
Graph[3][0] : 999
Graph[3][1] : 999
Graph[3][2] : 999
Graph[3][3] : 0

[OUTPUT]
The final distance matrix with shortest distance between every pair of vertices : 
0     5     8     9     
999     0     3     4     
999     999     0     1     
999     999     999     0     
 

>> Case - 2

[INPUT]
Enter the number of vertices : 4

Enter the Adjacency Matrix : 
Graph[0][0] : 0
Graph[0][1] : 9
Graph[0][2] : -4
Graph[0][3] : 999
Graph[1][0] : 6
Graph[1][1] : 0
9Graph[1][2] : 999
Graph[1][3] : 2
Graph[2][0] : 999
Graph[2][1] : 6 5
Graph[2][2] : 0
Graph[2][3] : 999
Graph[3][0] : 999
Graph[3][1] : 999
Graph[3][2] : 1
Graph[3][3] : 0


[OUTPUT]
The final distance matrix with shortest distance between every pair of vertices : 
0     1     -4     3     
6     0     2     2     
11     5     0     7     
12     6     1     0     

Complexities

Time Complexity = O(V^3)
Space Complexity = O(V^2)
*/ 
 


