#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments parameter
 * @argv: argments list
 * Return: equal to null
 */

int main(int argc, char *argv[])
{
        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        open_file(argv[1]);
        free_nodes();
        return (0);
}
/**
 * create_node - The function to create a node
 * @n: the number in the nide
 * Return: there is a return
 */
stack_t *create_node(int n)
{
        stack_t *nd;

        nd = malloc(sizeof(stack_t));
        if (nd == NULL)
                err(4);
        nd->next = NULL;
        nd->prev = NULL;
        nd->n = n;
        return (nd);
}
/**
 * free_nodes - the  function to free node
 */
void free_nodes(void)
{
        stack_t *c;

        if (head == NULL)
                return;

        while (head != NULL)
        {
                c = head;
                head = head->next;
                free(c);
        }
}

/**
 * add_to_queue - Adds a node to the queue.
 * @nnd: Pointer to a node
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **nnd, __attribute__((unused))unsigned int ln)
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
        while (c->next != NULL)
                c = c->next;

        c->next = *nnd;
        (*nnd)->prev = c;
}
