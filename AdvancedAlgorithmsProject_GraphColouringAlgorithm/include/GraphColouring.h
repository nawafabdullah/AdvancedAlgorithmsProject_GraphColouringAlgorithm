/** Nawaf Alharbi 
*   CSCI422
*   Final Project
**/ 

#include<stdio.h> 
#include<stdbool.h> 
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
// MAX Number of vertices in the graph 
const int Max_Size = 10000;

int V = 0;
bool **graph; // stores elements from input file here

void DISPLAY_GRAPH(bool** graph)
{
 int i,j;
 for (i = 0; i < V; i++) //loop through printing elements like a matrix
 {
   for (j = 0; j < V; j++)
     printf (" %i \t", graph[i][j]);   
   printf ( "\n");
  }  
}

void PRINT_SOLUTION(int color[]); 
  
bool ISSAFE (int v, bool** graph, int color[], int c) 
{ 
    for (int i = 0; i < V; i++) 
      if (graph[v][i] && c == color[i]) //if position in matrix has 1 (i.e connected vertex)  & c already exisits in solution set return false, otherwise return tru  
	return false; 
    return true; 
} 
  

bool GRAPH_COLORING_U(bool **graph, int m, int color[], int v) 
{ 
  if (v == V) // if graph contains no more connected vertices - BASE CASE - (i.e continue recursion until v = V 
    return true; // since now v = V that means all vertices were colored  
  
    /* Consider this vertex v and try different colors .. C represent the color number */
  for (int c = 1; c <= m; c++) // - LOOPS M TIMES THEN INSIDE IS_SAFE it loops V times, SO M^V  - TIME!!
    { 
        /* Check if assignment of color c to v is fine*/

      /* basically function will recieve a row number and check all element in row has diffrent colors */
        if (ISSAFE(v, graph, color, c)) 
	{ 
	  color[v] = c;
	  
	  if (GRAPH_COLORING_U(graph, m, color, v+1) == true) // recursion happes V times, SO COMPLEXITY IS O(V M^V)
	    return true;   
	  color[v] = 0; // If assigning color c doesn't lead to a solution then remove it  
        } 
    }   
    /* If no color can be assigned to this vertex then return false */
    return false; 
} 
  

bool GRAPH_COLORING(bool** graph, int m) 
{   
  int color[V]; //solutio is stored here. Note: storage size is same number as vertices because each vertex wil get a colour assigned  
  for (int i = 0; i < V; i++) // initilaize all colours to 0 
    color[i] = 0; 
  
    // Call graphColoringUtil() for vertex 0 
  if (GRAPH_COLORING_U(graph, m, color, 0) == false) 
  { 
    printf(" Solution does not exist"); 
    printf("\n"); 
    return false; 
  } 
  PRINT_SOLUTION(color); // Print the solution
  return true; 
} 
  
/* A utility function to print solution */
void PRINT_SOLUTION(int color[]) 
{ 
  printf(" Solution Exists:"
	 " Following are the assigned colors \n"); 
  for (int i = 0; i < V; i++) 
    printf(" %d ", color[i]); 
  printf("\n"); 
}

int READ_FILE(string fn)
{
  ifstream f;
  int v,u;  
  f.open(fn);
  if (!f.is_open())
  {
    perror(" could NOT open file ... \n exiting program ... \n");
    return 0;   
  }

  f >> V;   
  graph = new bool* [V];            // Less is nxn array of bool 
  for (int i=0; i<V; i++)
  {        
    graph[i]=new bool[V];           // Construct initial tables within the array           
    for (int j=0; j<V; j++) 
      graph[i][j]=false;    
  }

  printf (" Reading %i nodes... \n", V);   
  f >> u;
  while (u<V && f)
  {
    f >> v; 
    while (v <V && f)
    {
      graph[u][v] = true; //since relation is identified above
      f >> v;  
    }
    f >> u;
  }
  f.close(); 
  DISPLAY_GRAPH(graph);   
  printf (" FINISHED \n");
  return 1;
}

