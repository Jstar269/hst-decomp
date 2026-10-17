/* HSTMATCH module=hstp_trans_main.prx start=0x000bdd24 end=0x000bdd78 symbol=FUN_000bdd24 lang=c99 */
/* Clone of src/eboot/FUN_000ba9e0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_0037b360;
extern undefined DAT_0037b370;

void FUN_000bdd24(undefined4 param_1,undefined4 *param_2)
{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0x5a4;
    param_2[1] = 0x5a4;
    param_2[2] = 1;
    param_2[3] = 0x10;
    param_2[4] = 0x20000;
    param_2[5] = 0x8000;
    param_2[6] = (unsigned int)(&DAT_0037b360);
    param_2[7] = (unsigned int)(&DAT_0037b370);
  }
  return;
}
