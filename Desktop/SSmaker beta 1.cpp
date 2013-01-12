#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string>
#include <vector>

using namespace std;

int main() {
	char *p;
	int x, c, t, z; /* c stands for countdown */
	x=2, c=1, z=0, t=2;
	string name, dir, dur, un;
	vector<string> filename;
	string command;
	cout << "please enter a name for this slideshow: " << endl;
	cin >> name;
	cout << "please enter the directory the pictures are located in: " << endl;
	cin >> dir;
	cout << "please enter the slide duration in seconds: " << endl;
	cin >> dur;
	cout << "enter the number of files in the directory" << endl;
	cin >> c;
	cout << "please enter your Username" << endl;
	cin >> un;

       DIR *dp;
       struct dirent *ep;
 	dp = opendir (dir.c_str());
       if (dp != NULL)
         {
           while (ep = readdir (dp)){
		command = dir;
		command.append(ep->d_name);
		filename.insert (filename.begin() + z, command);
		command.clear();
		z=z+1;
		}
           (void) closedir (dp);
         }
       else{
        perror ("Couldn't open the directory");
	return 0;
	}

cout << "now creating required files and directories, for more information see man ***" << endl;
system("mkdir ~/SSmaker/");
system("mkdir ~/SSmaker/Slideshows/");
system("ln -s ~/SSmaker/Slideshows/ /usr/share/backgrounds/");

const string file = "/home/" + un + "/SSmaker/Slideshows/" + name + ".xml";
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
outputFile << "<static>" << endl;
outputFile << "<duration>" << dur << "</duration>" << endl;
outputFile << "<file>" << filename[x] << "</file>" << endl;
outputFile << "</static>" << endl;
outputFile << "<transition>" << endl; 
outputFile << "<duration>02</duration>" << endl;
outputFile << "<from>" << filename[x] << "</from>" << endl;
outputFile << "<to>" << filename[t] << "</to>" << endl;
outputFile << "</transition>" << endl;
outputFile << "</background>" << endl;
outputFile.close();
cout << "Done!\n";
return 0;
}
