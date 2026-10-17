/* HSTMATCH module=hstp_trans_main.prx start=0x001a0920 end=0x001a0b58 symbol=FUN_001a0920 lang=c99 */
/* Clone of src/eboot/global_cleanup_00194110.c (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the delete calls (0xa00) take the tested global as argument (Ghidra dropped it); exact match verified; names and types await human review. */
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

extern undefined * DAT_003eaa70;
extern undefined * DAT_003eaa74;
extern undefined * DAT_003eaa78;
extern undefined * DAT_003eaa7c;
extern undefined * DAT_003eaa80;
extern undefined * DAT_003eaa88;
extern void FUN_000009e4();
extern void FUN_00000a00(void *);
extern int FUN_0019ff00();

void FUN_001a0920(void)
{
  int iVar1;
  
  if (DAT_003eaa70 != 0) {
    iVar1 = *(int *)(DAT_003eaa70 + 4);
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      *(undefined4 *)(DAT_003eaa70 + 4) = 0;
    }
    if (DAT_003eaa70 != 0) {
      FUN_00000a00(DAT_003eaa70);
      DAT_003eaa70 = 0;
    }
  }
  if (DAT_003eaa7c != 0) {
    iVar1 = *(int *)(DAT_003eaa7c + 4);
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      *(undefined4 *)(DAT_003eaa7c + 4) = 0;
    }
    if (DAT_003eaa7c != 0) {
      FUN_00000a00(DAT_003eaa7c);
      DAT_003eaa7c = 0;
    }
  }
  if (DAT_003eaa74 != 0) {
    iVar1 = *(int *)(DAT_003eaa74 + 4);
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      *(undefined4 *)(DAT_003eaa74 + 4) = 0;
    }
    if (DAT_003eaa74 != 0) {
      FUN_00000a00(DAT_003eaa74);
      DAT_003eaa74 = 0;
    }
  }
  if (DAT_003eaa78 != 0) {
    iVar1 = *(int *)(DAT_003eaa78 + 4);
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      *(undefined4 *)(DAT_003eaa78 + 4) = 0;
    }
    if (DAT_003eaa78 != 0) {
      FUN_00000a00(DAT_003eaa78);
      DAT_003eaa78 = 0;
    }
  }
  if (DAT_003eaa80 != 0) {
    iVar1 = *(int *)(DAT_003eaa80 + 4);
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      *(undefined4 *)(DAT_003eaa80 + 4) = 0;
    }
    if (DAT_003eaa80 != 0) {
      FUN_00000a00(DAT_003eaa80);
      DAT_003eaa80 = 0;
    }
  }
  iVar1 = (int)(DAT_003eaa88);
  if (DAT_003eaa88 != 0) {
    if (DAT_003eaa88 != 0) {
      FUN_0019ff00(DAT_003eaa88 + 0x40,0xffffffff);
      FUN_0019ff00(iVar1 + 0x30,0xffffffff);
      FUN_0019ff00(iVar1 + 0x20,0xffffffff);
      FUN_0019ff00(iVar1 + 0x10,0xffffffff);
      FUN_0019ff00(iVar1,0xffffffff);
      FUN_00000a00((void *)iVar1);
    }
    DAT_003eaa88 = 0;
  }
  return;
}
