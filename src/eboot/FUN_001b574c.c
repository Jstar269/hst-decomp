/* HSTMATCH module=EBOOT.BIN start=0x001b574c end=0x001b5758 symbol=FUN_001b574c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
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

extern undefined DAT_0034179c;
extern void FUN_001b4b64();

void FUN_001b574c(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5, undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  FUN_001b4b64((undefined4 *)&DAT_0034179c,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}
