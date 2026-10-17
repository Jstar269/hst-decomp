/* HSTMATCH module=hstp_trans_main.prx start=0x0015eef8 end=0x0015ef68 symbol=FUN_0015eef8 lang=c99 */
/* Clone of src/eboot/FUN_00152d70.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003e9630;
extern char DAT_00383be8[];
extern int FUN_00157e10();
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern code * FUN_0023ce60();

undefined4 FUN_0015eef8(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68(DAT_00383be8,*(undefined4 *)(param_1 + 8));
  }
  uVar3 = *param_2;
  iVar1 = (int)(FUN_0023ce60());
  uVar4 = *(undefined4 *)(iVar1 + 0x138);
  puVar2 = (undefined4 *)FUN_00157e10(uVar3,*(undefined4 *)(param_1 + 8));
  *puVar2 = uVar4;
  return 0;
}
