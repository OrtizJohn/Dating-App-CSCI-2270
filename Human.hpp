#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>
using namespace std;

struct PersonVertex
{

};

class Human
{
public:
  Human();
  Human(string, int, float, string, bool, bool, int a[10]);
  ~Human();
  string getName();
  void setName(string);
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
  int findHuman(string);


private:
  string userName;
  string password = "password";
  int userIndex;
  string name;
  int age;
  float height;
  string major;
  bool gender; //1 for male 0 for female
  bool sexualOrientation; //1 for male 0 for female
  int questionAnswers[10];
};
#endif
