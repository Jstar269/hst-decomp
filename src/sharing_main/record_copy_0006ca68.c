/* HSTMATCH module=hstp_trans_main.prx start=0x0006ca68 end=0x0006cb54 symbol=FUN_0006ca68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed floating record members as float while preserving adjacent integer fields; exact match verified; names and types await human review. */
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

extern undefined4 * FUN_0004c898();
extern undefined4 * FUN_0005931c();

undefined4 * FUN_0006ca68(undefined4 *param_1,undefined4 *param_2)
{
  *param_1 = *param_2;
  FUN_0005931c(param_1 + 4,param_2 + 4);
  FUN_0004c898(param_1 + 0x14,param_2 + 0x14);
  FUN_0004c898(param_1 + 0x18,param_2 + 0x18);
  ((float *)param_1)[0x1c] = ((float *)param_2)[0x1c];
  ((float *)param_1)[0x1d] = ((float *)param_2)[0x1d];
  ((float *)param_1)[0x1e] = ((float *)param_2)[0x1e];
  param_1[0x1f] = param_2[0x1f];
  param_1[0x20] = param_2[0x20];
  ((float *)param_1)[0x21] = ((float *)param_2)[0x21];
  ((float *)param_1)[0x22] = ((float *)param_2)[0x22];
  ((float *)param_1)[0x23] = ((float *)param_2)[0x23];
  ((float *)param_1)[0x24] = ((float *)param_2)[0x24];
  ((float *)param_1)[0x25] = ((float *)param_2)[0x25];
  ((float *)param_1)[0x26] = ((float *)param_2)[0x26];
  ((float *)param_1)[0x27] = ((float *)param_2)[0x27];
  ((float *)param_1)[0x28] = ((float *)param_2)[0x28];
  *(undefined1 *)(param_1 + 0x29) = *(undefined1 *)(param_2 + 0x29);
  *(undefined1 *)((int)param_1 + 0xa5) = *(undefined1 *)((int)param_2 + 0xa5);
  *(undefined1 *)((int)param_1 + 0xa6) = *(undefined1 *)((int)param_2 + 0xa6);
  *(undefined1 *)((int)param_1 + 0xa7) = *(undefined1 *)((int)param_2 + 0xa7);
  *(undefined1 *)(param_1 + 0x2a) = *(undefined1 *)(param_2 + 0x2a);
  return param_1;
}
