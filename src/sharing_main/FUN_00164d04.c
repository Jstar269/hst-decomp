/* HSTMATCH module=hstp_trans_main.prx start=0x00164d04 end=0x00164d60 symbol=FUN_00164d04 lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b19b0;
extern undefined DAT_003b16d8;
extern void FUN_00000a00();

undefined4 * FUN_00164d04(undefined4 *param_1,short param_2)
{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b19b0);
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b16d8);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
