#include <iostream>
#include <stack>
#include <queue>
//#include <SDL.h>
#include <fstream>
#include <string.h>

using namespace std;




int **graph; // stores elements from input file here

struct node{
  int index;
  int priority;
};



void DISPLAY_GRAPH(int ** graph, int V)
{
  cout << V << endl;
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (graph[i][j] == 1)
	cout << j << " ";
    }
    cout << V << endl;
  }
  cout << V;
}


int ASSIGN_COLOURS(int ** graph, int V)
{
  for (int i = 0)


}

int main(int argc, char **argv)
{

  ifstream input_file; // ifstream  descriptor
  int V =0;

  
  if (argc < 2)
  {
    string defaut_file = "default.txt";
    cout <<" no arguements passed.. " <<endl <<" opening default file.. " <<endl;
    input_file.open(defaut_file); 
  }else
  {
    cout <<" file name was supplied.. " <<endl <<" attempting to open.. " << argv[1] <<endl;
    input_file.open(argv[1]); // open file
  }
  input_file >> V; // read and store first input here  
  int read = 0;
  graph = new int *[V]; // allocate memory - will be freed later -

  //loop inserting values and storing them in graph 
  for (int i = 0; i < V; i++)
  {
    graph[i] = new int[V]; 
    for (int j = 0; j < V; j++)
    {
      graph[i][j] = 0; //initilaize matrix (2d array) with 0s
    }
    input_file >> read; // start reading from file and inserting data to read  
    while (read != V)
    {
      graph[i][read] = 1;
      input_file >> read;
    }
   }
  input_file.close(); // close file after reading
  cout << " Input Graph : " <<endl; // display to screen 
  DISPLAY_GRAPH(graph, V); // display content inside 2d array 
  cout << endl;
  cout <<endl;
 
}
