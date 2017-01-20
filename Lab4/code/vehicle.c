#include "lab4.h"

struct Vehicle * initVehicle(int wheels, char * model, struct vInterface vInt)
{
	struct Vehicle * s = (struct Vehicle *)malloc(sizeof(struct Vehicle));
	s->numWheels = wheels;
	strcpy(s->model, model);
	s->vehInt = vInt;
	s->numPassengers = 0;
	s->currSpeed = 0;
	s->gear = 0;


	return s;


}

void cleanUpVehicle(struct Vehicle * v)
{
	free(v);
}

