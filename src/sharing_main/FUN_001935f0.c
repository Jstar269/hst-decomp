/* HSTMATCH module=hstp_trans_main.prx start=0x001935f0 end=0x00193634 symbol=FUN_001935f0 lang=c99 */
/* Clone of src/eboot/FUN_00186ea4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_001935f0(int param_1,int param_2,int param_3)
{
  *(undefined1 *)(param_1 + 0x1250) = 1;
  *(int *)(param_1 + 0x1240) = *(int *)(param_1 + 0x1238) - *(int *)(param_1 + 0x123c) * param_2;
  *(int *)(param_1 + 0x1244) = *(int *)(param_1 + 0x1238) - *(int *)(param_1 + 0x123c) * param_3;
  *(undefined4 *)(param_1 + 0x124c) = 0;
  *(undefined4 *)(param_1 + 0x1248) = 0;
  return;
}
