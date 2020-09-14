/** Nawaf Alharbi 
*   CSCI422
*   Final Project
**/ 

#include"GraphColouring.h"

int main(int argc, char **argv) 
{ 

  const char* defaut_file_char = "testing_graph.txt";
  string default_file(defaut_file_char);
  int m;
  cout <<" IF no arguements passed.. " <<endl <<" I will attempt to open default file.. " <<endl;
  //string default_file(argv[1]);
  if (argc > 1)
  {
    default_file = argv[1];
    cout <<" file name was supplied " <<endl << " attempting to open.. \n " << argv[1] <<endl;
  }  
  if(READ_FILE("resources/" + default_file) == 0)// open file
    return 0;
  printf (" please enter the number of colours to check against graph ");
  cin >> m;
  GRAPH_COLORING(graph, m);
  return 1;
}
