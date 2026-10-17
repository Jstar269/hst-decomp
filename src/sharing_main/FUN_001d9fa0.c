/* HSTMATCH module=hstp_trans_main.prx start=0x001d9fa0 end=0x001da030 symbol=FUN_001d9fa0 lang=c99 */
/* Clone of src/eboot/FUN_001cb7d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003ea8ec;
extern void FUN_00111aa4();
extern void FUN_0011e940();
extern void FUN_001d06dc();
extern void FUN_001dbf68();
extern undefined * FUN_00238a68();

void FUN_001d9fa0(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x15c);
  *(undefined1 *)(iVar2 + 0xb0) = 0;
  iVar1 = (int)(FUN_00238a68(iVar2 + 0x34,*(undefined4 *)(iVar2 + 0x24),param_2,0));
  if (iVar1 != 0) {
    FUN_0011e940(DAT_003ea8ec,1,iVar1,0,0);
    FUN_00111aa4(**(undefined4 **)(DAT_003ea8ec + 0x58),0,0);
    FUN_001dbf68(iVar2,4,1);
    FUN_001d06dc(iVar2);
  }
  return;
}
