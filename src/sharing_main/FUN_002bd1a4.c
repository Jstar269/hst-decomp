/* HSTMATCH module=hstp_trans_main.prx start=0x002bd1a4 end=0x002bd218 symbol=FUN_002bd1a4 lang=c99 */
/* Clone of src/eboot/FUN_002ad9e8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined DAT_003f4830;
extern undefined4 DAT_003f48d0;
extern int FUN_00177d4c();
extern void FUN_001cd870();

void FUN_002bd1a4(void)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  if (0 < DAT_003f48d0) {
    puVar3 = (undefined4 *)&DAT_003f4830;
    do {
      uVar1 = FUN_00177d4c();
      FUN_001cd870(uVar1,*puVar3,4);
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < DAT_003f48d0);
  }
  DAT_003f48d0 = 0;
  return;
}
