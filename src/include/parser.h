#ifndef LUVA_PARSER_H
#define LUVA_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "arraylist.h"
#include "token.h"
#include "expression.h"
#include "statement.h"
#include "ast.h"

// ----------------------------------------------------------

typedef enum _ParserObjectType parser_object_t;
typedef struct _ParserObject ParserObject;

// ----------------------------------------------------------

enum _ParserObjectType {
    TYPE_TOKEN,
    TYPE_EXPRESSION,
    TYPE_STATEMENT
};

struct _ParserObject {
    parser_object_t type;
    union {
        Token *token;
        Expr *expr;
        Statement *statement;
    };
};

// ----------------------------------------------------------

AST *parser_create_ast(ArrayList *tokens);
Expr *parser_create_expr(ArrayList *list);
Expr *evaluate_parenthesis(ArrayList *list);

void parser_generate_assembly_from_expr(char *filename, Expr *expr);
void parser_generate_assembly_from_ast(char *filename, AST *ast);

#endif // LUVA_PARSER_H