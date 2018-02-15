/*
 * CustomerService.h
 *
 *  Created on: Feb 10, 2018
 *      Authors: Rob Putyra, Christopher Runyan, Jonathan Daniel
 */

#ifndef CUSTOMERSERVICE_H_
#define CUSTOMERSERVICE_H_
#include <iostream>

using namespace std;

class CustomerService {
public:

	int arrivalTime;
	int serviceTime;

	int highestSize;
	int longestWait;

	int arrivalCounter;
	int departureCounter;

	CustomerService();
	void run(int x);
	void printArrivalMessage(int time);
	void printDepartureMessage(int time);
};

#endif /* CUSTOMERSERVICE_H_ */
