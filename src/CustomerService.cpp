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


//CustomerService Constructor
CustomerService::CustomerService() {
	highestSize = 0;
	longestWait = 0;

	arrivalCounter = 1;
	departureCounter = 1;
}

//Runs the loops for CustomerService
void CustomerService::run(int x) {
	//Initialize first customer and push into queue

	arrivalTime = (1 + rand() % x);
	serviceTime = arrivalTime;
	//Runs initial loop for CustomerService for 720 minutes.
	for(int i=0; i<720; i++) {
		/* When i matches each new customer's schedule arrival time,
		 * push the customer into the queue.
		 */
		if(i == arrivalTime) {
			printArrivalMessage(i);
			serviceQueue.push(arrivalTime);
			//hey
			if(serviceQueue.size() > highestSize) {
				highestSize = serviceQueue.size();
			}
			if(serviceQueue.size() == 1) {
				serviceTime = i + (1 + rand() % x);
			}
			arrivalTime = i + (1 + rand() % x);
		}
		/* When i matches the service time, pop the queue
		 * and recalculate the service time for the next customer
		 */
		if(i == serviceTime) {
			printDepartureMessage(i);
			serviceQueue.pop();
			if(!serviceQueue.empty()) {
				int wait = i - serviceQueue.front();
					if(wait > longestWait) {
						longestWait = wait;
					}
				serviceTime = i + (1 + rand() % x);
			}
		}
	}
	//Flush the rest of the customers out of the store.
	int i = 720;
	while(!serviceQueue.empty()) {

		if(i == serviceTime) {
			printDepartureMessage(i);
			serviceQueue.pop();
			if(!serviceQueue.empty()) {
				int wait = i - serviceQueue.front();
				if(wait > longestWait) {
					longestWait = wait;
				}
				serviceTime = i + (1 + rand() % x);
			}
		}
		i++;
	}
	//Print the stats of the simulation
	cout<<"\nLongest Line of Customers: "<<highestSize<<" customers."<<endl;
	cout<<"\nLongest Wait: "<<longestWait<<" seconds."<<endl;
}

//Print the arrival message for each customer
void CustomerService::printArrivalMessage(int time) {
	int minutes = time%60;
	int hour = time/60;
	if(minutes == 0) {
		cout << "Customer " << arrivalCounter << " left at    " << hour << ":" << "00" << endl;
		}
	else if(minutes%10 == 0) {
		cout << "Customer " << arrivalCounter << " arrived at " << hour << ":" << minutes << endl;
	}
	else if(minutes<10) {
		cout << "Customer " << arrivalCounter << " arrived at " << hour << ":" << "0" << minutes << endl;
	}
	else {
		cout << "Customer " << arrivalCounter << " arrived at " << hour << ":" << minutes << endl;
	}

	arrivalCounter++;
}

//Print the arrival message of each customer
void CustomerService::printDepartureMessage(int time) {
	int minutes = time%60;
	int hour = time/60;
	if(minutes == 0) {
		cout << "Customer " << departureCounter << " left at    " << hour << ":" << "00" << endl;
	}
	else if(minutes%10 == 0) {
		cout << "Customer " << departureCounter<< " left at    " << hour << ":" << minutes << endl;
	}
	else if(minutes<10) {
		cout << "Customer " << departureCounter << " left at    " << hour << ":" << "0" << minutes << endl;
	}

	else {
		cout << "Customer " << departureCounter << " left at    " << hour << ":" << minutes << endl;
	}
	departureCounter++;
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
