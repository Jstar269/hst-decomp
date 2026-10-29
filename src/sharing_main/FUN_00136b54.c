/* HSTMATCH module=hstp_trans_main.prx start=0x00136b54 end=0x00136b90 symbol=FUN_00136b54 lang=c99 */
/* Clone of src/eboot/FUN_0012b6e8.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
extern float DAT_00381ac0; /* lower bound */

typedef struct FloatHolder {
  char pad00[0x400];
  float value;              /* 0x400 */
} FloatHolder;

/* Stores `value`, raised to the lower bound when below it. */
void FUN_00136b54(float value,FloatHolder *self)
{
  float *chosen;
  float valueCopy;
  
  valueCopy = value;
  if (value < DAT_00381ac0) {
    chosen = &DAT_00381ac0;
  }
  else {
    chosen = &valueCopy;
  }
  self->value = *chosen;
  return;
}
