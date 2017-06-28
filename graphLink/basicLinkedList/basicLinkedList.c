#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "basicLinkedList.h"


simpleNode* sn_init(char* type)
{
	simpleNode *newNode =  malloc(sizeof(simpleNode));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->val = NULL;
	newNode->type = type;
	return newNode;
}

simpleNode* sn_initAt(void* val, char* type)
{
	simpleNode *newNode = sn_init(*type);
	newNode->val = val;
	return newNode;
}

simpleNode* sn_get(simpleNode* node, int i)
{
	simpleNode* actualNode = node;
	if(i > 0)
		while(actualNode->next != NULL)
		{
			actualNode = actualNode->next;
			i--;
			if(i==0)
				return actualNode;
		}
	else if(i<0)
		while(actualNode->prev != NULL)
		{
			actualNode = actualNode ->prev;
			i++;
			if(i==0)
				return actualNode;
		}
	return NULL;
}

int sn_addAt(simpleNode* node,simpleNode* toAdd, int i)
{
	node = sn_get(node, i);
	simpleNode* nodeNext = node->next;

	node->next = toAdd;
	toAdd->prev = node;

	if(nodeNext != NULL)
	{
		toAdd->next = nodeNext;
		nodeNext->prev = toAdd;
		return 0;
	}
	return 1;
}

int sn_rmvAt(simpleNode* node, int i)
{
	node = sn_get(node, i);
	simpleNode* nodeNext = node->next;
	simpleNode* nodePrev = node->prev;

	if(nodePrev != NULL)
	{
		nodePrev->next = nodeNext;
	}
	if(nodeNext != NULL)
	{
		nodeNext->prev = nodePrev;
	}
	return 0;
}
char* sn_getStr(simpleNode* node)
{
	if( node->type != NULL)
	{
		if(strcmp(node->type, "str"))
		{
			return (char*)(node->val);
		}
	}
	return NULL;
}
int sn_getInt(simpleNode* node)
{
	if(node->type != NULL)
	{
		if(strcmp(node->type, "int"))
		{
			return *(int*)(node->val);
		}
	}
}

float sn_getFloat(simpleNode* node)
{
	if(node->type != NULL)
	{
		if(strcmp(node->type, "flo"))
		{
			return *(float*)(node->val);
		}
	}
}

simpleNode* sn_getSimpleNode(simpleNode* node)
{
	if(node->type !=NULL)
	{
		if(strcmp(node->type,"sno"))
		{
			return (simpleNode*)(node->val);
		}
	}
	return NULL;
}

int sn_lengthAfter(simpleNode* node)
{
	int i = 0;
	while(node->next != NULL)
	{
		node = node->next;
		i++;
	}
	return i;
}
int sn_lengthBefore(simpleNode* node)
{
	int  i =0;
	while(node->prev != NULL)
	{
		node = node->prev;
		i++;
	}
	return i;
}

int sn_lengthTotal(simpleNode* node)
{
	int i = 0;
	while(node->prev != NULL)
	{
		node = node->prev;
		i++;
	}
	return i;
}
