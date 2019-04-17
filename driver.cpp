#include<iostream>
#include<string>
#include<fstream>
#include"connectivityGraph.hpp"

using namespace std;

int main(int argc, const char *argv[])
{


  ConnectivityGraph g1;
  g1.addVertex("Coral");
  g1.addVertex("John Mic Big Dick");
  g1.addVertex("Christian");
  g1.addVertex("Sara");
  g1.addVertex("Admin");
  g1.addVertex("James");
  g1.addVertex("Julia");
  g1.addEdge(g1.NameToId("Admin"),g1.NameToId("Coral"));
  g1.addEdge(g1.NameToId("John Mic Big Dick"),g1.NameToId("Christian"));
  g1.addEdge(g1.NameToId("Christian"),g1.NameToId("Admin"));
  g1.addEdge(g1.NameToId("Coral"),g1.NameToId("Admin"));
  g1.addEdge(g1.NameToId("James"),g1.NameToId("Sara"));
  g1.addEdge(g1.NameToId("John Mic Big Dick"),g1.NameToId("Julia"));
  g1.addEdge(g1.NameToId("Julia"),g1.NameToId("John Mic Big Dick"));
  g1.addEdge(g1.NameToId("Christian"),g1.NameToId("John Mic Big Dick"));

  g1.displayEdges();
  cout<< endl;
  g1.Matches(g1.NameToId("John Mic Big Dick"));
  g1.Matches(g1.NameToId("Admin"));
  return 0;
}
