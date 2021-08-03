//I took out my ascii art because of your comments
//would have done it eariler if I has known
//Sorry
//By: MRLT (Nathaniel Armogan)
#include <fstream>
	#include <iostream>
#include <string>

using namespace std;

int occuranceCounter(string &strToCheck, string &inputFromUser);

int main(int argc, char** argv){
//set arguments to string vars for further work
  string fileName(argv[1]);
  string inputFromUser(argv[2]);
  string strToCheck("");
if (argc >= 3){
	//create string to store file into
	ifstream read(fileName);
  if(read.is_open()){ 
    getline(read,strToCheck,char(read.eof()));
    read.close();
	  std::cout << '"'<< inputFromUser << '"' << " was found " 
      << "[" << occuranceCounter(strToCheck,inputFromUser) << "] times.";

}
}
  return 0;
}
int occuranceCounter(string &strToCheck, string &inputFromUser){
 //define the varibles for loop and gen occurance
 int occurances = 0, stepOutter=0, stepInner = 0;
 while(stepOutter <= (strToCheck.length() - inputFromUser.length())){
            stepOutter++;
   for (; stepInner < inputFromUser.length(); stepInner++) 
     if (strToCheck[stepOutter+stepInner] != inputFromUser[stepInner]) 
       break; 
    if (stepInner == inputFromUser.length()){ 
      occurances++; stepInner = 0; 
    }
  } 
    return occurances; 
}