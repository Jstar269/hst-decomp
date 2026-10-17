/* HSTMATCH module=hstp_trans_main.prx start=0x002bf498 end=0x002bf548 symbol=FUN_002bf498 lang=c++ */
/* Clone of src/eboot/find_fixed_point_segment_002afa48.cpp (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the table cursor and comparison, preserved the fixed-point value types, and reversed the zero-flag arm; exact match verified; names and types await human review. */
#pragma inline_depth(8)
struct Less { int operator()(int a, int b) const { return a < b; } };
extern unsigned char *DAT_003f4914;
extern "C" void FUN_002bf498(int *out_index, float *out_value, int input)
{
  int *cursor;
  int index;
  int value;
  if (DAT_003f4914 != 0) {
    if (out_index != 0) *out_index = 0;
    if (out_value != 0) *out_value = 0.0f;
    index = 0x1d;
    cursor = (int *)(DAT_003f4914 + 0xe8);
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

