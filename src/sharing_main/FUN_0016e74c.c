/* HSTMATCH module=hstp_trans_main.prx start=0x0016e74c end=0x0016e76c symbol=FUN_0016e74c lang=c99 */
/* Clone of src/eboot/FUN_001621c0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


float FUN_0016e74c(int param_1,int param_2)
{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x16c);
  if (param_2 - 1U < 2) {
    fVar1 = fVar1 + *(float *)(param_1 + 0x3c4);
  }
  return fVar1;
}
