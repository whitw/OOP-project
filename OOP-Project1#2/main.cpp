#include <iostream>
#include "SIMS.h"
#include "student.h"
using namespace std;


int main(int argc, char* argv[]) {
	string fileName = "file1.txt"; //default filename.
	if (argc >= 2) {
		fileName = string(argv[1]);
		//file existence will be checked by StudentDB.
		//file validitiy will be checked by Student.
	}
	//else(=>no argv): filename will automatically become "file1.txt"
	SIMS sm = SIMS(fileName);
	while (sm.isrunning() == true) {
		sm.start();
	}
	return 0;
}
