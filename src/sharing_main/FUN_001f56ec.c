/* HSTMATCH module=hstp_trans_main.prx start=0x001f56ec end=0x001f5724 symbol=FUN_001f56ec lang=c99 */
/* Clone of src/eboot/FUN_001e74d4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00108f54();
extern void FUN_001f08e8();
extern void FUN_001f5724();

void FUN_001f56ec(int param_1)
{
  FUN_001f08e8();
  FUN_00108f54(*(undefined4 *)(param_1 + 0x21e4),0);
  FUN_001f5724(param_1);
  return;
}
