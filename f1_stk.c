#include "monty.h"
/**
 * add_to_stack - Adds a node to the stack
 * @nND: PoinT TO THE NODE
 * @ln: The line number
 */
void add_to_stack(stack_t **nnd, __attribute__((unused))unsigned int ln)
{
        stack_t *c;

        if (nnd == NULL || *nnd == NULL)
                exit(EXIT_FAILURE);
        if (head == NULL)
        {
                head = *nnd;
                return;
        }
        c = head;
        head = *nnd;
        head->next = c;
        c->prev = head;
}
/**
 * print_stack - to add a node
 * @stk: Points to the top
 * @ln: thr number of the line
 */
void print_stack(stack_t **stk, unsigned int ln)
{
        stack_t *c;

        (void) ln;
        if (stk == NULL)
                exit(EXIT_FAILURE);
        c = *stk;
        while (c != NULL)
        {
                printf("%d\n", c->n);
                c = c->next;
        }
}
/**
 * pop_top - to add a node
 * @stk: to point to the top
 * @ln: number of the line
 */
void pop_top(stack_t **stk, unsigned int ln)
{
        stack_t *c;

        if (stk == NULL || *stk == NULL)
                more_err(7, ln);

        c = *stk;
        *stk = c->next;
        if (*stk != NULL)
                (*stk)->prev = NULL;
        free(c);
}
/**
 * print_top - Prints the start node
 * @stk: Poin to the tpo
 * @ln: the number of line
 */
void print_top(stack_t **stk, unsigned int ln)
{
        if (stk == NULL || *stk == NULL)
                more_err(6, ln);
        printf("%d\n", (*stk)->n);
}

