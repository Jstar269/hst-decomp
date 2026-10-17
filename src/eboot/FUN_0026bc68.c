/* HSTMATCH module=EBOOT.BIN start=0x0026bc68 end=0x0026bccc symbol=FUN_0026bc68 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern undefined4 DAT_003386c8;
extern int * FUN_0025c474();
extern int * FUN_0025de54();
extern int * FUN_00261e1c();
extern int * FUN_00269798();
extern int * FUN_0026b590();

undefined4 * FUN_0026bc68(undefined4 *param_1)
{
  *param_1 = *(undefined4 *)(DAT_003386c8 + 0x40);
  FUN_00269798(param_1 + 1);
  FUN_0025de54(param_1 + 0x44);
  FUN_0025c474(param_1 + 0x1bc);
  FUN_00261e1c(param_1 + 0x2af);
  FUN_0026b590(param_1 + 0x2d2);
  param_1[0x2ee] = 0;
  param_1[0x2f2] = 0;
  return param_1;
}
