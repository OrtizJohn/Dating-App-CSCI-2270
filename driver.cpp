#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<math.h>
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
  int arrg1[] = {0,1,2,3,4,5,1,2,3,4};
  int arrg2[] = {5,4,3,2,1,0,5,4,3,2};
  for(int i = 0;i<10;i++)
  {
    //arrg[i] = rand()%6;
  }

  Human h1("tom", 11, 4.5, "Christian Studies", 1, 0, arrg1);
  Human h2("Mark", 13, 7.8, "Being Stupid", 1, 0, arrg2);
  cout << h1.getName() << h1.getAge() << endl;
  int *a = h1.getQuestionAnswers();
  for(int i = 0;i<10;i++)
  {
    //cout << *(a+i) << endl;
  }
  cout << fixed << setprecision(2);
  cout << findDiff(h1, h2) << endl;
  // g1.displayEdges();
  // cout<< endl;
  // g1.Matches(g1.NameToId("John Mic Big Dick"));
  // g1.Matches(g1.NameToId("Admin"));
  return 0;
}
