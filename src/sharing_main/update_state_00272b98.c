/* HSTMATCH module=hstp_trans_main.prx start=0x00272b98 end=0x00272c44 symbol=FUN_00272b98 lang=c99 */
/* Clone of src/eboot/update_state_00261d70.c (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00108558();

typedef struct Entry {
  char pad0[0x20];
  char sub[0x60];
  float f80;
  char pad84[0x6c];
} Entry;

typedef struct Self {
  Entry e[3];
  char pad2d0[8];
  int count;
} Self;

void FUN_00272b98(Self *self)
{
  unsigned int i;
  Entry *p;

  i = 0;
  p = self->e;
  do {
    if ((int)i >= 1 && self->count < 2) goto next;
    if ((int)i >= 2 && self->count < 4) goto next;
    p->f80 += -p->f80 * 0.5f;
    FUN_00108558(p->sub);
next:
    p++;
  } while (++i < 3);
  self->count = self->count + 1;
}
