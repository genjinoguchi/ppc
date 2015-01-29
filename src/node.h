#pragma once
#include <stdarg.h>
#include "hash.h"
#include "lang.tab.h"
extern hash_table *sym;

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
    char ** saryvalue;
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

Node *nodify_oper(int tokenType, int operator, int numops, ...);
Node *nodify_var(int tokenType, char * varname);
Node *nodify_bool(char con);
Node *nodify_str(char *con);
Node *nodify_int(int con);
Node *nodify_float(float con);
Node *nodify_strary(char **con, int count);
Node *nodify_intary(int *con);
Node *interpret(Node *n);
void free_node(Node *);

// vim: ts=4:et:sts:sw=4:sr
