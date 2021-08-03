/* 
 __                       __       __  _______   __     ________ 
|  \                     |  \     /  \|       \ |  \   |        \
| $$____   __    __  __  | $$\   /  $$| $$$$$$$\| $$    \$$$$$$$$
| $$    \ |  \  |  \|  \ | $$$\ /  $$$| $$__| $$| $$      | $$   
| $$$$$$$\| $$  | $$ \$$ | $$$$\  $$$$| $$    $$| $$      | $$   
| $$  | $$| $$  | $$ __  | $$\$$ $$ $$| $$$$$$$\| $$      | $$   
| $$__/ $$| $$__/ $$|  \ | $$ \$$$| $$| $$  | $$| $$_____ | $$   
| $$    $$ \$$    $$ \$$ | $$  \$ | $$| $$  | $$| $$     \| $$   
 \$$$$$$$  _\$$$$$$$      \$$      \$$ \$$   \$$ \$$$$$$$$ \$$   
          |  \__| $$                                                  
           \$$    $$                                                  
            \$$$$$$  
  
 Given Name: Nathaniel Armogan    
 Application Name: Hello World   
 Application Date: May 13, 2019
 Description: layed out bellow                                   
*/


#include <iostream>
#include <iomanip>

using namespace std;
//declares the function of the hello world first program of the sem
void Hello();

int main(int argc, char const *argv[]){
	//calls the function
	Hello();
	return 0;
}
//This function builds a triangle using hello world and *'s
void Hello(){
	//hyp of triangle
	for (int i = 1; i < 12; ++i)
		std::cout << setw(i) << "*" << endl;
	//bottom of the triangle
	std::cout << "hello world" << "*"<< std::endl;
}