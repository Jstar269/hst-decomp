/* HSTMATCH module=hstp_trans_main.prx start=0x001304a4 end=0x001304d0 symbol=FUN_001304a4 lang=c99 */
/* Clone of src/eboot/FUN_001252d0.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e95c4;
extern int FUN_0013d030();

float FUN_001304a4(void)
{
  int iVar1;
  
  iVar1 = FUN_0013d030(DAT_003e95c4,6);
  return (float)iVar1;
}
