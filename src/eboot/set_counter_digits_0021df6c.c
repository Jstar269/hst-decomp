/* HSTMATCH module=EBOOT.BIN start=0x0021df6c end=0x0021e090 symbol=FUN_0021df6c lang=c99 */
/* Clone of src/sharing_main/set_counter_digits_0022d4e0.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Twin of EBOOT 0x21df6c. Updates three two-digit counters: stores value + 1 unless n is -1, then for each
   counter shows the tens sprite (hidden for the selected one once the value reaches 10) and sets the
   tens/ones sprite cells from the per-counter base table DAT_002f0694 (72-byte rows); n == -1 shows the
   tens sprite and the ones cell base + 10. Both cell fields are written through one inline helper, so
   the sprite pointer is loaded once. Names provisional. */
typedef struct Spr {
  char pad[0x24];
  int f24;
  int f28;
} Spr;

static inline void SetCell(Spr *s, int v)
{
  s->f24 = v;
  s->f28 = v;
}

typedef struct Digit {
  Spr *tens;
  Spr *ones;
  char pad[0x10];
} Digit;

typedef struct Self {
  char pad[0x60];
  Digit digit[3];
  char pad1[0x1c8 - 0xa8];
  int sel;
  int value;
} Self;

typedef struct Base {
  int pad[2];
  int tens;
  int pad1[2];
  int ones;
  int pad2[12];
} Base;

extern Base DAT_002f0694[];
extern void FUN_000ffb3c(void *, int);

void FUN_0021df6c(Self *self, int n)
{
  int i;

  if (n != -1) self->value = n + 1;
  for (i = 0; i < 3; i++) {
    if (n == -1) {
      FUN_000ffb3c(self->digit[i].tens, 1);
      SetCell(self->digit[i].ones, DAT_002f0694[i].ones + 10);
    } else {
      FUN_000ffb3c(self->digit[i].tens, self->value < 10 || i != self->sel);
      SetCell(self->digit[i].tens, self->value / 10 + DAT_002f0694[i].tens);
      SetCell(self->digit[i].ones, self->value % 10 + DAT_002f0694[i].ones);
    }
  }
}
