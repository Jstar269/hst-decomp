/* HSTMATCH module=hstp_trans_main.prx start=0x00136ae4 end=0x00136b54 symbol=FUN_00136ae4 lang=c99 */
/* Clone of src/eboot/FUN_0012b678.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001354c4();
extern undefined4 FUN_001377d0();
extern undefined4 FUN_00137a18();

void FUN_00136ae4(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)
{
  uchar cVar1;
  undefined1 uVar2;
  
  cVar1 = FUN_001377d0(param_1 + 0x370);
  if (cVar1 != '\0') {
    uVar2 = FUN_00137a18(param_1 + 0x370);
    *(undefined1 *)(param_1 + 0x410) = uVar2;
    *(undefined1 *)(param_1 + 0x32c) = param_4;
    if (*(uchar *)(param_1 + 0x410) == '\0') {
      FUN_001354c4(param_1,0xc,0xffffffff,0);
    }
  }
  return;
}
