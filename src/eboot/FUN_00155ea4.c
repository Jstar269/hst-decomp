/* HSTMATCH module=EBOOT.BIN start=0x00155ea4 end=0x00155ed8 symbol=FUN_00155ea4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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

extern undefined DAT_00308508;
extern undefined4 * FUN_0014c3f8();

undefined4 * FUN_00155ea4(undefined4 *param_1)
{
  FUN_0014c3f8();
  *param_1 = (unsigned int)(&DAT_00308508);
  return param_1;
}
