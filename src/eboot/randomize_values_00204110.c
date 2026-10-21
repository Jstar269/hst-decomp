/* HSTMATCH module=EBOOT.BIN start=0x00204110 end=0x002041e8 symbol=FUN_00204110 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned int DAT_002ef1d0;
extern unsigned int DAT_002ef1d4;
extern unsigned int FUN_0001342c(void);
typedef struct Data { char pad[0xf8]; int count; float values[64]; } Data;
void FUN_00204110(Data *object)
{
  int i;
  DAT_002ef1d0 = 0x3f800000;
  DAT_002ef1d4 = 0x3f800000;
  for (i = 0; i < object->count; i++) {
    int random = FUN_0001342c();
    float current = object->values[i] + (float)(random % 11 - 5) / 100.0f;
    object->values[i] = current;
    if (current < 0.25f) {
      object->values[i] = 0.25f;
    } else if (current > 1.0f) {
      object->values[i] = 1.0f;
    }
  }
}
