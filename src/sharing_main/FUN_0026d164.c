/* HSTMATCH module=hstp_trans_main.prx start=0x0026d164 end=0x0026d1ac symbol=FUN_0026d164 lang=c99 */
/* Clone of src/eboot/FUN_0025ccb4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003ea8ec;
extern void FUN_00108f54();
extern void FUN_00292408();

void FUN_0026d164(int param_1)
{
  *(undefined1 *)(param_1 + 0x54) = 0;
  *(undefined1 *)(param_1 + 0x55) = 0;
  FUN_00108f54(param_1,1);
  FUN_00108f54(DAT_003ea8ec,1);
  FUN_00292408(*(undefined4 *)(param_1 + 0x5c));
  return;
}
