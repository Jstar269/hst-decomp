/* HSTMATCH module=hstp_trans_main.prx start=0x00137748 end=0x001377d0 symbol=FUN_00137748 lang=c99 */
/* Clone of src/eboot/FUN_0012c2dc.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_002d10e0;
extern void FUN_00137eb8();

int FUN_00137748(int param_1)
{
  *(undefined **)(param_1 + 0x40) = &DAT_002d10e0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  if (*(uint *)(param_1 + 0x78) < 10) {
    FUN_00137eb8(param_1 + 0x70,10);
  }
  if (*(uint *)(param_1 + 0x8c) < 10) {
    FUN_00137eb8(param_1 + 0x84,10);
  }
  *(undefined4 *)(param_1 + 0x90) = 0x3f800000;
  *(undefined1 *)(param_1 + 0x94) = 0;
  return param_1;
}
