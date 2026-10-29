/* HSTMATCH module=hstp_trans_main.prx start=0x00209384 end=0x00209394 symbol=FUN_00209384 lang=c99 */
/* Clone of src/eboot/FUN_001fac6c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

typedef struct CounterObj {
  char pad00[0x135c];
  int counter;       /* 0x135c */
} CounterObj;

/* Increments the counter. */
void FUN_00209384(CounterObj *self)
{
  self->counter = self->counter + 1;
}
