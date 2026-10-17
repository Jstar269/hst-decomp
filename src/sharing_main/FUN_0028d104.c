/* HSTMATCH module=hstp_trans_main.prx start=0x0028d104 end=0x0028d128 symbol=FUN_0028d104 lang=c99 */
/* Clone of src/eboot/FUN_001233bc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 FUN_0028dacc();
extern void FUN_0028df98();

void FUN_0028d104(void)
{
  undefined4 uVar1;
  
  uVar1 = FUN_0028dacc();
  FUN_0028df98(uVar1);
  return;
}
