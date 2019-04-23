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
  setNameHuman(name);
  //v1.h1.setName(name);
  // cout<< v1.h1.getName()<<endl;
}

void ConnectivityGraph::incrementMatchedList(){
  for(int i=0;i<vertices.size();i++){
    vertices[i].MatchedList.push_back(0);
    vertices[i].messagedFirst.resize(vertices.size());
    vertices[i].messages.resize(vertices.size(),vector<string>(vertices.size(), ""));
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
  cout << "Here are your's matches: "<<endl;//for testing
  //cout<< "Here are your matches: "<<endl; //real print statement
  for(int i = 0; i<temp->Edges.size();i++){
    if(swipedBack(id, temp->Edges[i]->id)){
      cout<< "    " <<IdToName(temp->Edges[i]->id)<< endl;

    }
  }

}

bool ConnectivityGraph::AlreadyMatched(int UserId,int comparingId){
  PersonVertex *User = findVertex(UserId);
  for(int i = 0; i<User->Edges.size();i++){
    if((swipedBack(UserId, User->Edges[i]->id)) && (User->Edges[i]->id == comparingId)){
      cout<< "Already Matched with " <<IdToName(User->Edges[i]->id)<< endl;
      return true;

    }
  }
  return false;
}
bool ConnectivityGraph::checkLogin(string name,string password){
    PersonVertex *User = findVertex(NameToId(name));
    if(User == NULL){
      return true;
    }
    cout<<IdToName(User->id)<<endl;
    cout<<User->h1.getName()<<endl;
    cout<<User->h1.getPassword()<<endl;
    if ((User->h1.getName() == name)&&(User->h1.getPassword() == password)){
      cout<<"Welcome... " <<name<<endl;
      return false;
    }
    return true;

}

void ConnectivityGraph::setNameHuman(string name){
  PersonVertex *temp = findVertex(NameToId(name));
  temp->h1.setName(name);
}

void ConnectivityGraph::setHumanQualitites(string name,string password,int age,float height,string major,bool gender,bool sexualOrientation,int questionAnswers[10]){
  PersonVertex *temp = findVertex(NameToId(name));
  temp->h1.setPassword(password);
  temp->h1.setAge(age);
  temp->h1.setHeight(height);
  temp->h1.setMajor(major);
  temp->h1.setGender(gender);
  temp->h1.setSexualOrientation(sexualOrientation);
  temp->h1.setQuestionAnswers(questionAnswers);
}

void ConnectivityGraph::printHumanQualities(string name){
  PersonVertex *temp = findVertex(NameToId(name));
  int *questionAnswers = temp->h1.getQuestionAnswers();
  //cout<< "Here is your profile:"<<endl<<endl;
  cout<< "Name: " << name<<endl;
  cout<< "Age: " << temp->h1.getAge()<<endl;
  cout<<"Height: "<< temp->h1.getHeight()<<" inches"<<endl;
  cout<<"Declared Major: "<< temp->h1.getMajor()<<endl;
  if(temp->h1.getGender()) cout<<"Gender(biologically): Female"<<endl;
  else if(!temp->h1.getGender()) cout<<"Gender(biologically): Male"<<endl;
  if(temp->h1.getSexualOrientation()) cout<<"Sexually attracted to: Females"<<endl;
  else if(!temp->h1.getSexualOrientation()) cout<<"Sexually attracted to: Males"<<endl;
  cout<<"For the following questions you answered on a scale of 1(strongly disagree) to 5(strongly agree)..."<<endl;
  cout<<"You are very active. Answered: " <<questionAnswers[0]<<endl;
  cout<<"You are very organized. Answered: "<<questionAnswers[1]<<endl;
  cout<<"On a Friday Night, you would rather stay in and watch Netflix than go out and party. Answered: "<<questionAnswers[2]<<endl;
  cout<<"You love all types of sports. Answered: "<<questionAnswers[3]<<endl;
  cout<<"You are a nightowl. Answered: "<<questionAnswers[4]<<endl;
  cout<<"You are looking for a long term relationship. Answered: "<<questionAnswers[5]<<endl;
  cout<<"You are a good communicator. Answered: "<<questionAnswers[6]<<endl;
  cout<<"You like to be the center of attention. Answered: "<<questionAnswers[7]<<endl;
  cout<<"You are open to new ideas. Answered: "<<questionAnswers[8]<<endl;
  cout<<"There is nothing better in a partner than the ability to make you laugh. Answered: "<<questionAnswers[9]<<endl;

}
bool ConnectivityGraph::isInGraph(string name){
  PersonVertex *User = findVertex(NameToId(name));
  if(User == NULL){
    return false;
  }
  return true;
}

int ConnectivityGraph::getCurrentAmtOfNames(){
  return currentAmtOfNames;
}
