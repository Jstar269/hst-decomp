/* HSTMATCH module=hstp_trans_main.prx start=0x00161c98 end=0x00161d04 symbol=FUN_00161c98 lang=c99 */
/* Clone of src/eboot/update_value_001557c8.c (hstclone.py tag km3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: put the true work in the if body and return false after it. */
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

extern void *DAT_003f344c;
extern int *FUN_00157e10(undefined4, undefined4);
extern int FUN_001db8f8(void *);
extern undefined4 FUN_001db978(void *);

bool FUN_00161c98(int param_1,undefined4 *param_2)
{
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (FUN_001db8f8(DAT_003f344c) == 0) {
    uVar4 = *param_2;
    uVar2 = FUN_001db978(DAT_003f344c);
    puVar3 = (undefined4 *)FUN_00157e10(uVar4,*(undefined4 *)(*(int *)(param_1 + 4) + 8));
    *puVar3 = uVar2;
    return true;
  }
  return false;
}
