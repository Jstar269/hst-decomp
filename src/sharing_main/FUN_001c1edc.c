/* HSTMATCH module=hstp_trans_main.prx start=0x001c1edc end=0x001c1ef4 symbol=FUN_001c1edc lang=c99 */
/* Clone of src/eboot/FUN_001b3b4c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_0038d280;
extern void FUN_001be0d0();

void FUN_001c1edc(undefined4 *param_1)
{
  FUN_001be0d0(*param_1,&DAT_0038d280,8,0);
  return;
}
