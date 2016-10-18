#include <stdio.h>
#include <stdlib.h>
#include "2-1.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	List* list = List_Create();
	int i=0;
	int j=1;
	int k=2;
	List_Insert(list,&i,0);
	List_Insert(list,&j,1);
	List_Insert(list,&k,2);
	List_Clear(list);
	List_Destroy(list);
	return 0;
}
