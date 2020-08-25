#include <stdio.h>
#include <limits.h>
#include <float.h>

int main () {
	int var1 = INT_MAX;
	float var2 = FLT_MAX;
	double var3 = DBL_MAX;
	
	printf ("%lu, %i\n", sizeof(var1), var1);
	printf ("%lu, %f\n", sizeof(var2), var2);
	printf ("%lu, %lf\n", sizeof(var3), var3);

return 0;
}
