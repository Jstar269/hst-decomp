/* HSTMATCH module=hstp_trans_main.prx start=0x001eb484 end=0x001eb4b0 symbol=FUN_001eb484 lang=c99 */
/* Clone of src/eboot/FUN_001dd260.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00108a2c();
extern void FUN_001f8e00();

void FUN_001eb484(int param_1)
{
  FUN_00108a2c();
  FUN_001f8e00(*(undefined4 *)(param_1 + 0x8c));
  return;
}
