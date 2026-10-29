/* HSTMATCH module=hstp_trans_main.prx start=0x002be960 end=0x002be968 symbol=FUN_002be960 lang=c99 */
/* Clone of src/eboot/FUN_002af0dc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
typedef struct FloatAt68 {
  char pad00[0x68];
  float value;          /* 0x68 */
} FloatAt68;

/* Getter for the float at +0x68. */
float FUN_002be960(FloatAt68 *self)
{
  return self->value;
}
