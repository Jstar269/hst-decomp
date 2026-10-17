/* HSTMATCH module=hstp_trans_main.prx start=0x00277ca0 end=0x00277d10 symbol=FUN_00277ca0 lang=c99 */
/* Clone of src/eboot/FUN_00266d24.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b2e40;
extern undefined4 DAT_003e95e0;
extern undefined4 * FUN_0001ec44();

undefined4 * FUN_00277ca0(undefined4 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b2e40);
  param_1[0xf] = 0;
  param_1[0x12] = 0;
  *(undefined1 *)(param_1 + 0x13) = 1;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  *(undefined1 *)(param_1 + 0x19) = 0;
  if (*(int *)(DAT_003e95e0 + 0x1364) == 6) {
    *(undefined1 *)((int)param_1 + 0x65) = 1;
  }
  else {
    *(undefined1 *)((int)param_1 + 0x65) = 0;
  }
  return param_1;
}
