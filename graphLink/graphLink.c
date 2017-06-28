#include <stdio.h>
#include <stdlib.h>

#include "graphLink.h"
#include "basicLinkedList/basicLinkedList.h"


node* ghk_node_init(void)
{
	static int nbNodes = 0;
	nbNodes ++;
	node* newNode = malloc(sizeof(node));
	newNode->id = nbNodes;
	newNode->out = sn_init("nod");
	newNode->in = sn_init("nod");
	newNode->name = NULL;
	return newNode;
}

node* ghk_node_initAt(char* name)
{
	node* newNode = ghk_node_init();
	newNode->name = name;
	return newNode;
}


link* ghk_link_init(void)
{
	static int nbLinks = 0;
	nbLinks ++;
	link* newLink = malloc(sizeof(link));
	newLink->id = nbLinks;
	newLink->attributes = 0;
	newLink->emitter = NULL;
	newLink->receiver = NULL;
	return newLink;
}

link* ghk_link_initAt(int attribute)
{
	link* newLink = ghk_link_init();
	newLink->attributes = attribute;
	return newLink;
}

void ghk_link_setAttribute(link* lnk, int attribute)
{
	lnk->attributes = attribute;
}
void ghk_link_getAttribute(link* lnk)
{
	return lnk->attributes;
}

graph* ghk_graph_init(void)
{
	graph* newGraph = malloc(sizeof(graph));
	newGraph->nodeList = sn_init("nod");
	newGraph->linkList = sn_init("lnk");
	return newGraph;
}


