/* HSTMATCH module=EBOOT.BIN start=0x00093094 end=0x00093104 symbol=FUN_00093094 lang=c99 */
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

extern undefined DAT_002beb34;
extern char DAT_002d2a3c[];
extern char DAT_002d2a44[];
extern void FUN_000143b0();

void FUN_00093094(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, int param_5)
{
  FUN_000143b0(param_2,DAT_002d2a3c,param_4);
  FUN_000143b0(param_3,DAT_002d2a44,param_4,(int)(char)(&DAT_002beb34)[param_5]);
  return;
}
