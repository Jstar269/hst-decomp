/* HSTMATCH module=hstp_trans_main.prx start=0x00228668 end=0x0022869c symbol=FUN_00228668 lang=c99 */
/* Clone of src/eboot/FUN_00155ea4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b28a4;
extern undefined4 * FUN_0005b6bc();

undefined4 * FUN_00228668(undefined4 *param_1)
{
  FUN_0005b6bc();
  *param_1 = (unsigned int)(&DAT_003b28a4);
  return param_1;
}
