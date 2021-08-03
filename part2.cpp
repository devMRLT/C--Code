#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;
//encrypt & decrypt functions
string encrypt(string plainText, int shift, string file2);
string Decrypt(string plainText, int shift, string file2);

int main(int argc, char** argv){
	//file names will be given
	string file1 = argv[3], file2 = argv[4];
	int shift = atoi(argv[2]);
	string check = argv[1];
	//create streams for files
	ifstream f1(file1);
	if(check == "-e"){
		//inititate string
		string plainText;
		ofstream f2(file2);
		while(getline(f1,plainText)){
			//Call function to encrypt above filled string
			f2 << encrypt(plainText,shift, file2) << endl;
		}
		f2.close();
	}else if(check == "-d"){
		//inititate string to store
		string scatteredText;
		ofstream f2(file2);
		while(getline(f1,scatteredText)){
			f2 << Decrypt(scatteredText,shift, file2) << endl;
		}
		f2.close();
	}
	//close files once done
	f1.close();
	return 0;
}

//Encrypts
string encrypt(string plainText, int shift, string file2){
	//initiate temp string todo operations
	string output = "";
	//loop over and apply shift to encrypt
	for (int i = 0; i < plainText.length(); ++i){
		if (plainText[i] == 32) {
			output += plainText[i];
		} else if (plainText[i]+shift > 90) {
			output += char(int(plainText[i]+shift-65-26)%26+65);
		}else if(plainText[i]+shift == 64){
			output += plainText[i] + 25;
		} else if((plainText[i]+shift > 0) && (plainText[i]+shift < 31)){
			output += plainText[i];
		}else if((plainText[i]+shift > 34) && (plainText[i]+shift < 63)){
			output += plainText[i];
		}
		else {
			output += char(int(plainText[i]+shift-65)%26+65);
		}
	}
	return output;
}

//Decrypts
string Decrypt(string scatteredText, int shift, string file2){
	//initiate temp string todo operations
	string DecryptedOutput = "";
	//loop over and apply rev shift
	for (int i = 0; i < scatteredText.length(); ++i){
		if (scatteredText[i] == 32) {
			DecryptedOutput += scatteredText[i];
		} 
		else if (scatteredText[i]-shift < 65) {
			DecryptedOutput += char(int(scatteredText[i]-shift-65+26)%26+65);
		}
		else if(scatteredText[i]+shift == 64){
			DecryptedOutput += scatteredText[i]+25;
		}else if ((scatteredText[i]+shift >= 0) && (scatteredText[i]+shift < 31)) {
			DecryptedOutput += scatteredText[i];
		}else if ((scatteredText[i]+shift > 34) && (scatteredText[i]+shift < 63)) {
			DecryptedOutput += scatteredText[i];
		}
		 else {
			DecryptedOutput += char(int(scatteredText[i]-shift-65)%26+65);
		}
	}
	return DecryptedOutput;
}
