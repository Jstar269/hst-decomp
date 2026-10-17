/* HSTMATCH module=EBOOT.BIN start=0x002800ac end=0x00280114 symbol=FUN_002800ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: reused and stored the allocation result on both null and initialized paths; exact match verified; names and types await human review. */
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

extern undefined DAT_002fe8c8;
extern undefined4 DAT_0034a7f0;
extern char DAT_002fe888[];
extern int FUN_00000bcc();
extern int * FUN_000649c0();
extern undefined4 FUN_00064bf4();

undefined4 * FUN_002800ac(undefined4 *param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  *param_1 = 0;
  DAT_0034a7f0 = (unsigned int)(param_1);
  iVar1 = FUN_00000bcc(0x10);
  if (iVar1 != 0) {
    iVar1 = (int)FUN_000649c0(iVar1);
  }
  *param_1 = iVar1;
  FUN_00064bf4(iVar1,DAT_002fe888 + 0x10,1,&DAT_002fe8c8);
  return param_1;
}


