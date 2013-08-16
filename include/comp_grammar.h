#ifndef COMP_GRAMMAR_H
#define COMP_GRAMMAR_H

#include "comp_dict.h"

comp_dict_t *symbol_table;

/**
 * Symbol type enum
 */
typedef enum {
    T, NT, ND //! T -> Terminal; NT -> Not Terminal; ND -> Not Defined
} symbol_type;

/**
 * Symbol struct
 */
typedef struct comp_grammar_symbol_t comp_grammar_symbol_t;
struct comp_grammar_symbol_t {
    symbol_type type;
    int code_line_number;
    void *value;    
};

/**
 * initialize grammar_symbol with prev,next with its same address
 */
static inline void __comp_grammar_symbol_init(comp_grammar_symbol_t *grammar_symbol);
/**
 * create a grammar_symbol, alloc mem and return address
 */
comp_grammar_symbol_t *new_comp_grammar_symbol();
/**
 * free address memory used by grammar_symbol
 */
void comp_grammar_symbol_delete(comp_grammar_symbol_t *grammar_symbol);

/**
 * set grammar_symbol
 */
void comp_grammar_symbol_set(comp_grammar_symbol_t *grammar_symbol, symbol_type type, int code_line_number, void *value);

/**
 * print grammar_symbol
 */
void comp_grammar_symbol_print(comp_grammar_symbol_t *grammar_symbol);


/**
 * append a symbol to the symbol_table
 */
void yy_symbol_table_append(char *identifier, comp_grammar_symbol_t *symbol);

/**
 * initialize the symbol_table
 */
void symbol_table_init();

/**
 * print the symbol_table
 */
void yy_symbol_table_print();


#endif /* COMP_GRAMMAR_H */