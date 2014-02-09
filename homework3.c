//@author Noah Prince, nprince2

// Strategy: 7 (in binary) is 0x111. This program will check if the final three bits
// of a given integer are 111. If they are, it will increment the total number of 111
// bits. It then shifts the integer a bit to the rightm and checks that. It executes
// this pattern until it has checked the total number of bits in an integer.
#include <stdio.h>

int main(){
	int store;
	int total=0;
	scanf("%d", &store);

	//shift each bit, run a bitmask with 7 (0x111)
	for( int i = 0;i<sizeof(int);i++ ){
		//if the last 3 digits of store are 111, inc total
		if( (store & 7) == 7)
			total++;
		//shift store by one bit, check again
		store = store >> 1;
	}
	printf("%d",total);
};
