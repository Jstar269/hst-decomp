/* HSTMATCH module=EBOOT.BIN start=0x00222098 end=0x00222134 symbol=FUN_00222098 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: supplied missing sub->fc float argument to FUN_000ee088, corrected byte flag type and float compare polarity; exact match verified; names and types await human review. */

typedef struct Sub {
  char pad[8];
  int f8;
  int fc;
} Sub;

extern void FUN_000ee088(float, float, float, float, float, float, float, float, float, Sub *, int);

void FUN_00222098(char *param_1)
{
  int i = 0;
  char *p = param_1;
  do {
    if (*(unsigned char *)(p + 0x20) != 0 && *(float *)(p + 0x2c) > 0.0f) {
      Sub *sub = *(Sub **)(p + 0x24);
      FUN_000ee088((float)*(int *)(p + 0x38), (float)*(int *)(p + 0x3c), *(float *)(p + 0x2c), *(float *)(p + 0x34), *(float *)(p + 0x30), 0.0f, 0.0f, (float)sub->f8, (float)sub->fc, sub, 0xffff);
    }
    i++;
    p += 0x30;
  } while (i < 16);
}
