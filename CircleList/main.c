#include <stdio.h>
#include <stdlib.h>
#include "CircleList.h"
typedef struct _tag_Value
{
	CircleListNode header;
	int v;
}Value;
int main(int argc, char *argv[])
{
	int i = 0;
	int n = 0;
	int m = 0;
	
	printf("Please enter: n,m\n");
	scanf("%d,%d",&n,&m);
	
	Value* v = (Value*)malloc(sizeof(Value)*n);
	CircleList* list = CircleList_Create();
	
	
	for(i=0;i<n;i++)
	{
		v[i].v=i+1;
		CircleList_Insert(list, (CircleListNode*)&v[i], CircleList_Length(list));
	}
	
	for(i=0; i<CircleList_Length(list); i++)
	{
		Value* pv = (Value*)CircleList_Next(list);
		printf("%d\n", pv->v);
	}
	
	printf("\n");
	
	CircleList_Reset(list);
	
	while(CircleList_Length(list)>0)
	{
		Value* pv = NULL;
		for(i=1;i<m;i++)
		{
			CircleList_Next(list);
		}
		pv = (Value*)CircleList_Current(list);
		
		printf("%d\n", pv->v);
		
		CircleList_DeleteNode(list, (CircleListNode*)pv);	
	}
	
	CircleList_Destroy(list);
	return 0;
}
