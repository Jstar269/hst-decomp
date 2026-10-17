/* HSTMATCH module=hstp_trans_main.prx start=0x0012342c end=0x00123480 symbol=FUN_0012342c lang=c99 */
/* Clone of src/eboot/FUN_00118258.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b12c8;
extern undefined4 DAT_003e47a0;
extern undefined4 * FUN_0001ec44();
extern undefined4 FUN_00123530();
extern undefined4 FUN_001235f8();
extern void FUN_0012376c();

undefined4 * FUN_0012342c(undefined4 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b12c8);
  FUN_001235f8(param_1 + 0xb8);
  FUN_00123530(param_1 + 0xbe);
  DAT_003e47a0 = (unsigned int)(param_1);
  FUN_0012376c(param_1);
  return param_1;
}
