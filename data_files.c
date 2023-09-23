#include "monty.h"

/**
 * read_file - the function to read rhe file
 * @fd: the file descriptor
 * Return: there is a return
 */

void read_file(FILE *file)
{
        int num, f = 0;
        char *arr = NULL;
        size_t l = 0;

        for (num = 1; getline(&arr, &l, file) != -1; num++)
        {
                f = parse_line(arr, num, f);
        }
        free(arr);
}

/**
 * open_file - the function to geti nto the file
 * @fd: the path of the file
 * Return: there is a return not null
 */

void open_file(char *fd)
{
        FILE *f = fopen(fd, "r");

        if (fd == NULL || f == NULL)
                err(2, fd);

        read_file(f);
        fclose(f);
}

/**
 * parse_line - the funct Ssparates line
 * @arr: each line in the file
 * @num: the numbre of line
 * @f:  storage format
 * Return: 0 or 1 depending of the case
 */

int parse_line(char *arr, int num, int f)
{
        char *c, *v;
        const char *m = "\n ";

        if (arr == NULL)
                err(4);

        c = strtok(arr, m);
        if (c == NULL)
                return (f);
        v = strtok(NULL, m);

        if (strcmp(c, "stack") == 0)
                return (0);
        if (strcmp(c, "queue") == 0)
                return (1);

        find_func(c, v, num, f);
        return (f);
}
/**
 * call_fun - the funct calls a given
 * @fc: poits to a given funct
 * @c: parameyter of rhe  opcped
 * @v: string parameteer
 * @ln: the number of line
 * @f: Format specifier
 */
void call_fun(op_func fc, char *c, char *v, int ln, int f)
{
        stack_t *nd;
        int fl;
        int i;

        fl = 1;
        if (strcmp(c, "push") == 0)
        {
                if (v != NULL && v[0] == '-')
                {
                        v = v + 1;
                        f = -1;
                }
                if (v == NULL)
                        err(5, ln);
                for (i = 0; v[i] != '\0'; i++)
                {
                        if (isdigit(v[i]) == 0)
                                err(5, ln);
                }
                nd = create_node(atoi(v) * fl);
                if (f == 0)
                        fc(&nd, ln);
                if (f == 1)
                        add_to_queue(&nd, ln);
        }
        else
                fc(&head, ln);
}

/**
 * find_func - the function to extracta given one
 * @c: opcode
 * @v: parameter
 * @fm:  storage format
 * @ln: the number of line
 * Return: there is a return
 */
void find_func(char *c, char *v, int ln, int fm)
{
        int i;
        int f;

        instruction_t func_list[] = {
                {"push", add_to_stack},
                {"pall", print_stack},
                {"pint", print_top},
                {"pop", pop_top},
                {"nop", nop},
                {"swap", swap_nodes},
                {"add", add_nodes},
                {"sub", sub_nodes},
		{"div", div_nodes},
                {"mul", mul_nodes},
                {"mod", mod_nodes},
                {"pchar", print_char},
                {"pstr", print_str},
                {"rotl", rt},
                {"rotr", rotr},
                {NULL, NULL}
        };

        if (c[0] == '#')
                return;

        for (f = 1, i = 0; func_list[i].opcode != NULL; i++)
        {
                if (strcmp(c, func_list[i].opcode) == 0)
                {
                        call_fun(func_list[i].f, c, v, ln, fm);
                        f = 0;
                }
        }
        if (f == 1)
                err(3, ln, c);
}
