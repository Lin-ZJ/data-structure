#include <stdio.h>
#include <malloc.h>
#include "StaticList.h"

#define AVAILABLE -1

typedef struct _tag_StaticListNode
{
	unsigned int data;
	int next;
}TStaticListNode;

typedef struct _tag_StaticList
{
	int capacity;
	TStaticListNode header;
	TStaticListNode node[];
}TStaticList;

StaticList* StaticList_Create(int capacity)
{
	TStaticList* ret = NULL;
	int i = 0;
	
	if(capacity >=0 )
	{
		ret = (TStaticList*)malloc(sizeof(TStaticList) + sizeof(TStaticListNode) * (capacity+1));
	}
	if(ret != NULL)
	{
		ret->capacity = capacity;
		ret->header.data = 0;
		ret->header.next = 0;
		
		for(i=1; i<=capacity; i++)
		{
			ret->node[i].next = AVAILABLE;
		}
	}
	
	return ret; 
}

void StaticList_Destroy(StaticList* list)
{
	free(list);
}

void StaticList_Clear(StaticList* list)
{
	TStaticList* slist = (TStaticList*) list;
	int i = 0;
	
	if(slist != NULL)
	{
		slist->header.data = 0;
		slist->header.next = 0;
		for(i=1; i<=slist->capacity; i++)
		{
			slist->node[i].next = AVAILABLE;
		}
	}
}

int StaticList_Length(StaticList* list)
{
	TStaticList* slist = (TStaticList*) list;
	int ret = -1;
	
	if(slist != NULL)
	{
		ret = slist->header.data;
	}
	
	return ret;
}

int StaticList_Capacity(StaticList* list)
{
	TStaticList* slist = (TStaticList*) list;
	int ret = -1;
	
	if(slist != NULL)
	{
		ret = slist->capacity;
	}
	
	return ret;
}

int StaticList_Insert(StaticList* list, StaticListNode* node, int pos)
{
	TStaticList* slist = (TStaticList*) list;
	int ret = (slist != NULL);
	int current = 0;
	int index = 0;
	int i = 0;
	
	ret = ret && (slist->header.data + 1 <= slist->capacity);
	ret = ret && (pos >= 0) && (node != NULL);
	
	if(ret)
	{
		for(i=1; i<slist->capacity; i++)
		{
			if(slist->node[i].next == AVAILABLE)
			{
				index = i;
				break;
			}
		}
		slist->node[index].data = (unsigned int)node;
		slist->node[0]=slist->header;
		for(i=0; (i<pos) && (slist->node[current].next != 0); i++)
		{
			current = slist->node[current].next;
		}
		slist->node[index].next = slist->node[current].next;
		slist->node[current].next = index;
		slist->node[0].data++;
		slist->header = slist->node[0];
	} 
	
	return ret;
}

StaticListNode* StaticList_Get(StaticList* list, int pos)
{
	TStaticList* slist = (TStaticList*) list;
	StaticListNode* ret = NULL;
	int current = 0;
	int object = 0;
	int i=0;
	
	if((slist != NULL) && (0 <= pos) && (pos <= slist->header.data))
	{
		slist->node[0] = slist->header;
		for(i=0; i<pos; i++)
		{
			current = slist->node[current].next;
		}
		object = slist->node[current].next;
		ret = (StaticList*)slist->node[object].data;
	}
	
	return ret;
}

StaticListNode* StaticList_Delete(StaticList* list, int pos)
{
	TStaticList* slist = (TStaticList*) list;
	StaticListNode* ret = NULL;
	int current = 0;
	int object = 0;
	int i = 0;
	
	if((slist != NULL) && (0 <= pos) && (pos <= slist->header.data))
	{
		slist->node[0] = slist->header;
		for(i=0; i<pos; i++)
		{
			current = slist->node[current].next;
		}
		object = slist->node[current].next;
		ret = (StaticListNode*)slist->node[object].data;
		slist->node[current].next = slist->node[object].next;
		slist->node[0].data--;
		slist->header = slist->node[0];
		slist->node[object].next = AVAILABLE;
	}
	
	return ret;
}
