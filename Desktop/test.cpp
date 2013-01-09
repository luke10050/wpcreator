#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <dirent.h>
using namespace std;

int main() {


	string name, dir, dur;

	
	cout << "please enter a name for this slideshow: " << std::endl;
	cin >> name;
	cout << "please enter the directory the pictures are located in: " << std::endl;
	cin >> dir;
	cout << "please enter the slide duration: " << std::endl;
	cin >> dur;

  ofstream outputFile;
outputFile.open("slideshow.txt");

outputFile << name << endl;
outputFile << dir << endl;
outputFile << dur << endl;
//the program outputs the variables entered to make sure they are correct

outputFile.close();
cout << "Done!\n";

return 0;
}


