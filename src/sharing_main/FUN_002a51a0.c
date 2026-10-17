/* HSTMATCH module=hstp_trans_main.prx start=0x002a51a0 end=0x002a51e0 symbol=FUN_002a51a0 lang=c99 */
/* Clone of src/eboot/FUN_00293b94.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


short * FUN_002a51a0(int param_1,int param_2,int param_3)
{
  short *psVar1;
  
  psVar1 = (short *)(*(int *)(param_1 + param_2 * 0xc) + param_3 * 10);
  if (*psVar1 == -1) {
    psVar1 = (short *)0x0;
  }
  return psVar1;
}
