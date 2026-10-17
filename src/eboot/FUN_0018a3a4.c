/* HSTMATCH module=EBOOT.BIN start=0x0018a3a4 end=0x0018a468 symbol=FUN_0018a3a4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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

extern undefined DAT_002bc410;
extern undefined DAT_002e0974;
extern undefined DAT_0030779c;
extern undefined DAT_003090e0;
extern undefined DAT_00309124;
extern undefined4 FUN_00056098();
extern undefined4 * FUN_000fbf84();
extern undefined4 * FUN_000fc00c();
extern undefined4 * FUN_000fc0a0();
extern undefined4 * FUN_00217440();

undefined4 * FUN_0018a3a4(undefined4 *param_1)
{
  FUN_000fc0a0();
  FUN_00056098(param_1 + 0xc);
  *param_1 = (unsigned int)(&DAT_0030779c);
  param_1[0x1c] = 0;
  param_1[0x1d] = 0xffffffff;
  param_1[0x1e] = 0x3f800000;
  param_1[0x1f] = 0x3f800000;
  FUN_00056098(param_1 + 0x20);
  param_1[0x30] = (unsigned int)(&DAT_002e0974);
  FUN_000fc00c(param_1,&DAT_002bc410);
  FUN_000fbf84(param_1 + 0x20,&DAT_002bc410);
  FUN_00217440(param_1 + 0x34);
  *param_1 = (unsigned int)(&DAT_003090e0);
  param_1[0x34] = (unsigned int)(&DAT_00309124);
  param_1[0x41] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  return param_1;
}
