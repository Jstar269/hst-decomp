/* HSTMATCH module=hstp_trans_main.prx start=0x001934b0 end=0x001934c8 symbol=FUN_001934b0 lang=c99 */
/* Clone of src/eboot/FUN_00186d64.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00111b58();

void FUN_001934b0(int param_1,int param_2,int param_3,int param_4)
{
  FUN_00111b58(*(undefined4 *)(param_1 + 0x285c),param_2 + (param_3 - param_4) * 4,0);
  return;
}
