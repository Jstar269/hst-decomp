/* HSTMATCH module=hstp_trans_main.prx start=0x002be928 end=0x002be938 symbol=FUN_002be928 lang=c99 */
/* Clone of src/eboot/FUN_002af0a4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003ea8e8;
extern undefined8 FUN_001ca418(float param_1);

undefined8 FUN_002be928(void)
{
  undefined8 uVar1;
  
  uVar1 = FUN_001ca418(*(float *)(DAT_003ea8e8 + 0x1414));
  return uVar1;
}
