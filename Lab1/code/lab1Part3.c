#include "lab1.h"

void simpsonsAdaptiveIntegration(float aOrig, float bOrig, float eps, float minIntSize)
{
  float a, b, m;
  double sum=0;
  a = aOrig; b = bOrig;
  m = (aOrig + bOrig)/2;
  
  
  
 while (a != bOrig)
 {			
	 while (fabs(S(a,m)+S(m,b)-S(a,b))/15 >= eps && fabs(b-a) > minIntSize) 
	{
		b = m;
		m = (a + b)/2;
	}
				
	sum += S(a,b);
	a = b;
	b = bOrig;
	m = (a+b)/2;
 }
 
  printf("Result is: %f \n", (float)sum);

}
