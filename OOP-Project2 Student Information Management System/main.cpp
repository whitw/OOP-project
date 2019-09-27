#include <iostream>
#include "SIMS.h"
using namespace std;


int main(int argc, char* argv[]) {
	SIMS sm = SIMS();
	while (sm.isrunning() == true) {
		sm.reset();
		sm.start();
	}
	return 0;
}
