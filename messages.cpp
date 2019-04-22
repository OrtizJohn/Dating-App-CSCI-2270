#include <iostream>
#include <string>
#include <vector>
#inlcude "connectivityGraph.hpp"
using namespace std;
 //increment the vector of vector in connectivity graph like matched list and the vector of bools

 int main()
 {
   connectivityGraph *ptrG1 = &g1; //obtains a variable that uses the current user's data
   vector<int> list; //list of matches with indexes of people matched with the current user

   //obtains the list of matched indexes
   for(int i = 0; *ptrG1.vertices.size(); i++)
   {
     if(*ptrG1.swipedBack(*ptrG1.id, i))
     {
       list.push_back(i); //gets indexes of people who's matched with
     }
   }

   //outputs matched list
   for(int i = 0; i < list.size();i++)
   {
     cout << "You've matched with " << *ptrG1.IdToName(i) << endl;
   }

   //determines who is matched with who
   string input;
   cout << "Who would you like to talk to?" << endl;
   cout << "Or enter q to exit" << endl;
   getline(cin,input);
   while(input != 'q')
   {
     if(!(*ptrG1.isInGraph(input)) && *ptrG1.swipedBack(*ptrG1.id, *ptrG1.NameToId(input)))
     {
       break;
     }
     else
     {
       cout << "That is not a person you are matched with. Please enter a different name or enter q to exit" << endl;
       getline(cin,input);
       if(input == 'q')
       {
         break;
       }
     }
   }

   //messaging people
   if(input != 'q') //if they entered a correct name they matched with
   {
     int index = *ptrG1.NameToId(input);
     int choice;
     while(choice != 4)
     {
       cout << "Select an option: " << endl;
       cout << "1) Send a message to " << input << endl;
       cout << "2) See messages with " << input << endl;
       cout << "3) Unmatch with " << input << endl;
       cout << "4) Quit" << endl;
       switch(choice)
       {
         case 1:
         {
           if()//they have talked yet to determine who has messaged first
         }
         case 2:
         {
           if(*ptrG1.messages.empty()) //who messaged first to figure out algorithm to output
           {
             cout << "No messages between you and " << input << endl;
           }
           else //there are messages between the user and targeted person
           {
             if(*ptrG1.messagedFirst.at())
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
