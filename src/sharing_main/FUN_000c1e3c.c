/* HSTMATCH module=hstp_trans_main.prx start=0x000c1e3c end=0x000c1e54 symbol=FUN_000c1e3c lang=c99 */
/* Clone of src/eboot/FUN_000be79c.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0698;

undefined4 * FUN_000c1e3c(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b0698);
  param_1[6] = 0;
  return param_1;
}
