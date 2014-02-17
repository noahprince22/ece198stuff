/*
 * @author Noah Prince, nprince2
 *University of Illinois at Urbana-Champaign
 */

#include <stdio.h>

/* Define constants */

int main()
{
	/*********************/
	/* Declare variables */
	/*********************/
	unsigned int a,b,c,d;/* counters for the input logic values */
	unsigned int result;

	/*************************************/
	/* Compute and print the truth table */
	/*************************************/
	printf("PROBLEM 2 PART B PART ii UNSIMPLIFIED \n");
	printf("  A  B  C  D| OUT \n");/* print truth table header */
	printf("------------|-----\n");

	//	((a+b) + a'b')(c'd' + cd) + (ac)'
	/* cycle through all input bit combinations */
	for ( a = 0; a <= 1; a = a + 1 )
		{
			for ( b = 0; b <= 1; b = b + 1 )
				{
					for ( c = 0; c <= 1; c = c + 1 )
						{
							for ( d = 0; d <= 1; d = d + 1 )
								{
									result = ( ( (a + b) + ( !(a) & !(b) ) ) & ( (!(c) & !(d))  + (c & d) ) )   + !(a & c);
									if( result > 0 )
										result = 1;
									printf("  %u  %u  %u %u |  %u  \n", a, b, c, d, result);
								}
						}
				}
		}
	printf("\n SIMPLIFIED VERSION \n");
	printf("  A  B  C  D| OUT \n");/* print truth table header */
	printf("------------|-----\n");

		/* cycle through all input bit combinations */
	for ( a = 0; a <= 1; a = a + 1 )
		{
			for ( b = 0; b <= 1; b = b + 1 )
				{
					for ( c = 0; c <= 1; c = c + 1 )
						{
							for ( d = 0; d <= 1; d = d + 1 )
								{
									result = !a+!c+((!b)&d);/* operation 2 */
									if( result > 0 )
										result = 1;
									
									printf("  %d  %d  %d %d |  %d  \n", a, b, c, d, result);
								}
						}
				}
		}

	return 0;
}
