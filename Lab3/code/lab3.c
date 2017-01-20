#include "lab3.h"

int testBits(int * a, int n, unsigned int regVar)
{
  int i, k;
  for (i = 0; i < n; i++) {
    k = regVar & (1 << a[i]);
    if (k != (1 << a[i])) {
	return 0;
    }
  }
  return 1;
}

void setBits(int * a, int n, unsigned int * regVar)
{
  int i, k;
  for (i = 0; i < n; i++) {
    k  =*regVar & (1 << a[i]);
    if (k != (1 << a[i])) {
      *regVar = *regVar + (1 << a[i]);
    }
  }




}

void clearBits(int * a, int n, unsigned int * regVar)
{
int i, k;
  for (i = 0; i < n; i++) {
    k =  ~(*regVar) & (1 << a[i]);
    if (k != (1 << a[i])) {
      *regVar = *regVar - (1 << a[i]);
     }
  }




}
