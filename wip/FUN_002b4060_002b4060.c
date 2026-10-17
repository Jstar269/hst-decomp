/* HSTMATCH module=EBOOT.BIN start=0x002b4060 end=0x002b40b0 symbol=FUN_002b4060 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_002b40b0(void *, void *);
extern void FUN_002b4194(void *, void *);

void FUN_002b4060(void *param_1,void *param_2)
{
  undefined1 auStack_64 [100];
  
  FUN_002b4194(auStack_64,param_1);
  FUN_002b40b0(param_1,param_2);
  FUN_002b40b0(param_2,auStack_64);
  return;
}
// Near miss: six words differ because the two saved parameter registers are reversed from retail.
// Tried void pointer formals, typed helper prototypes, and C++ mode; these did not change the register coloring.
// near miss from lane u5cr1-2 (unreviewed)
