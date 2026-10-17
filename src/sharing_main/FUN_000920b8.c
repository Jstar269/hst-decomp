/* HSTMATCH module=hstp_trans_main.prx start=0x000920b8 end=0x00092148 symbol=FUN_000920b8 lang=c99 */
/* Clone of src/eboot/FUN_0009044c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e19f0;
extern undefined4 DAT_003e95c4;
extern int FUN_00092148();
extern void FUN_000b45fc();

void FUN_000920b8(int param_1,undefined4 param_2)
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_003e19f0 + 0x3c);
  if (((iVar2 == 4) || (iVar2 == 5)) ||
     ((iVar2 == 7 && (*(uchar *)(*(int *)(DAT_003e95c4 + 0x80) + 0x78) == '\0')))) {
    uVar1 = FUN_00092148(param_1);
    FUN_000b45fc(uVar1,param_2,*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(param_1 + 0x23c));
  }
  return;
}
