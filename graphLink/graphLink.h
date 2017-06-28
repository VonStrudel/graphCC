
typedef struct node
{
	long id;
	simpleNode *out;
	simpleNode *in;

	char* name;
}node

typedef struct link
{
	long id;
	int attributes;
	node* emitter;
	node* receiver;
}
typedef struct graph
{
	simpleNode *nodeList;
	simpleNode *linkList;
}

node* 	ghk_node_init(void);
node* 	ghk_node_initAt(char* name);

link* 	ghk_link_init(void);
link* 	ghk_link_initAt(int attribute);
void 	ghk_link_setAttribute(link* lnk, int attribute);
int	ghk_link_getAttribute(link* lnk);

graph* 	ghk_graph_init(void);
void	ghk_graph_addNode(node* nde);
void	ghk_graph_addLink(link* lnk);
void	ghk_graph_delNode(node* nde);
void	ghk_graph_delLink(link* lnk);

//------- Gestion du graph --------//

void ghk_bindNodes(graph* gph, node* emitter, node* receiver, int attribute);
void ghk_unbindNodes(graph* gph, node* emitter, node* receiver, int attribute);

void ghk_getLinkValue(node* emitter, node* receiver);

