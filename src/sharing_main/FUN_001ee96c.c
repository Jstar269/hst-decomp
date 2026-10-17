/* HSTMATCH module=hstp_trans_main.prx start=0x001ee96c end=0x001ee980 symbol=FUN_001ee96c lang=c99 */
/* Clone of src/eboot/FUN_001e0748.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b7ebc;
extern char DAT_003939d4[];
extern void FUN_0001c5f4();

void FUN_001ee96c(undefined4 param_1,undefined4 param_2,uint param_3,int *param_4,undefined4 param_5 ,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  FUN_0001c5f4((int)&DAT_003b7ebc,DAT_003939d4,param_3,param_4,param_5,param_6,
               param_7,param_8);
  return;
}
