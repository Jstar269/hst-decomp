/* HSTMATCH module=hstp_trans_main.prx start=0x00198514 end=0x00198530 symbol=FUN_00198514 lang=c99 */
/* Clone of src/eboot/FUN_0018bd64.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003ba2f8;
extern void FUN_00197eec();

void FUN_00198514(int param_1)
{
  *(undefined1 *)(param_1 + 0x44) = 1;
  DAT_003ba2f8 = (unsigned int)(FUN_00197eec);
  return;
}
