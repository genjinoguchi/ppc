typedef enum {
	typeStr,
	typeStrVar,
	typeStrOpr,
	typeInt,
	typeIntVar,
	typeIntOpr,
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
	char boolvalue,
	int intvalue,
	char * strvalue,
	int * iaryvalue[],
	char ** saryvalue[]
} ntypeConst;

typedef union {
	char * varname;
} ntypeVar;

typedef struct {
	int operator,
	int numops,
	struct nodeTag ** operands
} ntypeOper;

typedef struct nodeTag {
	nodeType type,
	
	union {
		ntypeConst const,
		ntypeVar var,
		ntypeOper oper
	}
} Node;
