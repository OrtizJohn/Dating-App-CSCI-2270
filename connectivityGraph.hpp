
#ifndef CONNECTIVITYGRAPH_HPP
#define CONNECTIVITYGRAPH_HPP

#include <vector>
#include <iostream>
#include "Human.hpp"

using namespace std;

struct PersonVertex;

/*this is the struct for each vertex in the graph. */
struct PersonVertex
{
    int id;//will be representative of there name
    vector<PersonVertex*> Edges; //stores edges to adjacent vertices
    bool visited;//boolean if it is visited
    vector<bool>MatchedList;//list to check if they have been matched before
    Human h1;//person object not sure if should be here
    vector<float> differenceValues;
};

class ConnectivityGraph
{
    public:
    ConnectivityGraph(); //constructor that does not need to do anything
    ~ConnectivityGraph();//destructor that will free all memory
    void addEdge(int v1, int v2);//this will connect one person to another
    void addVertex(string name);//will create new Person vertex -add name to names vector
    void displayEdges(); //displays who is connected to who
    //void printDFT(); //depth first traversal not sure if needed
    //void printBFT(); //breadth first traversal not sure if needed
    void setAllVerticesUnvisited();//this will set all person verteces to not be visited
    string IdToName(int id); //flip the id to name
    int NameToId(string name);//flips the name to the id associated with it
    void updateInfo(int id);//updates Human opject's info
    bool swipedBack(int id_1,int id_2);//check if the person you matched with is connected back
    void Matches(int id);//prints out who is connected back to user(in this case the id that it is called with)
    float findDiff(Human, Human); //finds the differenceValues for a pair of humans

  private:
    vector<PersonVertex> vertices; //stores vertices
    vector<string>names; //stores the names of each person with corresponding id
    int currentAmtOfNames; //will count the current Amt Of Names
    void incrementMatchedList();//will increase the amount in each person's matched list


    PersonVertex *findVertex(int id);//will find a person vertex in verteces vector
    //void BFTraversal(vertex *v);//helper BFT
    //void DFTraversal(vertex *v);//helper to DFT

};

#endif // GRAPH_HPP
