#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int main() {



	int x, c, z, t; /* c stands for countdown */
	x=0, c=10, z=0, t=5;
	string name, dir, dur;
	char * tab;
	
	cout << "please enter a name for this slideshow: " << endl;
	cin >> name;
	cout << "please enter the directory the pictures are located in: " << endl;
	cin >> dir;
	cout << "please enter the slide duration: " << endl;
	cin >> dur;
string filename [20/*make this an output from counting the number of jpegs */];
//add in the contents read and table listing here!
string result;
       DIR *dp;
       struct dirent *ep;
 	dp = opendir ("./");
       if (dp != NULL)
         {
           while (ep = readdir (dp)){
             cout << (ep->d_name) << endl;
		strcpy((ep->d_name), tab);
		z=z+1;
		}
           (void) closedir (dp);
         }
       else
         perror ("Couldn't open the directory");



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
while(c != 0)
{
outputFile << "<static>" << endl;
outputFile << "<duration>" << dur << "</duration>" << endl;
outputFile << "<file>" << filename[x] << "</file>" << endl;
outputFile << "</static>" << endl;


outputFile << "<transition>" << endl; 
outputFile << "<duration>02</duration>" << endl;
outputFile << "<from>" << filename[x] << "</from>" << endl;
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


