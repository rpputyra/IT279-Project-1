/*
 * CustomerService.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: rpput
 */

#include "CustomerService.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <queue>

CustomerService::CustomerService() {
	// TODO Auto-generated constructor stub

	counter = 1;
	highestSize = 0;
	longestWait = 0;
}

void CustomerService::run(int x) {
	//Initialize first customer and push into queue


	cust.arrivalTime = (1 + rand() % x);
	cust.serviceTime = cust.arrivalTime;
	cust.endService = cust.serviceTime + (1 + rand() % x);
	cust.id = counter;

	counter++;

	for(int i=0; i<720; i++) {
		if(i == cust.arrivalTime) {
			printArrivalMessage(cust, i);
			serviceQueue.push(cust);
			if(serviceQueue.size() > highestSize) {
				highestSize = serviceQueue.size();
			}
			if(serviceQueue.size() == 1) {
				serviceQueue.front().serviceTime = (1 + rand() % x);
				serviceQueue.front().endService = i + serviceQueue.front().serviceTime;
			}
			cust.arrivalTime = i + (1 + rand() % x);
			cust.id = counter;
			counter++;
		}
		if(i == serviceQueue.front().endService) {
			printDepartureMessage(serviceQueue.front(), i);
			int wait;
			wait = serviceQueue.front().endService - serviceQueue.front().arrivalTime;
			if(wait > longestWait) {
				longestWait = wait;
			}
			serviceQueue.pop();
			if(!serviceQueue.empty()) {
			serviceQueue.front().serviceTime = (1 + rand() % x);
			serviceQueue.front().endService = i + serviceQueue.front().serviceTime;
			}
		}
	}
	int i = 720;
	while(!serviceQueue.empty()) {

		if (serviceQueue.front().endService) {
			printDepartureMessage(serviceQueue.front(), i);
			serviceQueue.pop();
			if(!serviceQueue.empty()) {
			serviceQueue.front().serviceTime = (1 + rand() % x);
			serviceQueue.front().endService = i + serviceQueue.front().serviceTime;
			}
		}
		i++;
	}
	cout<<"\nLongest Line of Customers: "<<highestSize<<" customers."<<endl;
	cout<<"\nLongest Wait: "<<longestWait<<" seconds."<<endl;
}

void CustomerService::printArrivalMessage(Customer cust, int time) {
	int minutes = time%60;
	int hour = time/60;
	if(minutes == 0) {
			cout << "Customer " << cust.id << " left at    " << hour << ":" << "00" << endl;
			}
	else if(minutes%10 == 0) {
		cout << "Customer " << cust.id << " arrived at " << hour << ":" << minutes << endl;
	}
	else if(minutes<10) {
		cout << "Customer " << cust.id << " arrived at " << hour << ":" << "0" << minutes << endl;
	}
	else {
		cout << "Customer " << cust.id << " arrived at " << hour << ":" << minutes << endl;
	}
}

void CustomerService::printDepartureMessage(Customer cust, int time) {
	int minutes = time%60;
	int hour = time/60;
	if(minutes == 0) {
		cout << "Customer " << cust.id << " left at    " << hour << ":" << "00" << endl;
	}
	else if(minutes%10 == 0) {
		cout << "Customer " << cust.id << " left at    " << hour << ":" << minutes << endl;
	}
	else if(minutes<10) {
		cout << "Customer " << cust.id << " left at    " << hour << ":" << "0" << minutes << endl;
	}

	else {
		cout << "Customer " << cust.id << " left at    " << hour << ":" << minutes << endl;
	}
}

CustomerService::~CustomerService() {
	// TODO Auto-generated destructor stub

}

int main() {
	srand(time(NULL));

	CustomerService *cs = new CustomerService();

	int n;
	cout<<"Enter a value for x for a range of time from 1 to x seconds: "<<endl;
	cin>>n;
	cs->run(n);

	return 0;
}
