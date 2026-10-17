/* HSTMATCH module=hstp_trans_main.prx start=0x00277650 end=0x00277668 symbol=FUN_00277650 lang=c99 */
/* Clone of src/eboot/FUN_00266748.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00277650(int param_1)
{
  if (*(int *)(param_1 + 0x70) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x70) + 0xd0) = 0;
  }
  return;
}
