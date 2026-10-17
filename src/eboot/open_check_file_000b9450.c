/* HSTMATCH module=EBOOT.BIN start=0x000b9450 end=0x000b94b8 symbol=FUN_000b9450 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the sign test written as >= 0 (bltzl); exact match verified; names and types await human review. */
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

extern undefined DAT_002d4848;
extern char DAT_002d4a40[];
extern void FUN_000143b0();
extern int FUN_0004ccb8();
extern undefined4 FUN_0004cfd0();
extern void FUN_0004d028();

void FUN_000b9450(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  undefined1 auStack_100 [256];
  
  FUN_000143b0(auStack_100,DAT_002d4a40,param_2);
  iVar1 = FUN_0004ccb8(auStack_100,1,1);
  if (iVar1 >= 0) {
    FUN_0004d028(iVar1,&DAT_002d4848,0x120);
    FUN_0004cfd0(iVar1);
  }
  return;
}
