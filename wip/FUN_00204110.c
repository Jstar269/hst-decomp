/* HSTMATCH module=EBOOT.BIN start=0x00204110 end=0x002041e8 symbol=FUN_00204110 lang=c99 */
extern unsigned int DAT_002ef1d0;
extern unsigned int DAT_002ef1d4;
extern unsigned int FUN_0001342c(void);
typedef struct Data { char pad[0xf8]; int count; float values[64]; } Data;
void FUN_00204110(Data *object)
{
  Data *self = object;
  int i;
  int count;
  char *cursor;
  DAT_002ef1d0 = 0x3f800000;
  DAT_002ef1d4 = 0x3f800000;
  count = self->count;
  if (count <= 0) return;
  i = 0;
  cursor = (char *)self;
  do {
    int random = FUN_0001342c();
    float current = *(float *)(cursor + 0xfc) + (float)(random % 11 - 5) / 100.0f;
    *(float *)(cursor + 0xfc) = current;
    if (current < 0.25f) {
      *(float *)(cursor + 0xfc) = 0.25f;
    } else if (current > 1.0f) {
      *(float *)(cursor + 0xfc) = 1.0f;
    }
    i++;
    cursor += 4;
  } while (i < self->count);
}
// Near miss: two words at +0x2c differ. Retail moves object into s2 before BLEZ; GCC emits that move in the BLEZ delay slot. The float clamp, indexed stores, loop tail, and epilogue match.
// near miss from lane u6cr3-0 (unreviewed)
