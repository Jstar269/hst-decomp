/* HSTMATCH module=hstp_trans_main.prx start=0x001a65f0 end=0x001a6634 symbol=FUN_001a65f0 lang=c99 */
/* Clone of src/eboot/FUN_00199afc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003f39a8;
extern void FUN_001a5e8c();
extern void FUN_002446f8();

void FUN_001a65f0(int param_1)
{
  FUN_001a5e8c(*(undefined4 *)(param_1 + 0x3c));
  if (*(uchar *)(*(int *)(param_1 + 0x3c) + 0x24) != '\0') {
    FUN_002446f8(&DAT_003f39a8);
  }
  return;
}
