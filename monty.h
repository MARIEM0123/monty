#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stk_s - the linked list of the stack
 * @n: integer
 * @prev: points to the previous node
 * @next: pointer to the next node
 * Description: the linked list node
 */
typedef struct stk_s
{
        int n;
        struct stk_s *prev;
        struct stk_s *next;
} stack_t;
/**
 * struct ins_s - the functions of the opcode
 * @opcode: the parameter
 * @f: function for the opcode
 * Description: the functio to handle opcode
 */
typedef struct in_s
{
        char *opcode;
        void (*f)(stack_t **stk, unsigned int ln);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
void open_file(char *fn);
void find_func(char *, char *, int, int);
void read_file(FILE *);
int len_chars(FILE *);
stack_t *create_node(int n);
void free_nodes(void);
int parse_line(char *arr, int ln, int f);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void call_fun(op_func, char *, char *, int, int);
void print_stack(stack_t **, unsigned int);
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void string_err(int err_c, ...);
void rt(stack_t **, unsigned int);
void err(int err_c, ...);
void more_err(int err_c, ...);
void swap_nodes(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

#endif
