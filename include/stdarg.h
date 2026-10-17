#ifndef HST_STDARG_NOTE
# define HST_STDARG_NOTE
/* Project-authored stdarg.h for psp-gcc 3.3.3 (MIPS o32, little-endian). Written from ISO C 7.15 and the
   compiler's built-in variable-argument support (__builtin_va_list and the __builtin_va_* operations); it
   contains no compiler vendor text. A header that needs only the list type (stdio.h's prototypes) defines
   __need___va_list first and gets just __gnuc_va_list. */
#endif

#ifndef HST_GNUC_VA_LIST_DEFINED
# define HST_GNUC_VA_LIST_DEFINED
typedef __builtin_va_list __gnuc_va_list;
#endif

#ifndef __need___va_list

# ifndef HST_STDARG_H
#  define HST_STDARG_H

typedef __gnuc_va_list va_list;

#  define va_start(ap, last) __builtin_va_start(ap,last)
#  define va_arg(ap, type) __builtin_va_arg(ap,type)
#  define va_end(ap) __builtin_va_end(ap)
#  define va_copy(dest, src) __builtin_va_copy(dest, src)
#  define __va_copy(dest, src) __builtin_va_copy(dest, src)

# endif

#endif

#undef __need___va_list
