#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
/* self referential struct
	struct ll_node {
		char* data;
		struct ll_node next;   incomplete type is not allowed next needs to be pointer since right now complier will have to set infinte space
	};*/

	/* self referential struct */
struct ll_node {
	char* data;
	struct ll_node* next; /* need a pointer! */
};
struct ll_node* prepend(char* data, struct ll_node* next) {
	struct ll_node* n = malloc(sizeof(struct ll_node));
	n->data = data;
	n->next = next;
	return n;
}
void free_llist(struct ll_node* head) {
	struct ll_node* p = head, * q;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
}
void main(){

	struct ll_node* head = 0;
	head = prepend("reverse.", head);
	head = prepend("in", head);
	head = prepend("display", head);
	head = prepend("will", head);
	head = prepend("These", head);
	struct ll_node* p;
	for (p = head; p; p = p->next) {
		printf("%s ", p->data);
	}
	printf("\n");
	free_llist(head); /*how do i know of free_llist freed everything*/
	/*very handy tool for detecting/debugging
	memory leaks: valgrind in gnu commandline 
	# valgrind --leak-check=full ./12c-dma
	==308== HEAP SUMMARY:
	==308== in use at exit: 80 bytes in 5 blocks
	==308== total heap usage: 6 allocs, 1 frees, 1,104 bytes allocated
	==308==
	==308== 80 (16 direct, 64 indirect) bytes in 1 blocks are definitely lost   ////// 16 direct is the space taken by head which is struct_llist////////
	==308== at 0x483B7F3: malloc
	==308== by 0x1091C6: prepend (12c-dma.c:20)
	==308== by 0x1092AF: main (12c-dma.c:42)
	==308==
	==308== LEAK SUMMARY:
	==308== definitely lost: 16 bytes in 1 blocks
	==308== indirectly lost: 64 bytes in 4 blocks*/


	/*ADDENDUM: typedef is only to look code prettier
		-unsigned lof int size;
		-void (*fn)(int) fn is pointer to a function that takes int argument 
		-struct llnode *lst 
		TYPEDEF lets us create alias for wordy type

		typedef oldtype newtype
		
		*/


	typedef int int_t;
	int i;
	int_t j;
	i = j = 10;

	/*declare "int_t" as an alias for "int *" */
	typedef int* intp_t;
	int i;
	intp_t p = &i;

	/*Common integer aliases (see stdint.h)
		used to store sizes and offsets   */
	typedef unsigned long int size_t;
	typedef long int			off_t;

}


