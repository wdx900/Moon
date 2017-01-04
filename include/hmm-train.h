#ifndef HMM_TRAIN_H
#define HMM_TRAIN_H	

#include <iostream>

using namespace std;

class HMMTrain {
public:
	HMMTrain(){};
	~HMMTrain(){};

public:
	bool read_file(string file);
	
private:
	long freq_m[4][4];
	long count_m[4];
};

#endif
