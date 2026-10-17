/* HSTMATCH module=hstp_trans_main.prx start=0x001eb440 end=0x001eb484 symbol=FUN_001eb440 lang=c99 */
/* Clone of src/eboot/FUN_001dd21c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00108dac();
extern void FUN_001f8b80();
extern void FUN_001f8bd4();
extern void FUN_001f8ca4();

void FUN_001eb440(int param_1)
{
  FUN_00108dac();
  FUN_001f8bd4(*(undefined4 *)(param_1 + 0x8c),0);
  FUN_001f8ca4(*(undefined4 *)(param_1 + 0x8c),0);
  FUN_001f8b80(*(undefined4 *)(param_1 + 0x8c));
  return;
}
