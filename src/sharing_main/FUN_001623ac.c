/* HSTMATCH module=hstp_trans_main.prx start=0x001623ac end=0x001623e0 symbol=FUN_001623ac lang=c99 */
/* Clone of src/eboot/FUN_00155ea4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b17d4;
extern undefined4 * FUN_00157f0c();

undefined4 * FUN_001623ac(undefined4 *param_1)
{
  FUN_00157f0c();
  *param_1 = (unsigned int)(&DAT_003b17d4);
  return param_1;
}
