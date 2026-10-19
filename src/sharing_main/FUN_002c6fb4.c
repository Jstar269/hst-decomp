/* HSTMATCH module=hstp_trans_main.prx start=0x002c6fb4 end=0x002c6ff8 symbol=FUN_002c6fb4 lang=c99 */
/* Clone of src/eboot/FUN_002b7214.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef struct {
  char pad0[4];
  unsigned char *data;
  unsigned count;
} Self;

typedef struct {
  int a;
  signed char flag;
  char pad[3];
} Elem;

Elem *FUN_002c6fb4(Self *self, int idx)
{
  Elem *t;
  Elem *e;

  if (0 <= idx && idx < self->count && (t = (Elem *)(self->data + idx * 8))->flag >= 0)
    e = t;
  else
    e = 0;
  return e;
}
