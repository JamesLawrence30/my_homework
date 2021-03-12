/*
	Author: James Lawrence
	Cite: N/A
*/

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main() {

	// Open file given filename
	ifstream f ("DovKruger.calendar");


 	// Variable placeholders
 	string lineBuf;
 	string col1, col2, col3;

 	// Read in the desired lines
	while(getline(f, lineBuf)) {
		
		istringstream line(lineBuf);
		line >> col1 >> col2 >> col3;;

		if(lineBuf[0] == '#') {
			continue; // skip lines beginning in #
		}
		else if(lineBuf == "") {
			break; // stop at first blank line
		}
		else {
			cout << col1 << '\t' << col2 << '\t' << col3 << endl;

		}
	}
}
