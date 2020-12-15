//main file for sort//
#include "sorting.h"
using namespace std;

int main(int argc, char** argv){
	if (argc == 2){
		string userfile = argv[1];
		cout << endl;
		cout << "Sorting " << userfile  << " file."<< endl;
		cout << "------------------------" << endl;
		cout << endl;

		sorting s(userfile);
		s.run(userfile);
	}
	else{
		cout << "ERROR: Valid file needs to be inputed in command line." << endl;
	}
	return 0;
}
