#include <stdio.h>
#include <stdlib.h>
#include "lang.tab.h"
#include "node.h"

Node *interpret( Node * n )
{
	if(!n) return 0;

	switch ( n -> type ) {
		case typeStr: return n->const.strvalue;
		case typeStrVar: 
		case typeStrOpr: 
		case typeInt: return n->const.intvalue;
		case typeIntVar: 
		case typeIntOpr: 
		case typeBool: return n->const.boolvalue;
		case typeBoolVar: 
		case typeBoolOpr: 
		case typeIAry: return n->const.iaryvalue;
		case typeIAryVar: 
		case typeIAryOpr: 
		case typeSAry: return n->const.saryvalue;
		case typeSAryVar: 
		case typeSAryOpr: 
