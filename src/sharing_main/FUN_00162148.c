/* HSTMATCH module=hstp_trans_main.prx start=0x00162148 end=0x001621b4 symbol=FUN_00162148 lang=c99 */
/* Clone of src/eboot/FUN_00155c40.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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
extern undefined4 DAT_003f344c;
extern char DAT_00384078[];
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern int FUN_001d54e8();
extern void FUN_002a4d70();

undefined4 FUN_00162148(int param_1,undefined4 param_2)
{
  int iVar1;
  
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68(DAT_00384078,*(undefined4 *)(param_1 + 8));
  }
  iVar1 = FUN_001d54e8(DAT_003f344c,*(undefined4 *)(param_1 + 8));
  if (iVar1 != 0) {
    FUN_002a4d70(iVar1,0);
  }
  return 0;
}
