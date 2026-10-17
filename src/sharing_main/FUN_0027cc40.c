/* HSTMATCH module=hstp_trans_main.prx start=0x0027cc40 end=0x0027cca4 symbol=FUN_0027cc40 lang=c99 */
/* Clone of src/eboot/FUN_0026bc68.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e1a08;
extern int * FUN_0026c924();
extern int * FUN_0026ec7c();
extern int * FUN_00272c44();
extern int * FUN_0027a714();
extern int * FUN_0027c50c();

undefined4 * FUN_0027cc40(undefined4 *param_1)
{
  *param_1 = *(undefined4 *)(DAT_003e1a08 + 0x40);
  FUN_0027a714(param_1 + 1);
  FUN_0026ec7c(param_1 + 0x44);
  FUN_0026c924(param_1 + 0x1bc);
  FUN_00272c44(param_1 + 0x2af);
  FUN_0027c50c(param_1 + 0x2d2);
  param_1[0x2ee] = 0;
  param_1[0x2f2] = 0;
  return param_1;
}
