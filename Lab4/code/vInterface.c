#include "lab4.h"

struct vInterface initVInterface(int (*sS)(int), int (*sG)(int), int (*sP)(int))
{
  struct vInterface new;
  new.setSpeed = (sS);
  new.setGear = (sG);
  new.setPassengers = (sP);
  return new;
}
