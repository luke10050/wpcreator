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

const string file = name + ".txt";

ofstream outputFile;
outputFile.open(file.c_str());
outputFile << "<background>" << endl; 
outputFile << "<starttime>" << endl;  
outputFile << "<year>2000</year>" << endl;    
outputFile << "<month>01</month>" << endl;    
outputFile << "<day>01</day>" << endl;    
outputFile << "<hour>00</hour>" << endl;    
outputFile << "<minute>01</minute>" << endl;   
outputFile << "<second>00</second>" << endl;   
outputFile << "</starttime>" << endl; 
outputFile << "<static>" << endl;
outputFile << "<duration>" << dur << "</duration>" << endl;
outputFile << "</static>" << endl;

//below sections must be repeated for each slide!

outputFile << "<static>" << endl;
outputFile << "<duration>" << dur << "</duration>: << endl;
outputFile << "<file>" << "x" << "</file>" << endl;
outputFile << "</static>"


outputFile << "<transition>" << endl; 
outputFile << "<duration>02</duration>" << endl;
outputFile << "<from></from>" << endl;
outputFile << "<to></to>" << endl;
outputFile << "</transition>" << endl;
outputFile << "</background>" << endl;
outputFile << file << endl;
outputFile.close();
cout << "Done!\n";

return 0;
}


