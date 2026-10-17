/* HSTMATCH module=hstp_trans_main.prx start=0x001a9bf8 end=0x001a9c38 symbol=FUN_001a9bf8 lang=c99 */
/* Clone of src/eboot/FUN_0019ca44.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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
typedef float undefined4;

extern float FUN_0000c018(float param_1);

void FUN_001a9bf8(undefined4 param_1,int param_2)
{
  undefined4 uVar1;
  
  *(undefined4 *)(param_2 + 0x200) = param_1;
  uVar1 = FUN_0000c018(*(float *)(param_2 + 0x200) * 0.008726646f);
  *(undefined4 *)(param_2 + 0x214) = uVar1;
  return;
}
