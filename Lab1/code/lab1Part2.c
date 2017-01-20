#include "lab1.h"

float S(float a, float b)
{
  float mid = (b+a)/2;
  float integral = ((b-a)/6)*(f(a)+(4* f(mid))+f(b));
  return integral;
}
