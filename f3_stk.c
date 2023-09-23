#include "monty.h"

/**
 * mod_nodes - to add to the top
 * @stack: Poin to the top
 * @ln: the number of line
 */
void mod_nodes(stack_t **stk, unsigned int ln)
{
        int s;

        if (stk == NULL || *stk == NULL || (*stk)->next == NULL)

                more_err(8, ln, "mod");


        if ((*stk)->n == 0)
                more_err(9, ln);
        (*stk) = (*stk)->next;
        s = (*stk)->n % (*stk)->prev->n;
        (*stk)->n = s;
        free((*stk)->prev);
        (*stk)->prev = NULL;
}
/**
 * mul_nodes - to add to the top
 * @stack: Point to top
 * @ln: the number of lines
 */
void mul_nodes(stack_t **stk, unsigned int ln)
{
        int s;

        if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
                more_err(8, ln, "mul");

        (*stk) = (*stk)->next;
        s = (*stk)->n * (*stk)->prev->n;
        (*stk)->n = s;
        free((*stk)->prev);
        (*stk)->prev = NULL;
}
