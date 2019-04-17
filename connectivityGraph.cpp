#include<iostream>
#include<string>
#include<fstream>
#include"connectivityGraph.hpp"

using namespace std;



ConnectivityGraph::ConnectivityGraph(){
  currentAmtOfNames =0;
}
ConnectivityGraph::~ConnectivityGraph(){

}

void ConnectivityGraph::addVertex(string name){
  PersonVertex v1;
  v1.id = currentAmtOfNames;
  names.push_back(name);

  currentAmtOfNames++;
  incrementMatchedList();
  vertices.push_back(v1);
}

void ConnectivityGraph::incrementMatchedList(){
  for(int i=0;i<vertices.size();i++){
    vertices[i].MatchedList.push_back(0);
  }
}

void ConnectivityGraph::addEdge(int v1, int v2){
  PersonVertex *Edge = findVertex(v2);
  PersonVertex *temp = findVertex(v1);
  temp->Edges.push_back(Edge);
}


string ConnectivityGraph::IdToName(int id){
  for(int i=0;i<names.size();i++){
    if(i == id){
      return names[i];
    }
  }
  return "Not in Name Vector :(";
}

int ConnectivityGraph::NameToId(string name){
  for(int i=0;i<names.size();i++){
    if(names[i] == name){
      return i;
    }
  }
  return -1;
}
void ConnectivityGraph::displayEdges(){
  for(int i=0; i<vertices.size();i++){
    cout << IdToName(vertices[i].id) << "-->";
    //print each connection from edges vector
    for(int j=0; j<vertices[i].Edges.size();j++){

      cout<< IdToName(vertices[i].Edges[j]->id);
      if(j!=vertices[i].Edges.size()-1){
        cout<< "***";
      }
    }
    cout<< endl;
  }
}

PersonVertex* ConnectivityGraph::findVertex(int id){
  for (int i = 0; i<vertices.size();i++){
    if (vertices[i].id == id ){
      return &vertices[i];
    }
  }
  return NULL;
}

bool ConnectivityGraph::swipedBack(int id_1,int id_2){ //id_1 will be the user that will be checked in the second perons list of Edges
  PersonVertex *temp = findVertex(id_2);
  for(int i=0; i<temp->Edges.size();i++){
    if(temp->Edges[i]->id == id_1){
      //temp->MatchedList[id_1] = 1; //will be implemented once we correctly impmlement the Matches function
      return true;
    }
  }
  return false;
}
void ConnectivityGraph::Matches(int id){//use this persons id to check there connections and check if they matched back
  PersonVertex *temp = findVertex(id);
  cout << "Here are " << IdToName(id) << "'s matches: "<<endl;//for testing
  //cout<< "Here are your matches: "<<endl; //real print statement
  for(int i = 0; i<temp->Edges.size();i++){
    if(swipedBack(id, temp->Edges[i]->id)){
      cout<< "    " <<IdToName(temp->Edges[i]->id)<< endl;

    }
  }

}
