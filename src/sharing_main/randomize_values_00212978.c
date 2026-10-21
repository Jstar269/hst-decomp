/* HSTMATCH module=hstp_trans_main.prx start=0x00212978 end=0x00212a50 symbol=FUN_00212978 lang=c99 */
/* Clone of src/eboot/randomize_values_00204110.c (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned int DAT_00397258;
extern unsigned int DAT_0039725c;
extern unsigned int FUN_0001342c(void);
typedef struct Data { char pad[0xf8]; int count; float values[64]; } Data;
void FUN_00212978(Data *object)
{
  int i;
  DAT_00397258 = 0x3f800000;
  DAT_0039725c = 0x3f800000;
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
