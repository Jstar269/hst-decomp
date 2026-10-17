/* HSTMATCH module=hstp_trans_main.prx start=0x002c4854 end=0x002c485c symbol=FUN_002c4854 lang=c99 */
/* Clone of src/eboot/FUN_001fba70.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 * FUN_002bf968(undefined4 *param_1,short param_2);

void FUN_002c4854(int param_1,short param_2)
{
  FUN_002bf968((undefined4 *)((undefined4 *)(param_1 + -0x3c)),(short)(param_2));
  return;
}
