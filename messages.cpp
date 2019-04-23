#include <iostream>
#include <string>
#include <vector>
#include "connectivityGraph.hpp"
using namespace std;
 //increment the vector of vector in connectivity graph like matched list and the vector of bools

 int main()
 {
   string name = "Mark";
   ConnectivityGraph g1;
   PersonVertex *temp = g1.findVertex(g1.NameToId(name)); //obtains a variable that uses the current user's data
   vector<int> list; //list of matches with indexes of people matched with the current user

   //obtains the list of matched indexes
   for(int i = 0; g1.getCurrentAmtOfNames(); i++)
   {
     if(g1.swipedBack(temp->id, i))
     {
       list.push_back(i); //gets indexes of people who's matched with
     }
   }

   //outputs matched list
   for(int i = 0; i < list.size();i++)
   {
     cout << "You've matched with " << g1.IdToName(i) << endl;
   }

   //determines who is matched with who
   string input;
   cout << "Who would you like to talk to?" << endl;
   cout << "Or enter q to exit" << endl;
   getline(cin,input);
   while(input != "q")
   {
     if(!(g1.isInGraph(input)) && g1.swipedBack(temp->id, g1.NameToId(input)))
     {
       break;
     }
     else
     {
       cout << "That is not a person you are matched with. Please enter a different name or enter q to exit" << endl;
       getline(cin,input);
       if(input == "q")
       {
         break;
       }
     }
   }

   //messaging people
   if(input != "q") //if they entered a correct name they matched with
   {
     int index = g1.NameToId(input);
     string choice;
     while(stoi(choice) != 4)
     {
       cout << "Select an option: " << endl;
       cout << "1) Send a message to " << input << endl;
       cout << "2) See messages with " << input << endl;
       cout << "3) Unmatch with " << input << endl;
       cout << "4) Quit" << endl;
       getline(cin, choice);
       switch(stoi(choice))
       {
         case 1:
         {
           string message;
           //they have talked yet to determine who has messaged first
           if(temp->messages.empty()) //if you have messaged messaged First
           {
             temp->messagedFirst.at(g1.NameToId(input)) = true;
             cout << "Enter your message: " << endl;
             getline(cin, message);
             temp->messages[g1.NameToId(input)][0] = message;
           }
           else
           {
             cout << "Enter your message: " << endl;
             getline(cin, message);
             temp->messages[g1.NameToId(input)].push_back(message);
           }
         }
         case 2:
         {
           if(temp->messages.empty()) //who messaged first to figure out algorithm to output
           {
             cout << "No messages between you and " << input << endl;
           }
           else //there are messages between the user and targeted person
           {
             if(temp->messagedFirst.at(g1.NameToId(input))) //user send first message
             {
               for(int i = 0; i < temp->messages[g1.NameToId(input)].size(); i++)
               {
                 cout << "You: " << temp->messages[g1.NameToId(input)][i] << endl << endl;
                 cout << input << ": ";
                 cout << temp->messages[g1.NameToId(input)][i+1] << endl << endl;
               }
             }
             else //targeted person has sent first message
             {
               for(int i = 0; i < temp->messages[g1.NameToId(input)].size(); i++)
               {
                 cout << input << ": ";
                 cout << temp->messages[g1.NameToId(input)][i] << endl << endl;
                 cout << "You: " << temp->messages[g1.NameToId(input)][i+1] << endl << endl;
               }
             }
           }
         }
         case 3:
         {
           //remove edge from current user to user targeted
         }
         case 4:
         {
           //return to main menu
           break;
         }
         default:
         {
           cout << "That is not an option. Please select a valid option" << endl;
         }
       }
     }
   }
   else //if they entered q
   {
     //return back to the main menu
   }
}
