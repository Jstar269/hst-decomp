/* HSTMATCH module=EBOOT.BIN start=0x00069c5c end=0x00069d48 symbol=FUN_00069c5c lang=c99 */
/* Clone of src/sharing_main/record_copy_0006b16c.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v10) corrected by hand: typed floating record members as float while preserving adjacent integer fields; exact match verified; names and types await human review. */
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

extern undefined4 * FUN_0004c644();
extern undefined4 * FUN_00058694();

undefined4 * FUN_00069c5c(undefined4 *param_1,undefined4 *param_2,char *param_3)
{
  *param_1 = *param_2;
  FUN_00058694(param_1 + 4,param_3);
  FUN_0004c644(param_1 + 0x14,param_3 + 0x40);
  FUN_0004c644(param_1 + 0x18,param_3 + 0x50);
  ((float *)param_1)[0x1c] = *(float *)(param_3 + 0x60);
  ((float *)param_1)[0x1d] = *(float *)(param_3 + 100);
  ((float *)param_1)[0x1e] = *(float *)(param_3 + 0x68);
  param_1[0x1f] = *(undefined4 *)(param_3 + 0x6c);
  param_1[0x20] = *(undefined4 *)(param_3 + 0x70);
  ((float *)param_1)[0x21] = *(float *)(param_3 + 0x74);
  ((float *)param_1)[0x22] = *(float *)(param_3 + 0x78);
  ((float *)param_1)[0x23] = *(float *)(param_3 + 0x7c);
  ((float *)param_1)[0x24] = *(float *)(param_3 + 0x80);
  ((float *)param_1)[0x25] = *(float *)(param_3 + 0x84);
  ((float *)param_1)[0x26] = *(float *)(param_3 + 0x88);
  ((float *)param_1)[0x27] = *(float *)(param_3 + 0x8c);
  ((float *)param_1)[0x28] = *(float *)(param_3 + 0x90);
  *(undefined1 *)(param_1 + 0x29) = *(undefined1 *)(param_3 + 0x94);
  *(undefined1 *)((int)param_1 + 0xa5) = *(undefined1 *)(param_3 + 0x95);
  *(undefined1 *)((int)param_1 + 0xa6) = *(undefined1 *)(param_3 + 0x96);
  *(undefined1 *)((int)param_1 + 0xa7) = *(undefined1 *)(param_3 + 0x97);
  *(undefined1 *)(param_1 + 0x2a) = *(undefined1 *)(param_3 + 0x98);
  return param_1;
}
