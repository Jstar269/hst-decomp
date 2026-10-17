/* HSTMATCH module=hstp_trans_main.prx start=0x001a0bcc end=0x001a0c10 symbol=FUN_001a0bcc lang=c99 */
/* Clone of src/eboot/FUN_001943bc_001943bc.c (hstclone.py tag u3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003eaa70;
extern undefined4 DAT_003eaa7c;
extern undefined4 DAT_003eaa80;

undefined4 FUN_001a0bcc(void)
{
  if (DAT_003eaa80 == 0) goto zero;
  if (DAT_003eaa7c == 0) goto zero;
  if (DAT_003eaa70 == 0) goto zero;
  return 1;
zero:
  return 0;
}
