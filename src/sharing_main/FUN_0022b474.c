/* HSTMATCH module=hstp_trans_main.prx start=0x0022b474 end=0x0022b498 symbol=FUN_0022b474 lang=c99 */
/* Clone of src/eboot/FUN_0021bf00.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_0022b474(float param_1,float param_2,int param_3)
{
  *(float *)(param_3 + 0xe0) = param_1 - 150.0f;
  *(float *)(param_3 + 0xe4) = param_2 - 200.0f;
  return;
}
