/* HSTMATCH module=hstp_trans_main.prx start=0x0019cb14 end=0x0019cb58 symbol=FUN_0019cb14 lang=c99 */
/* Clone of src/eboot/FUN_00190304.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b2460;
extern undefined4 * FUN_0001ec44();
extern void FUN_001a57f4();
extern void FUN_001a58b8();

undefined4 * FUN_0019cb14(undefined4 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b2460);
  FUN_001a57f4(param_1 + 0xf);
  FUN_001a58b8(param_1);
  return param_1;
}
