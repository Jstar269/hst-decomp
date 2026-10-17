/* HSTMATCH module=hstp_trans_main.prx start=0x001a95d8 end=0x001a9618 symbol=FUN_001a95d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined DAT_003b251c;
extern undefined DAT_003f39a8;
extern undefined4 * FUN_0001ec44();
extern void FUN_002446f8();

undefined4 * FUN_001a95d8(undefined4 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b251c);
  FUN_002446f8(&DAT_003f39a8);
  return param_1;
}
