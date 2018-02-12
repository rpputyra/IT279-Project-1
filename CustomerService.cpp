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

}

void CustomerService::run() {
	//Initialize first customer and push into queue
	Customer cust;

	cust.arrivalTime = (1 + rand() % 5);
	cust.serviceTime = cust.arrivalTime;
	cust.endService =
			cust.serviceTime + (1 + rand() % 5);
	cust.id = counter;

//	cout << cust.arrivalTime << endl;
//	cout << cust.serviceTime << endl;
//	cout << cust.endService << endl;
//	cout << cust.id << endl;


//	serviceQueue.push(cust);

//	cout<< "Empty?: " << serviceQueue.empty() << endl;
//	cout<< "Size: " << serviceQueue.size() << endl;
//	cout << "----------" << endl;
//
//	cust.arrivalTime = (1 + rand() % 5);
//	cust.serviceTime = cust.arrivalTime;
//	cust.endService =
//	cust.serviceTime + (1 + rand() % 5);
//	cust.id = counter;
//
//	cout << "\nnew cust\n" <<endl;
//	cout << cust.arrivalTime << endl;
//	cout << cust.serviceTime << endl;
//	cout << cust.endService << endl;
//	cout << cust.id << endl;
//
//	cout <<"\nfront of queue\n" <<endl;
//	cout << serviceQueue.front().arrivalTime << endl;
//	cout << serviceQueue.front().serviceTime << endl;
//	cout << serviceQueue.front().endService << endl;

//	cout << endl;
//	Customer nextCustomer;
//
//	nextCustomer = serviceQueue.front();
//	serviceQueue.pop();
//
//	cout << nextCustomer.arrivalTime << endl;
//	cout << nextCustomer.serviceTime << endl;
//	cout << nextCustomer.endService << endl;
//	cout << nextCustomer.id << endl;
//	cout<< "Empty?: " << serviceQueue.empty() << endl;
//	cout<< "Size: " << serviceQueue.size() << endl;

	counter++;

	for(int i=0; i<60; i++) {
		if(i == cust.arrivalTime) {
			printArrivalMessage(cust, i);
			serviceQueue.push(cust);
			if(serviceQueue.size() == 1) {
				serviceQueue.front().serviceTime = (1 + rand() % 5);
				serviceQueue.front().endService = i + serviceQueue.front().serviceTime;
			}
			cust.arrivalTime = i + (1 + rand() % 5);
			cust.id = counter;
			counter++;
//			cout<< "New Customer ID: " << cust.id <<endl;
		}
		if(i == serviceQueue.front().endService) {
//			cout<< "	Next Customer ID: " << serviceQueue.front().id <<endl;
			printDepartureMessage(serviceQueue.front(), i);
			cout<<"   Service time: " << serviceQueue.front().serviceTime << endl;
			serviceQueue.pop();
			if(!serviceQueue.empty()) {
			serviceQueue.front().serviceTime = (1 + rand() % 5);
			serviceQueue.front().endService = i + serviceQueue.front().serviceTime;
//			cout<< "	Next Customer in Line ID: " << serviceQueue.front().id <<endl;
			}
		}
	}
	int i = 59;
	while(!serviceQueue.empty()) {

		if (serviceQueue.front().endService) {
//			cout<< "	Next Customer ID: " << serviceQueue.front().id <<endl;
			printDepartureMessage(serviceQueue.front(), i);
			cout<<"   Service time: " << serviceQueue.front().serviceTime << endl;
			serviceQueue.pop();
			if(!serviceQueue.empty()) {
			serviceQueue.front().serviceTime = (1 + rand() % 5);
			serviceQueue.front().endService = i + serviceQueue.front().serviceTime;
//			cout<< "	Next Customer in Line ID: " << serviceQueue.front().id <<endl;
			}
		}
		i++;
		cout<<"what is i: "<<i<<endl;
	}
}

void CustomerService::printArrivalMessage(Customer cust, int time) {
	cout << "Customer " << cust.id << " arrived at " << time << endl;
}

void CustomerService::printDepartureMessage(Customer cust, int time) {
	cout << "Customer " << cust.id << " left at " << time << endl;
}

CustomerService::~CustomerService() {
	// TODO Auto-generated destructor stub

}

int main() {
	srand(time(NULL));

	CustomerService *cs = new CustomerService();

	cs->run();

	return 0;
}
