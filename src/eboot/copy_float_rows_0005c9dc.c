/* HSTMATCH module=EBOOT.BIN start=0x0005c9dc end=0x0005ca5c symbol=FUN_0005c9dc lang=c99 */
/* Clone of src/sharing_main/copy_float_rows_0005d768.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed the copied records as floats and kept both bounds checks independent; exact match verified; names and types await human review. */
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


void FUN_0005c9dc(int param_1, int param_2, float *param_3, float *param_4)
{
  if (param_2 < *(int *)(param_1 + 0x18)) {
    int offset = param_2 * 8;
    float *base = (float *)*(int *)(param_1 + 0x1c);
    float *dest = base + offset;
    dest[0] = param_3[0]; dest[1] = param_3[1];
    dest[2] = param_3[2]; dest[3] = param_3[3];
  }
  if (param_2 < *(int *)(param_1 + 0x18)) {
    int offset = param_2 * 8;
    float *base = (float *)*(int *)(param_1 + 0x1c);
    float *dest = base + offset;
    dest[4] = param_4[0]; dest[5] = param_4[1];
    dest[6] = param_4[2]; dest[7] = param_4[3];
  }
}
