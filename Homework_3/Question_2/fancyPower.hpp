#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP
#include <math.h>

int fancyPower(int n, int m)
{
	//create a variable to store answer in
	int ans;
	//Check for even function -- check m for even
	if(m%2 == 0)
	{
		ans = pow((pow(n,2)),(m/2));
		return ans;
	}
	else if(m%2 == 1) // m is odd
	{
		ans = n * pow(pow(n,2), ((m-1)/2));
		return ans;
	}
	else if(m == 0)
	{
		return 1;
	}
	return 0;
}

#endif
