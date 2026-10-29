/* HSTMATCH module=EBOOT.BIN start=0x000d8160 end=0x000d8228 symbol=FUN_000d8160 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#define VALUE_COUNT 5 /* entries clamped in the values array */

extern int DAT_0034a77c;
extern void FUN_000d7eb8(void);
extern int FUN_0024de88(int, int, unsigned char);

typedef struct Selector {
  char pad0[0x67];
  char key;          /* 0x67 argument passed to the lookup */
} Selector;

/* Pick a mode 0..3 from three lookups (checked in order 12, 7, 2), then clamp every entry of values to at most that mode. */
void FUN_000d8160(Selector *self, int *values)
{
  int mode;
  int i;
  int *p;
  FUN_000d7eb8();
  mode = 0;
  if (FUN_0024de88(DAT_0034a77c, 12, (unsigned char)self->key) != 0) {
    mode = 3;
    goto scan;
  }
  if (FUN_0024de88(DAT_0034a77c, 7, (unsigned char)self->key) != 0) {
    mode = 2;
    goto scan;
  }
  if (FUN_0024de88(DAT_0034a77c, 2, (unsigned char)self->key) != 0)
    mode = 1;
scan:
  i = 0;
  p = values;
  do {
    int v = *p;
    v = mode < v ? mode : v;
    *p = v;
    ++i;
    ++p;
  } while (i < VALUE_COUNT);
}
