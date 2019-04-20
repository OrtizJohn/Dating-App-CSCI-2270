#include <iostream>
#include <string>
#include "Human.hpp"
using namespace std;

Human::Human()
{

}

Human::Human(string nameC, int ageC, float heightC, string majorC,
  bool genderC, bool sexualOrientationC, int questionAnswersC[10]) //parameterized constructor
{
  name = nameC;
  age = ageC;
  height = heightC;
  major = majorC;
  gender = genderC;
  sexualOrientation = sexualOrientationC;
  for(int i = 0;i<10;i++)
  {
    questionAnswers[i] = questionAnswersC[i];
  }
  userName = nameC;
}

Human::~Human()
{

}

string Human::getName()
{
  return name;
}

void Human::setName(string nameC)
{
  name = nameC;
  userName = nameC;
}

int Human::getAge()
{
  return age;
}

void Human::setAge(int ageC)
{
  age = ageC;
}
float Human::getHeight()
{
  return height;
}

void Human::setHeight(float heightC)
{
  height = heightC;
}

string Human::getMajor()
{
  return major;
}

void Human::setMajor(string majorC)
{
  major = majorC;
}

bool Human::getGender()
{
  return gender;
}
void Human::setGender(bool genderC)
{
  gender = genderC;
}

bool Human::getSexualOrientation()
{
  return sexualOrientation;
}
void Human::setSexualOrientation(bool sexualOrientationC)
{
  sexualOrientation = sexualOrientationC;
}

int* Human::getQuestionAnswers()
{
  return questionAnswers;
}
void Human::setQuestionAnswers(int questionAnswersC[10])
{
  for(int i = 0;i<10;i++)
  {
    questionAnswers[i] = questionAnswersC[i];
  }
}
void Human::setPassword(string Password){
  password = Password;
}
string Human::getPassword(){
  return password;
}
