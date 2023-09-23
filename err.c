#include "monty.h"
/**
 * string_err - handles errors for strings
 * @err_c: The cases :
 * (10) ~> The number inside a node is not ASCII bounds
 * (11) ~> The stack is empty
 */
void string_err(int err_c, ...)
{
        va_list vl;
        int ln;

        va_start(vl, err_c);
        ln = va_arg(vl, int);
        switch (err_c)
        {
                case 10:
                        fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
                        break;
                case 11:
                        fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
                        break;
                default:
                        break;
        }
        free_nodes();
        exit(EXIT_FAILURE);
}

/**
 * err -the function for the error output
 * @err_c: the parameter
 * (1) => in case of not giving a file or more than one file
 * (2) => in case the file can be opened or read
 * (3) => in case of invalid instruction
 * (4) => in case of lack of memory
 * (5) => f the parameter of push is different that an int
 * (6) => in the pint funct if the stack is empty
 * (7) => in the pop funct if the stack it empty
 * (8) => if stack is to short
 */
void err(int err_c, ...)
{
        va_list vl;
        char *c;
        int l_num;

        va_start(vl, err_c);
        switch (err_c)
        {
                case 1:
                        fprintf(stderr, "USAGE: monty file\n");
                        break;
                case 2:
                        fprintf(stderr, "Error: Can't open file %s\n",
                                va_arg(vl, char *));
                        break;
                case 3:
                        l_num = va_arg(vl, int);
                        c = va_arg(vl, char *);
                        fprintf(stderr, "L%d: unknown instruction %s\n", l_num, c);
                        break;
                case 4:
                        fprintf(stderr, "Error: malloc failed\n");
                        break;
                case 5:
                        fprintf(stderr, "L%d: usage: push integer\n", va_arg(vl, int));
                        break;
                default:
                        break;
        }
        free_nodes();
        exit(EXIT_FAILURE);
}
/**
 * more_err - funct for more errors
 * @err_c: giving the code errors to handle:
 * (6) => fo pint if the stack is empty
 * (7) => for pop if the stack is empty
 * (8) => is the stack is short
 * (9) => if dividing by 0
 */
void more_err(int err_c, ...)
{
        va_list vl;
        char *c;
        int l_num;

        va_start(vl, err_c);
        switch (err_c)
        {
                case 6:
                        fprintf(stderr, "L%d: can't pint, stack empty\n",
                                va_arg(vl, int));
                        break;
                case 7:
                        fprintf(stderr, "L%d: can't pop an empty stack\n",
                                va_arg(vl, int));
                        break;
                case 8:
                        l_num = va_arg(vl, unsigned int);
			                        c = va_arg(vl, char *);
                        fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, c);
                        break;
                case 9:
                        fprintf(stderr, "L%d: division by zero\n",
                                va_arg(vl, unsigned int));
                        break;
                default:
                        break;
        }
        free_nodes();
        exit(EXIT_FAILURE);
}
