#include <stdlib.h>
#include "lang.tab.h"
#include "node.h"
#include "hash.h"

extern hash_table *sym;

Node *interpret(Node * n);
Node *interpret_int(Node * n);

Node *interpret(Node * n) {
    if(!n) return 0;

    switch ( n -> type ) {
        case typeStr:
            break;
        case typeStrVar: 
            break;
        case typeStrOpr: 
            break;
        case typeInt:
            return interpret_int(n);
        case typeIntVar: 
            return interpret_int(n);
        case typeIntOpr:
            return interpret_int(n);
        case typeFloat:
            break;
        case typeFloatVar:
            break;
        case typeFloatOpr:
            break;
        case typeBool:
            break;
        case typeBoolVar: 
            break;
        case typeBoolOpr: 
            break;
        case typeIAry:
            break;
        case typeIAryVar: 
            break;
        case typeIAryOpr: 
            break;
        case typeSAry:
            break;
        case typeSAryVar: 
            break;
        case typeSAryOpr:
            break;
        default:
            break;
    }
}

Node *interpret_int(Node * n) {
    Node *ret;
    switch (n->type) {
        case typeInt:
            ret->type = typeInt;
            ret->con.intvalue = n->con.intvalue;
            return ret;
        case typeIntVar:
            ret->type = typeInt;
            linked_list *res = lookup(sym, n->var.varname);
            ret->con.intvalue = res->i;
            return ret;
        case typeIntOpr:
            switch (n->oper.operator) {
                case '+':
                    switch (n->oper.operands[0]->type) {
                        case typeInt:
                            switch (n->oper.operands[1]->type) {
                                case typeInt:
                                    ret->type = typeInt;
                                    ret->con.intvalue = n->oper.operands[0]->con.intvalue + n->oper.operands[1]->con.intvalue;
                                    return ret;
                            }
                    }
            }
            
    }
}

// vim: ts=4:et:sts:sw=4:sr
