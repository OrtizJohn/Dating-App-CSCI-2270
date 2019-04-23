#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<math.h>
#include"connectivityGraph.hpp"
#include "PriorityQueue.hpp"

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
  cout<< "  4. Matched People (messages)"<<endl;
  cout<< "  5. Log Out"<<endl;
  cout<<"--------------------------"<<endl;
}

void UpdateHumanHelper(ConnectivityGraph* g1,string name, string password,bool newUser){
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
  string q11,q22,q33,q44,q55,q66,q77,q88,q99,q1010;
  int q1,q2,q3,q4,q5,q6,q7,q8,q9,q10;
  cout<<"The next 10 questions please answer on a scale of 1-5 (1-strongly disagree, 5-strongly agree)?"<<endl;
  cout<<"You are very active."<<endl;
  getline(cin,q11);
  q1 = stoi(q11);
  arr[0]=q1;
  cout<<"You are very organized."<<endl;
  getline(cin,q22);
  q2 = stoi(q22);
  arr[1]=q2;
  cout<<"On a Friday Night, you would rather stay in and watch Netflix than go out and party."<<endl;
  getline(cin,q33);
  q3 = stoi(q33);
  arr[2]=q3;
  cout<<"You love all types of sports."<<endl;
  getline(cin,q44);
  q4 = stoi(q44);
  arr[3]=q4;
  cout<<"You are a nightowl."<<endl;
  getline(cin,q55);
  q5 = stoi(q55);
  arr[4]=q5;
  cout<<"You are looking for a long term relationship."<<endl;
  getline(cin,q66);
  q6 = stoi(q66);
  arr[5]=q6;
  cout<<"You are a good communicator."<<endl;
  getline(cin,q77);
  q7 = stoi(q77);
  arr[6]=q7;
  cout<<"You like to be the center of attention."<<endl;
  getline(cin,q88);
  q8 = stoi(q88);
  arr[7]=q8;
  cout<<"You are open to new ideas."<<endl;
  getline(cin,q99);
  q9 = stoi(q99);
  arr[8]=q9;
  cout<<"There is nothing better in a partner than the ability to make you laugh."<<endl;
  getline(cin,q1010);
  q10 = stoi(q1010);
  arr[9]=q10;
  cout<<"[";
  for(int i=0;i<10;i++){
    cout<< arr[i]<<",";
  }
  cout<<"]"<<endl;
  g1->setHumanQualitites(name,password,age,height,major,gender,sexualOrientation,arr);

  if(newUser){
    cout<<"Great you will now be taken back to the main menu to login..."<<endl<<endl;

  }
  else{
    cout<< "Your profile has been updated!"<<endl<<endl;
  }





}

void UpdateHuman(ConnectivityGraph* g1, string name,bool newUser){


  string password;
  string updateProfileAns;
  if(newUser){
    cout<<"This is where you will be updating your profile..."<<endl<<endl;
    cout<< "Before starting, we need you to set up your password, your full name will be your username, so what would you like your password to be? "<<endl;
    getline(cin,password);
    //UpdateHumanHelper
    UpdateHumanHelper(g1,name,password,1);
  }
  else{
    PersonVertex *temp = g1->findVertex(g1->NameToId(name));
    password = temp->h1.getPassword();
    UpdateHumanHelper(g1,name,password,0);
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
      g1->printHumanQualities(name);

    }
		else if(stoi(ans) == 2){
      UpdateHuman(g1,name,0);
		}
    else if(stoi(ans)==3){
      // bool runQueue = true;
      // PersonVertex *temp = g1->findVertex(g1->NameToId(name));
      // Queue q1 (g1->getCurrentAmtOfNames(),*temp);
      // for(int i =0; i<g1->getCurrentAmtOfNames();i++){
      //   if((i!= g1->NameToId(name)) && (!g1->AlreadyMatched(g1->NameToId(name),i))){ //write an and statement to check if already matched with a person
      //     PersonVertex *comparingUser = g1->findVertex(i);
      //     q1.enqueue(*comparingUser);
      //
      //   }
      //
      // }

      //bool continue = true;
      //while (continue)
      //create the queue
      //enqueue everyone
      //not enqueu already matched ppl
      //peek front queue print out information
      //Ask if they are interested or not
      //if yes
        //add edge to this persons
        //check if the other person has already swiped back so then we can add them to be an immediate match
        //dequeue
      //if no
        //dequeue
      //if they want to keep searching
        //continue cycle



        PersonVertex *temp = g1->findVertex(g1->NameToId(name));
        cout<< "current amt of names" <<g1->getCurrentAmtOfNames()<<endl;
        Queue *q1 = new Queue(g1->getCurrentAmtOfNames(),*temp);

        for(int i =0; i<g1->getCurrentAmtOfNames();i++){
          cout<<"index: "<<i<<", index of User: " <<g1->NameToId(name)<<endl;
          if((i!= g1->NameToId(name)) && (!g1->swipedBack(i,g1->NameToId(name)))){ //write an and statement to check if already matched with a person
            cout<<"hi"<<endl;
            PersonVertex *comparingUser = g1->findVertex(i);
            cout<<"adding " <<g1->IdToName(i)<<endl;
            cout<< g1->IdToName(comparingUser->id)<<endl;
            q1->enqueue(*comparingUser);


          }
        }
        bool continue1 = true;
        while(continue1){
          if(q1->isEmpty()){
            //cout<<"There is no potential matches for you, you might want to consider updating your profile..."<<endl;
            continue1=false;
          }else{
            string matchAnswer;
            string continueLookingAtQueue;
            //PersonVertex PotentialMatch = q1->peek();
            PersonVertex PotentialMatch = q1->peek();
            cout<<endl;
            cout<<"Here is your recommended match: "<<endl;
            g1->printHumanQualities(g1->IdToName(PotentialMatch.id));
            cout<<endl;
            cout<<"Would you be interested in talking with this person? (yes or no)"<<endl;
            getline(cin,matchAnswer);
            if(matchAnswer == "yes"){
              g1->addEdge(g1->NameToId(name),g1->NameToId(g1->IdToName(PotentialMatch.id)));
              q1->dequeue();


            }
            else if(matchAnswer == "no"){
              q1->dequeue();

            }

            cout<<"Want to continue looking for your potential matches?"<<endl;
            getline(cin,continueLookingAtQueue);
            if(continueLookingAtQueue == "yes"){
              cout<< "We will check who is the next best potential match"<<endl;
            }
            else if(continueLookingAtQueue == "no"){
              cout<<"Ok you will be brought back to the menu screen."<<endl;
              continue1=false;
            }
          }

        }

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
  g1.addVertex("Coral");
  g1.addVertex("John M");
  g1.addVertex("Christian");
  g1.addVertex("Sara");
  g1.addVertex("Admin");
  // PersonVertex *temp = g1.findVertex(g1.NameToId("Admin"));
  // temp->h1.setName("Bob");
  // cout<< temp->h1.getName()<<endl;

  // PersonVertex *temp1 = g1.findVertex(g1.NameToId("Admin"));
  // cout<< temp1->h1.getName()<<endl;
  // cout<<endl;
  // cout <<g1.checkLogin("Admin","password");
  g1.addVertex("James");
  g1.addVertex("Julia");
  g1.addEdge(g1.NameToId("Admin"),g1.NameToId("Coral"));
  g1.addEdge(g1.NameToId("John M"),g1.NameToId("Christian"));
  g1.addEdge(g1.NameToId("Christian"),g1.NameToId("Admin"));
  g1.addEdge(g1.NameToId("Coral"),g1.NameToId("Admin"));
  g1.addEdge(g1.NameToId("James"),g1.NameToId("Sara"));
  g1.addEdge(g1.NameToId("John M"),g1.NameToId("Julia"));
  g1.addEdge(g1.NameToId("Julia"),g1.NameToId("John M"));
  g1.addEdge(g1.NameToId("Christian"),g1.NameToId("John M"));

  int AdminArr[10]={1,1,1,1,1,1,1,1,1,1};
  g1.setHumanQualitites("Admin","password",21,62.3,"computer science",0,1,AdminArr);
  g1.setHumanQualitites("Christian","password",18,42.3,"business",0,0,AdminArr);
  g1.setHumanQualitites("Coral","password",17,42.3,"physics",0,0,AdminArr);
  g1.setHumanQualitites("John M","password",19,42.3,"business",0,0,AdminArr);
  g1.setHumanQualitites("Julia","password",16,42.3,"business",1,0,AdminArr);
  g1.setHumanQualitites("James","password",16,42.3,"business",1,0,AdminArr);
  g1.setHumanQualitites("Sara","password",34,53.3,"business",1,0,AdminArr);
  //g1.displayEdges();
  cout<<endl;

    //cout<<g1.AlreadyMatched(g1.NameToId("Admin"),g1.NameToId("Coral"))<<endl;





    //bool continue = true;
    //while (continue)
    //create the queue
    //enqueue everyone
    //not enqueu already matched ppl
    //peek front queue print out information
    //Ask if they are interested or not
    //if yes
      //add edge to this persons
      //check if the other person has already swiped back so then we can add them to be an immediate match
      //dequeue
    //if no
      //dequeue
    //if they want to keep searching
      //continue cycle





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
        //ConnectivityGraph *ptrG1 = &g1;
        userInterface(&g1,userName);
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
