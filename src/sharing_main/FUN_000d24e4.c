/* HSTMATCH module=hstp_trans_main.prx start=0x000d24e4 end=0x000d2508 symbol=FUN_000d24e4 lang=c99 */
/* Clone of src/eboot/FUN_000ce8e8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0808;
extern undefined DAT_003b081c;

undefined4 * FUN_000d24e4(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b0808);
  param_1[1] = 0;
  *param_1 = (unsigned int)(&DAT_003b081c);
  return param_1;
}
