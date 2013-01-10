#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string>
#include <vector>

using namespace std;

int main() {



	int x, c; /* c stands for countdown */
	x=0, c=2;
	string name, dir, dur;
	string filename [3/*make this an output from counting the number of jpegs */] = {/* make program add .jpg names here */"5", "6"};

	
	cout << "please enter a name for this slideshow: " << endl;
	cin >> name;
	cout << "please enter the directory the pictures are located in: " << endl;
	cin >> dir;
	cout << "please enter the slide duration: " << endl;
	cin >> dur;

//add in the contents read and table listing here!

DIR *opendir(const char *dir);




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
outputFile << "<transition>" << endl; 
outputFile << "<duration>02</duration>" << endl;
outputFile << "<from></from>" << endl;
outputFile << "<to>"<< filename[x+1] << "</to>" << endl;
outputFile << "</transition>" << endl;
if(c != 0)
{
outputFile << "<static>" << endl;
outputFile << "<duration>" << dur << "</duration>" << endl;
outputFile << "<file>" << filename[x] << "</file>" << endl;
outputFile << "</static>" << endl;


outputFile << "<transition>" << endl; 
outputFile << "<duration>02</duration>" << endl;
outputFile << "<from>" << filename[x-1] << "</from>" << endl;
outputFile << "<to>" << filename[x+1] << "</to>" << endl;
outputFile << "</transition>" << endl;

x=x+1;
c=c-1;
}
outputFile << "</background>" << endl;
outputFile.close();
cout << "Done!\n";

return 0;
}


