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
	unsigned int a,b;/* counters for the input logic values */
	unsigned int q1;
	unsigned int q2;

	/*************************************/
	/* Compute and print the truth table */
	/*************************************/
	printf("  A  B | Q1  Q2 \n");/* print truth table header */
	printf("-------|--------\n");

	/* cycle through all input bit combinations */
	for ( a = 0; a <= 1; a = a + 1 )
		{
			for ( b = 0; b <= 1; b = b + 1 )
				{
					q1 = !(a & b);/* compute desired logical operation */
					q2 = a | b;
					printf("  %d  %d |  %d  %d \n", a, b, q1, q2);
				}
		}

	return 0;
}
