 //     _____          ___                                 ___           ___                                        
 //    /  /::\        /  /\          ___                  /__/\         /  /\                        ___            
 //   /  /:/\:\      /  /:/_        /__/\                |  |::\       /  /::\                      /  /\           
 //  /  /:/  \:\    /  /:/ /\       \  \:\               |  |:|:\     /  /:/\:\    ___     ___     /  /:/           
 // /__/:/ \__\:|  /  /:/ /:/_       \  \:\            __|__|:|\:\   /  /:/~/:/   /__/\   /  /\   /  /:/            
 // \  \:\ /  /:/ /__/:/ /:/ /\  ___  \__\:\          /__/::::| \:\ /__/:/ /:/___ \  \:\ /  /:/  /  /::\            
 //  \  \:\  /:/  \  \:\/:/ /:/ /__/\ |  |:|          \  \:\~~\__\/ \  \:\/:::::/  \  \:\  /:/  /__/:/\:\           
 //   \  \:\/:/    \  \::/ /:/  \  \:\|  |:|           \  \:\        \  \::/~~~~    \  \:\/:/   \__\/  \:\          
 //    \  \::/      \  \:\/:/    \  \:\__|:|            \  \:\        \  \:\         \  \::/         \  \:\         
 //     \__\/        \  \::/      \__\::::/              \  \:\        \  \:\         \__\/           \__\/         
 //                   \__\/           ~~~~                \__\/         \__\/                                       
 //-----------------------------------------------------------------------------------------------------------
#include <iostream>
	#include <string>
	#include <algorithm>
	#include <ctype.h> 
#include <stdio.h> 

using namespace std;

class Filter{
protected:
  string _name;
public:  
  Filter(const string& name) : _name(name) {}
  virtual ~Filter() {};
  virtual string apply(const string& input) = 0;
  string get_name(){return _name;}
};
//Cap all letters in string (done)
class Capitalize : public Filter{
 public:
  Capitalize(): Filter("Capitalize"){}
	string apply(const string& input){ string copy(input);
	  //loop over string and uppercase the whole string
	  transform(copy.begin(), copy.end(), copy.begin(), ::toupper);
	return copy;
}};
//reverse the string (done)
class ReverseString: public Filter{
 public:
  ReverseString(): Filter("ReverseString"){}
 //reverse all the string using the built in function
  string apply(const string& input){ string copy(input);
  	 reverse(copy.begin(), copy.end());
  	return copy;
}};
//to lower (done)
class ToSmall: public Filter{
 public:
 	ToSmall(): Filter("ToSmall"){}
  	string apply(const string& input){ string copy(input);
  	//loop over and lowercase everything
   		transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
			return copy;
}};
//Cap only first letter in string (done)
class CapitalizeFirstLetter: public Filter{
 public:
	CapitalizeFirstLetter(): Filter("CapitalizeFirstLetter"){}
 	string apply(const string& input){ string copy(input);
		copy[0] = toupper(copy[0]);
	  		return copy;
}};
//Randomize the string (Done)
class Randomize: public Filter{
 public:
	Randomize(): Filter("Randomize"){}
	string apply(const string& input){ string copy(input);
	  random_shuffle(copy.begin(), copy.end());
		return copy;
}};
//Cap first letter of every word in string (done)
class CapitalizeFirstLetterOfEveryWord: public Filter{
 public:
 CapitalizeFirstLetterOfEveryWord(): Filter("CapitalizeFirstLetterOfEveryWord"){}
 string apply(const string& input){ string copy(input);
	//initialize first letter as upper
	copy[0] = toupper(copy[0]);
	//loop over the rest of the string and upper rest
	for (int i = 0; i < copy.length(); ++i){
	 if(copy[i - 1] == ' ') copy[i] = toupper(copy[i]);
	  	}
	  	return copy;
}};
//--------------------------------------------
//(in progress)
class Obenglobish: public Filter{
 public:
 Obenglobish(): Filter("Obenglobish"){}
 string apply(const string& input){
		string copy(input);
		string space(" ");
//convert string to lowercase
transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
copy.replace(copy.find(space),space.length(), "  ");

for (int i = 0; i < copy.length(); ++i){
	switch(copy[i]){
		case 'a':
		copy[i] = 'o';
		case 'e':
		copy[i] = 'o';
		case 'i':
		copy[i] = 'o';
		case 'u':
		copy[i] = 'o';
		case 'y':
		copy[i] = 'o';
		case 'o':
		copy[i+1] = 'b';
		default:
		break;
	}
}
for (int i = 0; i < copy.length(); ++i){
	switch(copy[i]){
		case 'o':
		copy[i+1] = 'b';
		default:
		break;
	}
}
return copy;
}
};

int main(int argc, char const *argv[]){
	const int num_filters = 7;
Filter* filters[num_filters];
//-----------------------------------------------------------|---------F
filters[0] = new Capitalize();//-----------------------------|---------i
	filters[1] = new CapitalizeFirstLetter();//--------------|---------l
		filters[2] = new CapitalizeFirstLetterOfEveryWord();//---------t
		filters[3] = new Obenglobish();//--------------------|---------e
		filters[4] = new ReverseString();//------------------|---------r
	filters[5] = new ToSmall();//----------------------------|---------C
filters[6] = new Randomize();//------------------------------|---------o
//___________________________________________________________|---------d
//															  ---------e
string input;

std::cout << "Enter string: ";  getline(cin, input);
std::cout << "Input string: " << input << std::endl;

for (int i=0; i<num_filters; ++i) {
  std::cout << "Filter name:  " << filters[i]->get_name() << std::endl;
  std::cout << "Output:       " << filters[i]->apply(input) << std::endl;}

for (int i=0; i<num_filters; ++i) delete filters[i];
	return 0;
}
