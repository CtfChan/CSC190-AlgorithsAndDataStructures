#include "assignment2.h"

double calcAverageWaitingTime(struct Simulation * S)
{
	double sumOfDiff  = 0;
	double denominator = 0;
	while ((S->eventQueue).currSize != 0) {
		sumOfDiff += -1 * (((S->eventQueue).front)->data.arrivalTime - ((S->eventQueue).front)->data.departureTime);
		denominator ++;
		dequeue(&(S->eventQueue));
	}
	return sumOfDiff / denominator;


}

struct Simulation initSimulation(double arrivalRate, double serviceTime, double simTime)
{
	struct Simulation s1;
	s1.currTime = 0;	
	s1.arrivalRate = arrivalRate;
	s1.serviceTime = serviceTime;
	
	s1.timeForNextArrival = getRandTime(arrivalRate);
	s1.timeForNextDeparture = serviceTime + (s1.timeForNextArrival); 
	s1.totalSimTime = serviceTime;
	
	s1.buffer = initQueue();
	s1.eventQueue = initQueue();
	s1.e = ARRIVAL;

	return s1;

}

double runSimulation(double arrivalRate, double serviceTime, double simTime)
{
	struct Simulation sim =  initSimulation(arrivalRate, serviceTime, simTime);
	
	while (simTime > sim.currTime) {
		if (sim.buffer.currSize == 0) {
			sim.timeForNextDeparture = sim.timeForNextArrival + serviceTime;	
			sim.e = ARRIVAL;
		}
		if (sim.e == ARRIVAL) {
			
			struct Data d;
			d.arrivalTime = sim.timeForNextArrival;
			d.departureTime = 0;
			enqueue(&(sim.buffer), d);
			
			sim.timeForNextArrival = sim.timeForNextArrival + getRandTime(arrivalRate);

			if (sim.timeForNextArrival > sim.timeForNextDeparture) {
				sim.currTime = sim.timeForNextDeparture;
				sim.e = DEPARTURE;			
			}
			else { // sim.timeForNextArrival < sim.timeForNextDeparture
				((sim.buffer.rear)->data).departureTime = sim.timeForNextDeparture;
				sim.currTime = sim.timeForNextArrival;
				sim.e = ARRIVAL;
			} 
		}
		else if (sim.e == DEPARTURE) {
			((sim.buffer.front)->data).departureTime = sim.currTime;
			
			enqueue(&(sim.eventQueue), (sim.buffer.front)->data);
			dequeue(&(sim.buffer));
			
/*			// to delete
			printf("Arrival: %lf", (sim.eventQueue.rear)->data.arrivalTime);
			printf("\n");
			printf("Departure: %lf", (sim.eventQueue.rear)->data.departureTime);
			printf("\n");

*/


			sim.timeForNextDeparture = sim.timeForNextDeparture + serviceTime;
			
			if (sim.timeForNextArrival > sim.timeForNextDeparture) {
				sim.currTime = sim.timeForNextDeparture;
				sim.e = DEPARTURE;
			}
			else {	//sim.timeForNextArrival < sim.timeForNextDeparture
				sim.currTime = sim.timeForNextArrival;
				sim.e = ARRIVAL;
			}

		}

	}
	
	double ans = calcAverageWaitingTime(&(sim));
	freeQueue(&(sim.buffer));
	freeQueue(&(sim.eventQueue));
	return ans;	


}
