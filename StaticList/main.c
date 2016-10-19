#include <stdio.h>
#include <stdlib.h>
#include "StaticList.h" 

int main(int argc, char *argv[])
{
	StaticList* list = StaticList_Create(5);
	
	int index = 0;
	int i = 0;
	int j = 1;
	int k = 2;
	int x = 3;
	int y = 4;
	int z = 5;
	
	printf("Create: StaticList\n");
	StaticList_Insert(list, &i, 0);
	StaticList_Insert(list, &j, 0);
	StaticList_Insert(list, &k, 0);
	StaticList_Insert(list, &x, 5);
	StaticList_Insert(list, &y, 0);
	for(index=0; index<StaticList_Length(list); index++)
	{
		int* p = (int*)StaticList_Get(list, index);
		printf("%d\n", *p);
	}
	printf("Capacity: %d Length: %d\n\n",StaticList_Capacity(list),StaticList_Length(list));
	
	int* p = (int*)StaticList_Delete(list, 2);
	printf("Delete: %d Pos: 2\n", *p);
	for(index=0; index<StaticList_Length(list); index++)
	{
		int* p = (int*)StaticList_Get(list, index);
		printf("%d\n", *p);
	}
	printf("Capacity: %d Length: %d\n\n",StaticList_Capacity(list),StaticList_Length(list));
	
	StaticList_Insert(list, &z, 3);
	printf("Insert: %d Pos: 3\n", z);
	for(index=0; index<StaticList_Length(list); index++)
	{
		int* p = (int*)StaticList_Get(list, index);
		printf("%d\n", *p);
	}
	printf("Capacity: %d Length: %d\n\n",StaticList_Capacity(list),StaticList_Length(list));
	
	StaticList_Destroy(list);
	
	return 0;
}
