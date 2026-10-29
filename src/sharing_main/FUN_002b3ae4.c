/* HSTMATCH module=hstp_trans_main.prx start=0x002b3ae4 end=0x002b3aec symbol=FUN_002b3ae4 lang=c99 */
/* Clone of src/eboot/FUN_002a43cc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
typedef struct FloatHolder {
  char pad00[0x20];
  float value;            /* 0x20 */
} FloatHolder;

float FUN_002b3ae4(FloatHolder *self)
{
  return self->value;
}
