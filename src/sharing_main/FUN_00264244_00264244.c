/* HSTMATCH module=hstp_trans_main.prx start=0x00264244 end=0x002643dc symbol=FUN_00264244 lang=c99 */
/* Clone of src/eboot/FUN_00253da0_00253da0.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: declared the loop index before the byte offset to match the retail saved-register allocation; exact match verified; names and types await human review. */
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

extern undefined * DAT_003f3acc;
extern char DAT_003a5820[];
extern char DAT_003a5850[];
extern char DAT_003a5880[];
extern char DAT_003a58ac[];
extern char DAT_003a58d8[];
extern char DAT_003a5904[];
extern int * FUN_000008d8();
extern int FUN_00000a90();
extern void FUN_000143b0();
extern undefined4 FUN_00056a58();
extern void FUN_0005697c();
extern void FUN_000569f4();

void FUN_00264244(void)
{
  undefined4 uVar1;
  int iVar3;
  int iVar2;
  undefined1 auStack_100 [256];
  
  uVar1 = FUN_00000a90(0x230);
  DAT_003f3acc = (unsigned char *)(FUN_000008d8(uVar1,FUN_0005697c,FUN_000569f4,0x10,0x22));
  iVar3 = 0;
  iVar2 = 0;
  do {
    if (iVar3 < 0xf) {
      FUN_000143b0(auStack_100,DAT_003a5820,iVar3,iVar3);
      FUN_00056a58(DAT_003f3acc + iVar2,auStack_100,0);
    }
    else if (iVar3 < 0x1e) {
      FUN_000143b0(auStack_100,DAT_003a5850,iVar3 + -0xf,iVar3 + -0xf
                  );
      FUN_00056a58(DAT_003f3acc + iVar2,auStack_100,0);
    }
    else if (iVar3 == 0x1e) {
      FUN_00056a58(DAT_003f3acc + iVar2,DAT_003a5880,0);
    }
    else if (iVar3 == 0x1f) {
      FUN_00056a58(DAT_003f3acc + iVar2,DAT_003a58ac,0);
    }
    else if (iVar3 == 0x20) {
      FUN_00056a58(DAT_003f3acc + iVar2,DAT_003a58d8,0);
    }
    else if (iVar3 == 0x21) {
      FUN_00056a58(DAT_003f3acc + iVar2,DAT_003a5904,0);
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 0x10;
  } while (iVar3 < 0x22);
  return;
}

