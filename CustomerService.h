/*
 * CustomerService.h
 *
 *  Created on: Feb 10, 2018
 *      Author: rpput
 */

#ifndef CUSTOMERSERVICE_H_
#define CUSTOMERSERVICE_H_
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

struct Customer {
	int serviceTime, endService, arrivalTime, id;
};

class CustomerService {
public:
	int firstArrival;
	int counter;
	queue <Customer> serviceQueue;

	CustomerService();
	void run();
	void printArrivalMessage(Customer cust, int time);
	void printDepartureMessage(Customer cust, int time);
	virtual ~CustomerService();
};

#endif /* CUSTOMERSERVICE_H_ */
