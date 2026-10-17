/* HSTMATCH module=hstp_trans_main.prx start=0x001e9da4 end=0x001e9de0 symbol=FUN_001e9da4 lang=c99 */
/* Clone of src/eboot/FUN_001dbc04.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e1a54;
extern void FUN_0005ffd8();

void FUN_001e9da4(int param_1)
{
  if ((*(int *)(param_1 + 0x3c) != 0) && (*(uchar *)(param_1 + 0xcc) != '\0')) {
    FUN_0005ffd8(*(int *)(param_1 + 0x3c),DAT_003e1a54);
  }
  return;
}
