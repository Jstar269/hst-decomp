/* HSTMATCH module=hstp_trans_main.prx start=0x00210984 end=0x002109a4 symbol=FUN_00210984 lang=c99 */
/* Clone of src/eboot/FUN_002021b4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00210984(float param_1,uchar *param_2)
{
  if (*param_2 != '\0') {
    *(float *)(param_2 + 0x14) = *(float *)(param_2 + 0x14) + param_1;
  }
  return;
}
