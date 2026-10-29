/* HSTMATCH module=hstp_trans_main.prx start=0x002b0188 end=0x002b0194 symbol=FUN_002b0188 lang=c99 */
/* Clone of src/eboot/FUN_002a0d7c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
typedef struct FloatPairHolder {
  char pad[0x13c];
  float unk13c;  /* 0x13c */
  float unk140;  /* 0x140 */
} FloatPairHolder;

void FUN_002b0188(float a,float b,FloatPairHolder *self)
{
  self->unk13c = a;
  self->unk140 = b;
}
