/* HSTMATCH module=hstp_trans_main.prx start=0x001b1a70 end=0x001b1af8 symbol=FUN_001b1a70 lang=c99 */
/* Clone of src/eboot/FUN_001a44a4.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef int bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern char DAT_003895cc[];
extern void FUN_00177c64();
extern int FUN_001aabec();
extern int FUN_001b1900();

void FUN_001b1a70(int param_1)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = **(int **)(*(int *)(param_1 + 900) + *(int *)(param_1 + 0x300) * 4);
  bVar1 = iVar2 == -1;
  if (bVar1) {
    uVar3 = FUN_001b1900();
    iVar2 = FUN_001aabec(DAT_003895cc,uVar3);
  }
  FUN_00177c64(iVar2,bVar1);
  *(undefined4 *)(param_1 + 0x308) = *(undefined4 *)(param_1 + 0x2fc);
  *(undefined4 *)(param_1 + 0x30c) = *(undefined4 *)(param_1 + 0x300);
  *(undefined4 *)(param_1 + 0x310) = *(undefined4 *)(param_1 + 0x304);
  return;
}
