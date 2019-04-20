#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<math.h>
#include"connectivityGraph.hpp"

using namespace std;

void printLoginMenu(){
      //   Login
          // Login Name:
          // Password:
      // New User?
          // Proceed to Update Profile
      // End Program
  cout <<"1. Login"<<endl;
  cout <<"2. New User" <<endl;
  cout <<"3. End Dating App" <<endl;
}
void printUserMenu(){
  cout <<"1. Display Profile"<<endl;
  cout <<"2. " <<endl;
  cout <<"3. " <<endl;
  cout<< "4. "<<endl;
}

void userInterface(){
  bool go = true;
  while(go){
    printUserMenu();
    string ans="";
    getline(cin,ans);

    if(stoi(ans)==1){

    }
		else if(stoi(ans) == 2){

		}
    else if(stoi(ans)==3){


    }
    else if(stoi(ans) == 4){

		}
    else if(stoi(ans) == 5){
      cout << "Goodbye!" << endl;
      go = false;
		}




  }
}

int main(int argc, const char *argv[])
{


  ConnectivityGraph g1;
  // g1.addVertex("Coral");
  // g1.addVertex("John M");
  // g1.addVertex("Christian");
  // g1.addVertex("Sara");
  g1.addVertex("Admin");
  // g1.addVertex("James");
  // g1.addVertex("Julia");
  // g1.addEdge(g1.NameToId("Admin"),g1.NameToId("Coral"));
  // g1.addEdge(g1.NameToId("John M"),g1.NameToId("Christian"));
  // g1.addEdge(g1.NameToId("Christian"),g1.NameToId("Admin"));
  // g1.addEdge(g1.NameToId("Coral"),g1.NameToId("Admin"));
  // g1.addEdge(g1.NameToId("James"),g1.NameToId("Sara"));
  // g1.addEdge(g1.NameToId("John M"),g1.NameToId("Julia"));
  // g1.addEdge(g1.NameToId("Julia"),g1.NameToId("John M"));
  // g1.addEdge(g1.NameToId("Christian"),g1.NameToId("John M"));
  //
  // g1.displayEdges();
  // cout<< endl;
  // g1.Matches(g1.NameToId("John M"));
  // g1.Matches(g1.NameToId("Admin 23"));

  // Human h1("tom", 11, 4.5, "Christian Studies", 1, 0, arrg1);
  // Human h2("Mark", 13, 7.8, "Being Stupid", 1, 0, arrg2);
  // cout << h1.getName() << h1.getAge() << endl;
  // int *a = h1.getQuestionAnswers();
  // for(int i = 0;i<10;i++)
  // {
  //   //cout << *(a+i) << endl;
  // }
  // cout << fixed << setprecision(2);
  // cout << findDiff(h1, h2) << endl;








  bool go = true;

  while(go){
    printLoginMenu();
    string ans="";
    getline(cin,ans);

    if(stoi(ans)==1){
      bool incorrectCredentials =true;
      while(incorrectCredentials){
        string FullName;
        string Password;
        cout<< "Enter the following: "<< endl;
        cout<<"Full Name: ";
        getline(cin,FullName);
        cout << "Password: ";
        getline(cin,Password);

        incorrectCredentials= g1.checkLogin(FullName,Password);
        if(incorrectCredentials = true){
          cout<< "I'm sorry you are not recognized in the data base, please try again..." <<endl;
          cout<<endl;
        }
        //incorrectCredentials = false;
      }


      //userInterfacecall
    }




		else if(stoi(ans) == 2){
      string name;
      cout<< "To register for an account please enter your Name: ";
      getline(cin,name);
      g1.addVertex(name);
      //g1.updateHumanInfo
		}
    else if(stoi(ans)==3){
      cout << "Goodbye!" << endl;
      go = false;

    }



  }
  return 0;
}
