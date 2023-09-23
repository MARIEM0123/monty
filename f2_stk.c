#include "monty.h"

/**
 * swap_nodes - the funct to swaps the top
 * @stk: Point to the top
 * @ln: the number of lines
 */
void swap_nodes(stack_t **stk, unsigned int ln)
{
        stack_t *c;

        if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
                more_err(8, ln, "swap");
        c = (*stk)->next;
        (*stk)->next = c->next;
        if (c->next != NULL)
                c->next->prev = *stk;
        c->next = *stk;
        (*stk)->prev = c;
        c->prev = NULL;
        *stk = c;
}
/**
 * nop - the function doen nothing
 * @stack: Poits to thr top
 * @ln: the number of line
 */
void nop(stack_t **stk, unsigned int ln)
{
        (void)stk;
        (void)ln;
}
/**
 * sub_nodes - to add to the top of the stack
 * @stack: Points to the top
 * @ln: the number of line
 */
void sub_nodes(stack_t **stk, unsigned int ln)
{
        int s;

        if (stk == NULL || *stk == NULL || (*stk)->next == NULL)

                more_err(8, ln, "sub");


        (*stk) = (*stk)->next;
        s = (*stk)->n - (*stk)->prev->n;
        (*stk)->n = s;
        free((*stk)->prev);
        (*stk)->prev = NULL;
}
/**
 * div_nodes - the funct to add to the top
 * @stk: Pointer to the top
 * @ln: the  number of lines
 */
void div_nodes(stack_t **stk, unsigned int ln)
{
        int s;

        if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
                more_err(8, ln, "div");

        if ((*stk)->n == 0)
                more_err(9, ln);
        (*stk) = (*stk)->next;
        s = (*stk)->n / (*stk)->prev->n;
        (*stk)->n = s;
        free((*stk)->prev);
        (*stk)->prev = NULL;
}

/**
 * add_nodes - the funct dds the top
 * @stk: Points to the top
 * @ln: the nulber of lines
 */
void add_nodes(stack_t **stk, unsigned int ln)
{
        int s;

        if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
                more_err(8, ln, "add");

        (*stk) = (*stk)->next;
        s = (*stk)->n + (*stk)->prev->n;
        (*stk)->n = s;
        free((*stk)->prev);
        (*stk)->prev = NULL;
}
