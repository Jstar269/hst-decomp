/* HSTMATCH module=EBOOT.BIN start=0x001b177c end=0x001b1810 symbol=FUN_001b177c lang=c99 */
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

extern undefined DAT_002e97fc;
extern undefined DAT_002e9804;
extern undefined DAT_002e9808;
extern uint * FUN_00014788();
extern uint * FUN_000149a8();
extern char * FUN_00014b74();
extern int FUN_00014cfc();
extern char * FUN_00014d64();

void FUN_001b177c(undefined4 param_1)
{
  undefined1 *puVar1;
  int iVar2;
  undefined1 auStack_10 [16];
  
  puVar1 = (undefined1 *)FUN_00014cfc(param_1,0x2e);
  if (puVar1 != (undefined1 *)0x0) {
    FUN_000149a8(auStack_10,puVar1);
    *puVar1 = 0;
    FUN_00014788(param_1,&DAT_002e97fc);
    FUN_00014788(param_1,auStack_10);
  }
  iVar2 = (int)(FUN_00014d64(param_1,&DAT_002e9804));
  if (iVar2 != 0) {
    FUN_00014b74(iVar2,&DAT_002e9808,3);
  }
  return;
}
