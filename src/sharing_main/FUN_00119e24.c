/* HSTMATCH module=hstp_trans_main.prx start=0x00119e24 end=0x00119e58 symbol=FUN_00119e24 lang=c99 */
/* Clone of src/eboot/FUN_00111010.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 DAT_003eaaac;
extern void FUN_00108aec();

void FUN_00119e24(void)
{
  *(undefined1 *)(DAT_003eaaac + 0x88) = 1;
  FUN_00108aec();
  *(undefined1 *)(DAT_003eaaac + 0x88) = 0;
  return;
}
