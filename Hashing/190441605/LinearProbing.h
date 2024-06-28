#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "BaseClass.h"
#include <iostream>
#include <vector>

class LinearProbing : public BaseClass {
public:
	LinearProbing();
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int databaseSize() override;
    int hash(std::string id) override;
    
private:
int size2;
int m2;
std::vector<int> power;
std::vector<int> p2;
int min_idx;


 void M(std::vector<int>& v, int start, int middle, int end) {
	
	std::vector<int> temp;

	int i, j;
	i = start;
	j = middle + 1;

	while (i <= middle && j <= end) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= middle) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= end) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = start; i <= end; ++i)
		v[i] = temp[i - start];

}

void MS(std::vector<int>& v, int start, int end) {
	if (start < end ) {
		int middle = (start + end) / 2;
		MS(v, start, middle);
		MS(v, middle + 1, end);
		M(v, start, middle, end);
	}
}


 



    // Other data members and functions specific to Linear Probing
};

#endif // LINEARPROBING_H
