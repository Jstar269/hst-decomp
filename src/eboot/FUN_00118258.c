/* HSTMATCH module=EBOOT.BIN start=0x00118258 end=0x001182ac symbol=FUN_00118258 lang=c99 */
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

extern undefined DAT_00307ffc;
extern undefined4 DAT_0033b460;
extern undefined4 * FUN_0001f06c();
extern undefined4 FUN_0011835c();
extern undefined4 FUN_00118424();
extern void FUN_00118598();

undefined4 * FUN_00118258(undefined4 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00307ffc);
  FUN_00118424(param_1 + 0xb8);
  FUN_0011835c(param_1 + 0xbe);
  DAT_0033b460 = (unsigned int)(param_1);
  FUN_00118598(param_1);
  return param_1;
}
