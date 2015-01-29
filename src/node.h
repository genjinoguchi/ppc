typedef enum {
	typeStr,
	typeStrVar,
	typeStrOpr,
	typeInt,
	typeIntVar,
	typeIntOpr,
	typeFloat,
	typeFloatVar,
	typeFloatOpr,
	typeBool,
	typeBoolVar,
	typeBoolOpr,
	typeIAry,
	typeIAryVar,
	typeIAryOpr,
	typeSAry,
	typeSAryVar,
	typeSAryOpr
} nodeType;

typedef union {
	char boolvalue;
	int intvalue;
	float floatvalue;
	char * strvalue;
	int * iaryvalue;
	struct {	
		char ** saryvalue;
		int sarycount;
	};
} ntypeCon;

typedef union {
	char * varname;
} ntypeVar;

typedef struct {
	int returnToken;
	int operator;
	int numops;
	struct nodeTag ** operands;
} ntypeOper;

typedef struct nodeTag {
	nodeType type;
	
	union {
		ntypeCon con;
		ntypeVar var;
		ntypeOper oper;
	};
} Node;
