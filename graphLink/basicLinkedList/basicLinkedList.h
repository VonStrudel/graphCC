
typedef struct simpleNode
{
	struct simpleNode *prev;
	struct simpleNode *next;
	void* val;
	char* type;
}simpleNode;

simpleNode* 	sn_init(char* type);
simpleNode* 	sn_initAt(void* val, char* type);
simpleNode* 	sn_get(simpleNode* node, int i);
int 		sn_addAt(simpleNode* node, simpleNode* toAdd, int i);
int		sn_rmvAt(simpleNode* node, int i);
int 		sn_lengthAfter(simpleNode* node);
int		sn_lengthBefore(simpleNode* node);
int		sn_lengthTotal(simpleNode* node);

char*		sn_getStr(simpleNode* node);
int		sn_getInt(simpleNode* node);
float		sn_getFloat(simpleNode* node);
simpleNode*	sn_getSimpleNode(simpleNode* node);


