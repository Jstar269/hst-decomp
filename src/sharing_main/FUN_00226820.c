/* HSTMATCH module=hstp_trans_main.prx start=0x00226820 end=0x0022687c symbol=FUN_00226820 lang=c99 */
/* Clone of src/eboot/FUN_00217778.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_002269c4();
extern void FUN_002269d0();
extern void FUN_002269dc();

void FUN_00226820(int *param_1,int param_2)
{
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[4] = 0;
  if (*param_1 != 0) {
    *(undefined2 *)(param_1 + 2) = 0;
    *(undefined2 *)((int)param_1 + 10) = 0;
    *(undefined2 *)(param_1 + 3) = 0x80;
  }
  FUN_002269c4(param_1);
  FUN_002269d0(param_1);
  FUN_002269dc(param_1);
  return;
}
