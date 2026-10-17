/* HSTMATCH module=hstp_trans_main.prx start=0x00059a00 end=0x00059ac0 symbol=FUN_00059a00 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Object {
  char pad_0[0x8c];
  int state;
  char pad_90[0xdc];
  float *values;
} Object;

extern int FUN_0002fe30(int);

int FUN_00059a00(int object, float *out, int index)
{
  float *destination = out;
  int item_index = index;
  if (*(int *)(object + 0x8c) != 0) {
    Object *self = (Object *)object;
    if (self->values != 0) {
      int value = *(int *)(*(int *)(object + 0x8c) + 8);
      int count;
      if (value != 0) count = FUN_0002fe30(value);
      else count = 0;
      if (item_index < 0 || item_index >= count) goto default_values;
      {
        float *source = self->values + item_index * 4;
        destination[0] = source[0];
        destination[1] = source[1];
        destination[2] = source[2];
        destination[3] = source[3];
      }
      return 1;
    }
  }
default_values:
  destination[0] = 1.0f;
  destination[1] = 1.0f;
  destination[2] = 1.0f;
  destination[3] = 0.0f;
  return 0;
}
