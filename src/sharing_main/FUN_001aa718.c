/* HSTMATCH module=hstp_trans_main.prx start=0x001aa718 end=0x001aa7b4 symbol=FUN_001aa718 lang=c99 */
/* Clone of src/eboot/FUN_0019d270.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0a68;
extern undefined DAT_003b122c;
extern undefined DAT_003b24b4;
extern void FUN_00000a00();
extern undefined4 * FUN_0010642c();
extern int * FUN_0010d2d4();

undefined4 * FUN_001aa718(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b24b4);
    if (param_1 != (undefined4 *)0x0) {
      puVar1 = param_1 + 0x48;
      *param_1 = (unsigned int)(&DAT_003b122c);
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        FUN_0010d2d4(puVar1,0);
      }
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = (unsigned int)(&DAT_003b0a68);
        FUN_0010642c(param_1,0);
      }
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
