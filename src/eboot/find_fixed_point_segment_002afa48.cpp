/* HSTMATCH module=EBOOT.BIN start=0x002afa48 end=0x002afaf8 symbol=FUN_002afa48 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the table cursor and comparison, preserved the fixed-point value types, and reversed the zero-flag arm; exact match verified; names and types await human review. */
#pragma inline_depth(8)
struct Less { int operator()(int a, int b) const { return a < b; } };
extern unsigned char *DAT_0034b5d4;
extern "C" void FUN_002afa48(int *out_index, float *out_value, int input)
{
  int *cursor;
  int index;
  int value;
  if (DAT_0034b5d4 != 0) {
    if (out_index != 0) *out_index = 0;
    if (out_value != 0) *out_value = 0.0f;
    index = 0x1d;
    cursor = (int *)(DAT_0034b5d4 + 0xe8);
    do {
      value = *cursor >> 4;
      if (Less()(input, value) == 0) {
        if (out_index != 0) *out_index = index;
        if (out_value == 0) return;
        if (index == 0x1d) {
          *out_value = 1.0f;
          return;
        }
        *out_value = (float)(input - value) / (float)((cursor[2] >> 4) - value);
        return;
      }
      --index;
      cursor -= 2;
    } while (index >= 0);
  }
}

