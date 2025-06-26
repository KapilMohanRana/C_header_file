#include<stdio.h>
#include<math.h>

typedef double (*funcFunc)(double);

double binary_search(double start,double end,double target,double epsilom, funcFunc func){
    double mid;
    while(end - start > epsilom) {
	mid = start + (end - start)/2.0;
	double fmid = func(mid);
	if(fabs(fmid - target) < epsilom) {
	    return mid;
	}	
	else if(fmid < target) {
	    start = mid;
	}
	else {
	    end = mid;
	}	
    }
    return (end+start)/2.0;
}
