/* HSTMATCH module=hstp_trans_main.prx start=0x0028ab40 end=0x0028abcc symbol=FUN_0028ab40 lang=c99 */
/* Clone of src/eboot/FUN_0027985c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003751d4;
extern void FUN_0001dc34();
extern void FUN_0001de88();

void FUN_0028ab40(int param_1)
{
  FUN_0001dc34(DAT_003751d4,0x2000);
  FUN_0001de88(DAT_003751d4,0x2000,1);
  FUN_0001dc34(DAT_003751d4,0x4000);
  FUN_0001de88(DAT_003751d4,0x4000,1);
  *(undefined1 *)(param_1 + 0x170) = 0;
  *(undefined1 *)(param_1 + 0x171) = 0;
  *(undefined1 *)(param_1 + 0x172) = 0;
  *(undefined1 *)(param_1 + 0x173) = 0;
  *(undefined1 *)(param_1 + 0x174) = 0;
  *(undefined1 *)(param_1 + 0x175) = 0;
  *(undefined1 *)(param_1 + 0x176) = 0;
  *(undefined1 *)(param_1 + 0x177) = 0;
  *(undefined1 *)(param_1 + 0x17d) = 0;
  return;
}
