/* HSTMATCH module=EBOOT.BIN start=0x0022da30 end=0x0022dd04 symbol=FUN_0022da30 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_002f3538;
extern undefined * DAT_003415a8;
extern undefined4 DAT_003415ac;
extern undefined4 DAT_003415d4;
extern undefined1 DAT_00341771;
extern undefined4 FUN_000031f0(unsigned char *, unsigned char *);
extern undefined4 FUN_00003e04(char *, unsigned char *);
extern int FUN_00004138(unsigned char *, int);
extern void FUN_000143b0(unsigned char *, unsigned int, int);
extern int FUN_00014934(int, void *);
extern uint * FUN_000149a8(undefined *, int);
extern undefined4 * FUN_00045730(unsigned char *, unsigned int);
extern uint * FUN_000462a0(void *, unsigned int);
extern void FUN_00103628(unsigned int, int);
extern void FUN_00115088(unsigned int, int, char *, int, int);
extern undefined1 FUN_001155c0(unsigned int);
extern undefined4 FUN_001156d4(unsigned int);
extern undefined4 FUN_00190830(unsigned int);
extern int FUN_0019083c(unsigned int);
extern uint * FUN_00190880(void *, void *);
extern undefined * FUN_001fea10(int, int, int);
extern void FUN_0022d848(char *, int);
extern void FUN_0022fcdc(char *, int);
extern undefined4 FUN_002add24(unsigned int);

void FUN_0022da30(char *param_1)
{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_100 [256];
  undefined1 auStack_10c [12];
  undefined1 auStack_118 [12];
  undefined1 auStack_124 [12];
  undefined1 auStack_130 [12];
  undefined1 auStack_13c [12];
  undefined1 auStack_148 [12];
  undefined4 local_14c;
  undefined4 local_150;
  undefined4 local_154;
  undefined1 auStack_160 [12];
  
  iVar1 = FUN_00190830(DAT_003415d4);
  if ((*(uint *)(param_1 + 0x70) & 1) != 0) {
    iVar4 = *(int *)(param_1 + 0x78);
  }
  else {
    iVar4 = (int)(param_1 + 0x71);
  }
  iVar4 = FUN_00014934(iVar4,&DAT_002f3538);
  if (iVar4 == 0) {
    if (DAT_00341771 == '\0') {
      if (*(int *)(*(int *)(iVar1 + 0x70) + 0x2c) == 2) {
        psVar2 = (short *)FUN_0019083c(DAT_003415d4);
        if (*psVar2 != 0) {
          uVar3 = FUN_0019083c(DAT_003415d4);
          iVar1 = FUN_002add24(uVar3);
          if (iVar1 == 0) {
            uVar3 = FUN_0019083c(DAT_003415d4);
            FUN_00045730(auStack_130,uVar3);
            FUN_00003e04(param_1 + 0x70,auStack_130);
            FUN_00190880(param_1 + 0x7c,auStack_124);
            FUN_000462a0(auStack_124,0xffffffff);
            FUN_00004138(auStack_130,0);
            uVar3 = FUN_0019083c(DAT_003415d4);
            FUN_00045730(auStack_148,uVar3);
            FUN_00003e04(param_1 + 0x58,auStack_148);
            FUN_00190880(param_1 + 100,auStack_13c);
            FUN_000462a0(auStack_13c,0xffffffff);
            FUN_00004138(auStack_148,0);
            if ((*(uint *)(param_1 + 0x70) & 1) == 0) {
              iVar1 = (int)(param_1 + 0x71);
            }
            else {
              iVar1 = *(int *)(param_1 + 0x78);
            }
            uVar3 = (unsigned int)(FUN_001fea10(0x11,0xd,1));
            FUN_000143b0(auStack_100,uVar3,iVar1);
            FUN_000031f0(auStack_160,auStack_100);
            local_154 = 0;
            local_150 = 0;
            local_14c = 0;
            FUN_00003e04(param_1 + 0x70,auStack_160);
            FUN_00190880(param_1 + 0x7c,&local_154);
            FUN_000462a0(&local_154,0xffffffff);
            FUN_00004138(auStack_160,0);
            if ((*(uint *)(param_1 + 0x70) & 1) == 0) {
              param_1 = param_1 + 0x71;
            }
            else {
              param_1 = (char *)*(int *)(param_1 + 0x78);
            }
            FUN_00115088(DAT_003415ac,1,param_1,0,0);
            return;
          }
        }
        FUN_0022fcdc(param_1,0);
      }
      else {
        FUN_0022fcdc(param_1,0);
      }
    }
  }
  else {
    iVar1 = FUN_001155c0(DAT_003415ac);
    if (iVar1 != 0) {
      FUN_00103628(DAT_003415ac,1);
      iVar1 = FUN_001156d4(DAT_003415ac);
      if (iVar1 == 0) {
        uVar3 = FUN_0019083c(DAT_003415d4);
        FUN_00045730(auStack_118,uVar3);
        FUN_00003e04(param_1 + 0x70,auStack_118);
        FUN_00190880(param_1 + 0x7c,auStack_10c);
        FUN_000462a0(auStack_10c,0xffffffff);
        FUN_00004138(auStack_118,0);
        if ((*(uint *)(param_1 + 0x70) & 1) == 0) {
          iVar1 = (int)(param_1 + 0x71);
        }
        else {
          iVar1 = *(int *)(param_1 + 0x78);
        }
        FUN_000149a8(DAT_003415a8 + 0x20,iVar1);
        FUN_0022fcdc(param_1,0);
      }
      else {
        FUN_0022d848(param_1,0);
      }
    }
  }
  return;
}
// Near miss: 164 of 181 retail words differ, starting after the early item-name pointer branch.
// Ruled out switch versus if on the state result and integer versus pointer prototypes for the backing globals and accessors.
// near miss from lane km5 (unreviewed)

}  /* extern "C" */
// improved by lane dsm1 (unreviewed): no comparable result -> 164 differing words
