/* HSTMATCH module=EBOOT.BIN start=0x00051050 end=0x000510c0 symbol=FUN_00051050 lang=c99 */
/* Clone of src/sharing_main/FUN_00051964.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_00306fc8;
extern void FUN_00051118();
extern void FUN_00051274();

undefined4 * FUN_00051050(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *param_1 = (unsigned int)(&DAT_00306fc8);
  FUN_00051118();
  FUN_00051274(param_1,param_2,param_3,param_4,0x10);
  return param_1;
}
