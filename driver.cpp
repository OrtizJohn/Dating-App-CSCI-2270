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
  cout<<"------------------------"<<endl;
  cout <<"  1. Login"<<endl;
  cout <<"  2. New User" <<endl;
  cout <<"  3. End Dating App" <<endl;
  cout<<"------------------------"<<endl;
}
void printUserMenu(){
  cout<<"--------------------------"<<endl;
  cout <<"  1. Display Profile"<<endl;
  cout <<"  2. Update Profile" <<endl;
  cout <<"  3. Potential Matches" <<endl;
  cout<< "  4. Matched People"<<endl;
  cout<< "  5. Log Out"<<endl;
  cout<<"--------------------------"<<endl;
}

void UpdateHumanHelper(ConnectivityGraph* g1,string name, string password){
//string name,string password,int age,float height,string major,bool gender,bool sexualOrientation,int questionAnswers[10]
  string age1,height1,gender1,sexualOrientation1;
  int age;
  float height;
  string major;
  bool gender;
  bool sexualOrientation;
  int arr [10];

  cout<<"What is your age?"<<endl;
  getline(cin,age1);
  age = stoi(age1);
  cout<<"What is your height (in inches)?" <<endl;
  getline(cin,height1);
  height = stof(height1);
  cout<< "What is your major?" <<endl;
  getline(cin,major);
  cout<< "What is your sex(male or female -biological)? If you are a male please put 0, if you are a female please put 1." <<endl;
  getline(cin,gender1);
  if(gender1 == "0") gender = 0;
  else if(gender1 == "1") gender = 1;
  cout<<"What is your sexualOrientation? If you are attracted to biological males plese put 0, if you are attracted to biological females please put 1." <<endl;
  getline(cin,sexualOrientation1);
  if(sexualOrientation1 == "0") sexualOrientation = 0;
  else if(sexualOrientation1 == "1") sexualOrientation= 1;

  cout<<endl;
  //cout<< age<< " years old, " <<height <<" inches tall, " << " taking " <<major << "you are a " <<gender<< "you are attracted to " <<sexualOrientation<<endl;
  int q1,q2,q3,q4,q5,q6,q7,q8,q9,q10;
  cout<<"The next 10 questions please answer on a scale of 1-5 (1-strongly disagree, 5-strongly agree)?"<<endl;


}

void UpdateHuman(ConnectivityGraph* g1, string name,bool new1){


  string password;
  string updateProfileAns;
  if(new1){
    cout<<"This is where you will be updating your profile..."<<endl<<endl;
    cout<< "Before starting, we need you to set up your password, your full name will be your username, so what would you like your password to be? "<<endl;
    getline(cin,password);
    //UpdateHumanHelper
    UpdateHumanHelper(g1,name,password);
  }
  else{
    PersonVertex *temp = g1->findVertex(g1->NameToId(name));
    password = temp->h1.getPassword();
    UpdateHumanHelper(g1,name,password);
  }




}



void userInterface(ConnectivityGraph *g1,string name){
  bool userInterface = true;

  while(userInterface){
    printUserMenu();
    string ans="";
    getline(cin,ans);

    if(stoi(ans)==1){
      //display profile

    }
		else if(stoi(ans) == 2){

      //update profile call function
      UpdateHuman(g1,name,0);
		}
    else if(stoi(ans)==3){


    }
    else if(stoi(ans) == 4){

		}
    else if(stoi(ans) == 5){
      cout << "Logging out..." << endl;
      userInterface = false;
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
  // PersonVertex *temp = g1.findVertex(g1.NameToId("Admin"));
  // temp->h1.setName("Bob");
  // cout<< temp->h1.getName()<<endl;

  // PersonVertex *temp1 = g1.findVertex(g1.NameToId("Admin"));
  // cout<< temp1->h1.getName()<<endl;
  // cout<<endl;
  // cout <<g1.checkLogin("Admin","password");

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
  cout<<"Welcome to CU Boulder's newest and most hightech Dating App!!!"<<endl;
  while(go){
    printLoginMenu();
    string ans="";
    getline(cin,ans);

    if(stoi(ans)==1){
      bool incorrectCredentials =true;
      bool goBackToLogin = false;
      string userName="";
      while(incorrectCredentials){
        string FullName;
        string Password;
        cout<< "Enter the following: "<< endl;
        cout<<"Full Name: ";
        getline(cin,FullName);
        userName = FullName;
        cout << "Password: ";
        getline(cin,Password);

        incorrectCredentials= g1.checkLogin(FullName,Password);
        if(incorrectCredentials){
          string tryingAgain;
          cout<< "I'm sorry you are not recognized in the data base." <<endl;
          cout<< "Would you like to try again (yes or no)? " <<endl;
          getline(cin,tryingAgain);
          cout<<endl;
          if(tryingAgain == "no"){
            incorrectCredentials = false;
            goBackToLogin= true;
          }
        }

      }
      if(goBackToLogin){
        //cout<< endl;
      }
      else{
        //cout<<"Heading to UserInterface..."<<endl;
        cout <<endl;
        cout<<"Which option would you like to perform?"<<endl;
        ConnectivityGraph *ptrG1 = &g1;
        userInterface(ptrG1,userName);
      }


    }




		else if(stoi(ans) == 2){
      string name;
      cout<< "To register for an account please enter your Name: ";
      getline(cin,name);
      g1.addVertex(name);
      ConnectivityGraph *ptrG1 = &g1;
      UpdateHuman(ptrG1,name,1);
		}
    else if(stoi(ans)==3){
      cout << "Goodbye!" << endl;
      go = false;

    }



  }


  return 0;
}
