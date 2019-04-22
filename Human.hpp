#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>
using namespace std;

class Human
{
public:
  Human();
  Human(string, int, float, string, bool, bool, int a[10]);
  ~Human();
  string getName();
  void setName(string);

  //changed
  void setPassword(string);
  string getPassword();


  int getAge();
  void setAge(int);
  float getHeight();
  void setHeight(float);
  string getMajor();
  void setMajor(string);
  bool getGender();
  void setGender(bool);
  bool getSexualOrientation();
  void setSexualOrientation(bool);
  int *getQuestionAnswers();
  void setQuestionAnswers(int [10]);

private:
  //string userName; will not need cause have to use full name to recognize them by
  string password = "password"; //I think this needs to be changed to actually hold a password
  int userIndex;
  string name;
  int age;
  float height;
  string major;
  bool gender; //0 for male 1 for female
  bool sexualOrientation; //0 for male 1 for female
  int questionAnswers[10];
};
#endif
