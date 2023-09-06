#include<stdio.h>
#include<stdlib.h>
void main() {


	char* sarr[] = { "variable","length","string" };
	char* p = sarr[0];
	/*for (int i = 0; p[i] != 0; i++)
	{
		printf("%c", p[i]);
	}*/

	/*printing a string (painfully)*/
	char* str = "hello world!";   
	for (int i = 0; str[i] != 0; i++){
		printf("%c", str[i]);
	}

	/* or just */

	printf("%s", str);   /* BEWARE if you change terminating 0 then printf goes for foverver reading over next segment of memory*/


	/* Dyanamic Memory Allocation 
	   Dynamic vs static ( lifetime = forever)
				vs local (lifetime = LIFO aka stack)
	   C requries EXPLICIT memory manganement 
			- must request & free memory manually
			- if forget to free -> memory leak

		BASIC C "malloc" API (in stdlib.h):
			-malloc						- gives you space, return type address ( pointer)
			-realloc (context senstive) 
			-free						- takes a address to free ( pointer )

			malloc lib is TYPE AGNOSTIC, does not care with data types
			 - so we need a generic/ type-less pointer 
							(VOID *) void pointer 

			 void *malloc (size_t size);                    size_t is an integer
			 void *realloc ( void *ptr, size_t size);
			 void free (void *ptr);
			 
			 all size in bytes 
			 all ptrs are from previous malloc request
			
	*/


	int k = 1;  
	int* jagged_arr[5]; /*array of 5 pointers to int */

	for (int i = 0; i < 5; i++) {
		jagged_arr[i] = malloc(sizeof(int) * k);
		for (int j = 0; j < k; j++) {
			jagged_arr[i][j] = k;

		}
		k += 1;
	}

	printf("%d", *jagged_arr[4]);

	/* COMPOSITE DATA TYPES
	
		eqvi to objects in OOP
		c structs create user defined types, based on primitive or other user defined types
	
	*/

	struct point {
		int x;
		int y;
	};


	struct point pt;   /* point declaration ( & alloc!)*/

	struct point* pp;  /*pp stores address of struct pp*/

	/* Declaration and init in one go
	
	struct point {
		int x;
		int y;
	} pt, *pp ;
	
	*/

	pt.x = 10;
	pt.y = -5;

	struct point pt2 = { .x = 8, .y = 13 };

	pp = &pt;

	(*pp).x = 351; /*comp. access via pointer*/

	/* is (*PP).x = 351 same as *pp.x = 351)
			answer is NO
			because "." operator has higher precedence than "*"


			but (*pp).x is painful
			so we use the "->" operator 
				- component acess via pointer
	*/
	pp->x = 10;
	pp->y = -5;   /*use this format*/

	/* Dynamically allocating structs: */
	int N = 2;
	struct point* parr1 = malloc(N * sizeof(struct point));
	for (int i = 0; i < N; i++) {
		parr1[i].x = parr1[i].y = 0;
	}
	/* or, equivalently, with calloc (which zero-inits) */
	struct point* parr2 = calloc(N, sizeof(struct point));
	/* do stuff with parr1, parr2 ... */
	free(parr1);
	free(parr2);
}
