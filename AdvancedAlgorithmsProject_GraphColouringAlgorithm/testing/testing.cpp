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
bool **bool_graph;

void DISPLAY_GRAPH(bool** graph)
{
 int i,j;
 for (i = 0; i < V; i++) //loop through printing elements like a matrix
 {
   for (j = 0; j < V; j++)
     printf ("%i \t", graph[i][j]);   
   printf ("\n");
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
      printf("Solution does not exist"); 
      return false; 
    } 
    PRINT_SOLUTION(color); // Print the solution
    return true; 
} 
  
/* A utility function to print solution */
void PRINT_SOLUTION(int color[]) 
{ 
    printf("Solution Exists:"
            " Following are the assigned colors \n"); 
    for (int i = 0; i < V; i++) 
      printf(" %d ", color[i]); 
    printf("\n"); 
}

int READ_FILE(string fn)
{
  cout <<"entered"<<endl;
  ifstream f;
  int v,u;  
  f.open(fn);

  cout <<"here OPENED FILE" <<endl;
 //  if (!f)
 // cerr<<"File not openable. "<<endl; return 0;
  f >> V;   
  //cout <<"here V is: "<< V <<endl;
  graph = new bool* [V];            // Less is nxn array of bool 
  // cout <<"here V is: "<< V <<endl;
  for (int i=0; i<V; i++)
  {        // Less[u][v] means u<v in the poset
    graph[i]=new bool[V];           // Construct initial tables within the array           
    for (int j=0; j<V; j++) 
      graph[i][j]=false;    
  }

  cout << "Reading " << V <<  " nodes..." << endl;
  //if (V>) { cerr<<"n too large: "<<n<<endl; return 0;} // arbitrary
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
   cout << " FINISHED "<<endl;
}


// driver program to test above function 
int main(int argc, char **argv) 
{ 

  const char* defaut_file_char = "default.txt";
  string default_file(defaut_file_char);
  int m;
  cout <<" IF no arguements passed.. " <<endl <<" I will attempt to open default file.. " <<endl;
  //  string default_file(argv[1]);
  if (argc > 1)
  {
    string default_file(argv[1]);
    cout <<" file name was supplied " <<endl << " attempting to open.. " << argv[1] <<endl;
  }  

  //cout <<" attempting to open.. " << argv[1] <<endl;
  //  string default_file(argv[1]);
  READ_FILE(default_file); // open file
  cout <<" please enter the number of colours to check against graph" <<endl;
  cin >> m;
  GRAPH_COLORING(graph, m);

}



  /*input_file >> V; // read and store first input here  
  int read =0;
  int v =0;
  graph = new int *[V]; // allocate memory - will be freed later -
  bool_graph = new bool *[V]; 
  
//loop inserting values and storing them in graph 
  for (int i = 0; i < V; i++)
  {
    graph[i] = new int[V]; 
    bool_graph[i]=new bool[V];

    for (int j = 0; j < V; j++)
    {      
      graph[i][j] = 0; //initilaize matrix (2d array) with 0s
      bool_graph[i][j]=false;
    }



    input_file >> read; // start reading from file and inserting data to read  
    while (read < V && input_file)
    {
      graph[i][read] = 1;
      input_file >> v;
      while(v < V && input_file)
      {
      bool_graph[i][read] = 1;
      input_file >> v;
      }
      input_file >> read;
    }
  }
 





  input_file.close(); // close file after reading
  cout << " Input Graph : " <<endl; // display to screen 
  DISPLAY_GRAPH(graph, V); // display content inside 2d array 
  // cout << endl;
  

int m = 1; // Number of colors
/*
  for (int i=0; i<V; i++)
  {        // Less[u][v] means u<v in the poset
               // Construct initial tables within the array          
    for (int j=0; j<n; j++)
      
 
  }
   
     // cout << "Reading " << n <<  " nodes..." << endl;
   if (V > Max_Size) { cerr<<"n too large: "<<n<<endl; return 0;} // arbitrary

   f >> u;

   while (u<n && f)
   {
     f >> v; 
     while (v <n && f) {
       Less[u][v] = true; //since relation is identified above
       Covers[u][v] = true;
       f >> v;  
     }
     f >> u;
   }

*/






  //  graphColoring (bool_graph, m);
	
 






 
