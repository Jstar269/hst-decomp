/* HSTMATCH module=hstp_trans_main.prx start=0x00193634 end=0x00193664 symbol=FUN_00193634 lang=c99 */
/* Clone of src/eboot/FUN_00186ee8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00108558();

void FUN_00193634(int param_1,int param_2)
{
  *(undefined1 *)(param_1 + 0x1250) = 0;
  *(float *)(*(int *)(param_1 + 0x28) + 0x60) =
       (float)(*(int *)(param_1 + 0x1238) - *(int *)(param_1 + 0x123c) * param_2);
  FUN_00108558(*(undefined4 *)(param_1 + 0x28));
  return;
}
