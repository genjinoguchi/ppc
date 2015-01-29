#include <stdio.h>
#include <stdlib.h>
#include "lang.tab.h"
#include "node.h"

Node *interpret( Node * n )
{
	if(!n) return 0;

	switch ( n -> type ) {
		case typeStr:
		case typeStrVar: 
		case typeStrOpr: 
		case typeInt:
		case typeIntVar: 
		case typeIntOpr:
		case typeFloat:
		case typeFloatVar:
		case typeFloatOpr:
		case typeBool:
		case typeBoolVar: 
		case typeBoolOpr: 
		case typeIAry:
		case typeIAryVar: 
		case typeIAryOpr: 
		case typeSAry:
		case typeSAryVar: 
		case typeSAryOpr:
		default:
		break;
	}
}
