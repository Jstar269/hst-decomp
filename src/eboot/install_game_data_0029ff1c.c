/* HSTMATCH module=EBOOT.BIN start=0x0029ff1c end=0x002a0058 symbol=FUN_0029ff1c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: pass the saved status as the variadic error argument. */
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

extern char DAT_002cbdc0[];
extern char DAT_002cbe10[];
extern char DAT_002cbe1c[];
extern char DAT_002cbe28[];
extern char DAT_002cbe74[];
extern char DAT_002cbebc[];
extern char DAT_002cbec8[];
extern char DAT_002cbf18[];
extern char DAT_002cbf60[];
extern char DAT_002cbf6c[];
extern uint FUN_000fe448();
extern int FUN_00296d60();
extern int FUN_00296ff8();
extern int FUN_002973a4();
extern void FUN_0029e3cc(const char *, ...);
extern int FUN_002b79b0();

undefined4 FUN_0029ff1c(undefined4 param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_2;
  iVar1 = FUN_000fe448(DAT_002cbf6c,DAT_002cbf60,
                       *(undefined4 *)(iVar3 + 8),0x218000);
  if (iVar1 < 0) {
    FUN_0029e3cc(DAT_002cbf18,*(undefined4 *)(iVar3 + 0x20));
    *(undefined4 *)(iVar3 + 0x20) = 0xffffffff;
  }
  else {
    iVar2 = FUN_00296d60();
    *(int *)(iVar3 + 0x20) = iVar2;
    if (iVar2 < 0) {
      FUN_0029e3cc(DAT_002cbec8,iVar2);
      goto LAB_0029fff8;
    }
    iVar1 = FUN_002973a4(DAT_002cbebc,*(undefined4 *)(iVar3 + 8),iVar1);
    *(int *)(iVar3 + 0x20) = iVar1;
    if (iVar1 < 0) {
      FUN_0029e3cc(DAT_002cbe74,iVar1);
    }
    else {
      iVar1 = FUN_00296ff8();
      *(int *)(iVar3 + 0x20) = iVar1;
      if (iVar1 < 0) {
        FUN_0029e3cc(DAT_002cbe28,iVar1);
      }
    }
  }
LAB_0029fff8:
  iVar1 = *(int *)(iVar3 + 0x20);
  if (iVar1 >= 0) {
    FUN_0029e3cc(DAT_002cbe1c);
  } else {
    FUN_0029e3cc(DAT_002cbe10,iVar1);
  }
  iVar1 = FUN_002b79b0(0);
  if (iVar1 < 0) {
    FUN_0029e3cc(DAT_002cbdc0,iVar1);
  }
  return 0;
}
