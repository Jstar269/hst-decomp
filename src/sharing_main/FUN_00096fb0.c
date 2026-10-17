/* HSTMATCH module=hstp_trans_main.prx start=0x00096fb0 end=0x00096fec symbol=FUN_00096fb0 lang=c99 */
/* Clone of src/eboot/FUN_00094fa4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0544;
extern undefined4 * FUN_000577ec();
extern void FUN_00097048();

undefined4 * FUN_00096fb0(undefined4 *param_1)
{
  FUN_000577ec();
  *param_1 = (unsigned int)(&DAT_003b0544);
  FUN_00097048(param_1);
  return param_1;
}
