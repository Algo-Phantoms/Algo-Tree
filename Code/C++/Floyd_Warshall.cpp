// C++ Program for Floyd Warshall Algorithm 
// Dynamic Programming
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
Time Complexity = O(V^3)
Space Complexity = O(V^2)
*/ 
 


