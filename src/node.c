#include "node.h"

Node *nodify_oper( int tokenType, int operator, int numops, ... )
{
    va_list marker;
    Node *node;
    int i;

    if(( node = (Node *)malloc(sizeof(Node))) == NULL ){
        print_error("Ran out of memory");
    }
    if(( node->oper.operands = (Node **)malloc(numops * sizeof(Node *))) == NULL) {
        print_error("Ran out of memory");
    }

    switch( tokenType ){
        case BOOLEAN:
            node->type=typeBoolOpr;
            break;
        case STRING:
            node->type=typeStrOpr;
            break;
        case INTEGER:
            node->type=typeIntOpr;
            break;
        case FLOAT:
            node->type=typeFloatOpr;
            break;
        case STRING_ARRAY:
            node->type=typeSAryOpr;
            break;
        case INT_ARRAY:
            node->type=typeIAryOpr;
            break;
    }
    node->oper.returnToken = tokenType;
    node->oper.operator = operator;
    node->oper.numops = numops;
    va_start(marker, numops);
    for( i=0; i<numops; i++ ){
        node->oper.operands[i] = va_arg(marker, Node *);
    }
    va_end(marker);

    return node;
}

Node *nodify_var( int tokenType, char * varname )
{
    int i;
    Node * node;

    if(( node = (Node *)malloc(sizeof(Node))) == NULL ){
        print_error("Ran out of memory");
    }

    switch( tokenType ){
        case BOOLEAN:
            node->type=typeBoolVar;
            break;
        case STRING:
            node->type=typeStrVar;
            break;
        case INTEGER:
            node->type=typeIntVar;
            break;
        case FLOAT:
            node->type=typeFloatVar;
            break;
        case STRING_ARRAY:
            node->type=typeSAryVar;
            break;
        case INT_ARRAY:
            node->type=typeIAryVar;
            break;
    }
    node->var.varname=varname;

    return node;
}

Node *nodify_bool( char con )
{
    Node *node;

    /* Node memory allocation */
    if(( node = (Node *)malloc(sizeof(Node))) == NULL ){
        print_error("Ran out of memory");
    }

    node->type=typeBool;
    node->con.boolvalue = con;

    return node;
}

Node *nodify_str( char *con )
{
    Node *node;

    /* Node memory allocation */
    if(( node = (Node *)malloc(sizeof(Node))) == NULL ){
        print_error("Ran out of memory");
    }

    node->type=typeStr;
    node->con.strvalue = con;

    return node;
}

Node *nodify_int( int con )
{
    Node *node;

    /* Node memory allocation */
    if(( node = (Node *)malloc(sizeof(Node))) == NULL ){
        print_error("Ran out of memory");
    }

    node->type=typeInt;
    node->con.intvalue = con;

    return node;
}

Node *nodify_float( float con )
{
    Node *node;

    /* Node memory allocation */
    if(( node = (Node *)malloc(sizeof(Node))) == NULL ){
        print_error("Ran out of memory");
    }

    node->type=typeFloat;
    node->con.floatvalue = con;

    return node;
}

Node *nodify_strary( char ** con, int count )
{
    Node *node;

    /* Node memory allocation */
    if(( node = (Node *)malloc(sizeof(Node))) == NULL ){
        print_error("Ran out of memory");
    }

    /* String memory allocation */


    node->type=typeSAry;
    node->con.saryvalue = con;

    return node;
}

Node *nodify_intary( int * con )
{
    Node *node;

    /* Node memory allocation */
    if(( node = (Node *)malloc(sizeof(Node))) == NULL ){
        print_error("Ran out of memory");
    }

    node->type=typeIAry;
    node->con.iaryvalue = con;

    return node;
}

void free_node( Node * node)
{
    int i;
    linked_list *res;

    if( !node ) return;
    switch( node->type ) {
        case typeStr:
            free(node->con.strvalue);
            break;
        case typeStrVar:
            res = lookup(sym, node->var.varname);
/**/        free(res->s);
            free(node->var.varname);
            break;
        case typeStrOpr:
            /*
             * To address:
             * How would I be able to free the outcome of the string_opr?
             */
            for( i=0; i<node->oper.numops; i++ ){
                free_node(node->oper.operands[i]);
            }
            free(node->oper.operands);
        case typeInt:
            break;
        case typeIntVar:
            free(node->var.varname);
            break;
        case typeIntOpr:
            for( i=0; i<node->oper.numops; i++ ){
                free_node(node->oper.operands[i]);
            }
            free(node->oper.operands);
            break;
        case typeFloat:
            break;
        case typeFloatVar:
            free(node->var.varname);
            break;
        case typeFloatOpr:
            for( i=0; i<node->oper.numops; i++ ){
                free_node(node->oper.operands[i]);
            }
            free(node->oper.operands);
            break;
        case typeBool:
            break;
        case typeBoolVar:
            free(node->var.varname);
            break;
        case typeBoolOpr:
            for( i=0; i<node->oper.numops; i++ ){
                free_node(node->oper.operands[i]);
            }
            free(node->oper.operands);
            break;
        case typeIAry:
            free(node->con.iaryvalue);
            break;
        case typeIAryVar:
            /*
             * Lookup in the sym hash table?
             * Not sure if setting arrays to variables is done yet.
             */
            free(node->var.varname);
        case typeIAryOpr:
        case typeSAry:
            i = 0;
            while (node->con.saryvalue[i]) {
                free(node->con.saryvalue[i]);
                ++i;
            }
            free(node->con.saryvalue[i]);
            free(node->con.saryvalue);
        case typeSAryVar:
            /*
             * Lookup in the sym hash table?
             * Not sure if setting arrays to variables is done yet.
             */
             free(node->var.varname);
        case typeSAryOpr:
            for( i=0; i<node->oper.numops; i++ ){
                free(node->oper.operands[i]);
            }
            free(node->oper.operands);
    }
}

// vim: ts=4:et:sts:sw=4:sr
