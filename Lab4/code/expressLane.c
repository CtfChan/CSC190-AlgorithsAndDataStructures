#include "lab4.h"

struct ExpressLaneRec * initExpressLane(float enterTime, float exitTime)
{
  struct ExpressLaneRec *getfit = (struct ExpressLaneRec *)malloc(sizeof(struct ExpressLaneRec));
  getfit->enterTime = enterTime;
  getfit->exitTime = exitTime;
  getfit->car = NULL;
  getfit->nextRec = NULL;
  return getfit;
}

struct ExpressLaneRec * addCarRec(struct Car * c, float enterTime, float exitTime, struct ExpressLaneRec * eL)
{
  struct ExpressLaneRec *new =  initExpressLane(enterTime, exitTime);
  new->car = c;
  if (eL != NULL) {
    eL->nextRec = new;
  }
  return new;
}

void printRecords(struct ExpressLaneRec * eLCurr)
{

  struct ExpressLaneRec * node = eLCurr;
  
  while (node != NULL) {
    printf("Car enter time is %.6f \n", node->enterTime);
    printf("Car exit time is %.6f \n", node->exitTime);
    printf("Speed of the Car is: %d \n", node->car->veh->currSpeed);
    printf("Gear of the Car is set at: %d \n", node->car->veh->gear);
    printf("Passengers in the Car are: %d \n", node->car->veh->numPassengers);
    printf("Navigator in the Car: %d \n", node->car->hasNav);
    printf("\n");
    node = node->nextRec;
  }
  


}

void cleanUpRec(struct ExpressLaneRec * eL)
{


  


  if (eL->nextRec == NULL) {
    free(eL->car->veh);
    free(eL->car);
    free(eL);
    eL = NULL;
    return;
  }
  
  cleanUpRec(eL->nextRec);
  free(eL->car->veh);
  free(eL->car);
  free(eL);
  eL = NULL;




}

