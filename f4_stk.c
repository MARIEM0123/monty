#include "monty.h"

/**
 * print_str - the funct prints a string
 * @stk: Points to the top
 * @ln: the number of the line 
 */
void print_str(stack_t **stk, __attribute__((unused))unsigned int ln)
{
        int asc;
        stack_t *c;

        if (stk == NULL || *stk == NULL)
        {
                printf("\n");
                return;
        }

        c = *stk;
        while (c != NULL)
        {
                asc = c->n;
                if (asc <= 0 || asc > 127)
                        break;
                printf("%c", asc);
                c = c->next;
        }
        printf("\n");
}
/**
 * print_char - the function prints the Ascii value.
 * @stk: Points to the top
 * @ln: the number of the line
 */
void print_char(stack_t **stk, unsigned int ln)
{
        int asc;

        if (stk == NULL || *stk == NULL)
                string_err(11, ln);

        asc = (*stk)->n;
        if (asc < 0 || asc > 127)
                string_err(10, ln);
        printf("%c\n", asc);
}
/**
 * rt - place the firdt node to the bottom
 * @stk: Points to the top
 * @ln: the number of line
 */
void rt(stack_t **stk, __attribute__((unused))unsigned int ln)
{
        stack_t *c;

        if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
                return;

        c = *stk;
        while (c->next != NULL)
                c = c->next;

        c->next = *stk;
        (*stk)->prev = c;
        *stk = (*stk)->next;
        (*stk)->prev->next = NULL;
        (*stk)->prev = NULL;
}
/**
 * rotr - the funct to place the last to the top
 * @stk: Points to the top
 * @ln: the number line
 */
void rotr(stack_t **stk, __attribute__((unused))unsigned int ln)
{
        stack_t *c;

        if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
                return;

        c = *stk;

        while (c->next != NULL)
                c = c->next;

        c->next = *stk;
        c->prev->next = NULL;
        c->prev = NULL;
        (*stk)->prev = c;
        (*stk) = c;
}
