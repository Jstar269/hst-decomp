/* HSTMATCH module=hstp_trans_main.prx start=0x000fbe24 end=0x000fbe68 symbol=FUN_000fbe24 lang=c99 */
/* Clone of src/eboot/FUN_000f6730.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00108e6c(float, int);

typedef struct ValueHolder {
  int target;     /* 0x0 object told the new value (may be 0) */
  char pad4[0xc];
  int value;      /* 0x10 */
} ValueHolder;

/* Store value; if there is a target, pass it the value as a float first. */
void FUN_000fbe24(ValueHolder *self,int value)
{
  if (self->target != 0) {
    FUN_00108e6c((float)((float)value),(int)(self->target));
  }
  self->value = value;
}
