/* HSTMATCH module=hstp_trans_main.prx start=0x0012fd6c end=0x0012fdcc symbol=FUN_0012fd6c lang=c99 */
/* Clone of src/eboot/FUN_00124b98.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0012fdcc(int param_1,int param_2,float *param_3);

void FUN_0012fd6c(undefined4 param_1,int param_2,float *param_3,float *param_4)
{
  *(undefined4 *)(param_2 + 0x48) = 0;
  FUN_0012fdcc(param_2,1,param_3);
  FUN_0012fdcc(param_2,2,param_4);
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x88) = param_1;
  return;
}
