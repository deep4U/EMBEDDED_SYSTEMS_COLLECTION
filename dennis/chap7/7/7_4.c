#include <stdarg.h>
#include <stdio.h>

/* minprintf:  minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int *ival;
    double* dval;
    unsigned* uval;

    va_start(ap, fmt);    /* make ap point to the first unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
//            putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'd':
        case 'i':
            ival = va_arg(ap, int *);
            scanf("%d", ival);
            break;
        case 'c':
            ival = va_arg(ap, int *);
//            putchar(ival);
		scanf("%c",p);
            break;
        case 'u':
            uval = va_arg(ap, unsigned int *);
            scanf("%u", uval);
            break;
        case 'o':
            uval = va_arg(ap, unsigned int *);
            scanf("%o", uval);
            break;
        case 'x':
            uval = va_arg(ap, unsigned int *);
            scanf("%x", uval);
            break;
        case 'X':
            uval = va_arg(ap, unsigned int *);
            scanf("%X", uval);
            break;
        case 'e':
            dval = va_arg(ap, double *);
            scanf("%e", dval);
            break;
        case 'f':
            dval = va_arg(ap, double *);
            scanf("%f", dval);
            break;
        case 'g':
            dval = va_arg(ap, double *);
            scanf("%g", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                scanf("%c",*sval);
            break;
        default:
//            putchar(*p);
            break;
        }
    }
    va_end(ap);
}
int main()
{}
/* end of function */
