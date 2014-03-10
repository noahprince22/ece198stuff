/*******************************************************************/
/*	multiply.c                                                 */
/*	Douglas L. Jones                                           */
/*	University of Illinois at Urbana-Champaign                 */
/*	October 7, 2012                                            */
/*                                                                 */
/*	(c) 2012 by Douglas L. Jones                               */
/*	This work is made available according to                   */
/*	the Creative Commons "Attribution" license                 */
/*	http://creativecommons.org/licenses/by/3.0/                */
/*                                                                 */
/*  multiply.c: multiplies two 16-bit unsigned integers            */
/*      via shift-and-add approach                                 */
/*                                                                 */
/*  Developer notes:                                               */
/*	The idea is that e.g. a four-decimal-digit number          */
/*      d3 d2 d1 d0 = 10*(10*(10*d3 + d2) + d1) + d0               */
/*                                                                 */
/*      #define TEST_FLAG 1  to see internal values for debugging  */
/*                                                                 */
/*      Need to add explicit checks on the input value range       */
/*      and trap unsupported values!                               */
/*                                                                 */
/*  User notes:                                                    */
/*                  @author Noah Prince, nprince2                  */
/*                                                                 */
/*******************************************************************/
#include <stdio.h>

/*********************/
/* Declare constants */
/*********************/
#define TEST_FLAG 1	/* 1 to turn on test operations; 0 to turn off */
#define WORD_LENGTH 16	/* maximum allowable number of bits in input integers */

int main()
{
   /*********************/
   /* Declare variables */
   /*********************/
   int  bit_mask;	/* bit mask for selecting a single bit to test for 1 or 0 */
   int  number1;	/* first number to multiply */
   int  number2;	/* second number to multiply */
   int  product;	/* holds the accumulating product */

   int  ii;		/* for-loop counter value */
   int  temp;		/* temporary integer value */


   /*******************************/
   /* Read in numbers to multiply */
   /*******************************/
   printf("Enter first nonnegative integer to multiply  ");
   scanf("%d", &number1);

   printf("Enter second nonnegative integer to multiply  ");
   scanf("%d", &number2);

   /************************************************/
   /* Compute product by shift-and-conditional-add */
   /************************************************/
   product = 0;
   bit_mask = 1;
   temp = number2;
   for ( ii = 0; ii < number2; ii = ii + 1 )
   {
      if ( (bit_mask & number1) > 0 )
      {
         product = product + temp;
      }
      if ( TEST_FLAG == 1 ) { printf("TEST: product is %d; temp is %d; bit_mask is %d\n", product, temp, bit_mask); }
      temp = temp << 1;	/* no multiples allowed! */
      bit_mask = bit_mask << 1;
   }
   printf("The product of %d and %d is %d\n", number1, number2, product);
   if ( TEST_FLAG == 1 ) { printf("TEST: The product is %d\n", number1*number2); }

   return 0;
}

