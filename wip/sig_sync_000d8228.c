/* HSTMATCH module=EBOOT.BIN start=0x000d8228 end=0x000d8334 symbol=FUN_000d8228 lang=c99 */

struct Obj {
  short src[6];
  char pad[0x67 - 0x0c];
  unsigned char key;
  char pad2[0xa4 - 0x68];
  int out[5];
  short sig_lo;
  short sig_hi;
  short cur[6];
};

extern char DAT_002d688c[];
void FUN_000d8160(struct Obj *, int *);

void FUN_000d8228(struct Obj *self)
{
  int local[5];
  int i;
  int changed;

  changed = *(int *)&self->sig_lo != self->key;
  if (!changed) {
    for (i = 0; i < 6; i++) {
      if (self->cur[i] != self->src[i]) {
        changed = 1;
        break;
      }
    }
  }
  if (changed) {
    for (i = 0; i < 6; i++) {
      self->cur[i] = self->src[i];
    }
    self->sig_lo = -1;
    self->sig_hi = -1;
    for (i = 0; i < 5; i++) {
      self->out[i] = 0;
    }
    *(int *)&self->sig_lo = self->key;
    FUN_000d8160(self, local);
    for (i = 0; i < 5; i++) {
      self->out[i] = *(int *)(DAT_002d688c + i * 4 + local[i] * 0x14);
    }
  }
}
// NEAR 108/67 words (0x000d8228). First draft only: the field offsets are right (src shorts at 0,
// key byte at 0x67, 5-int out table at 0xa4, packed sig at 0xb8 as two shorts, cur[6] at 0xbc) and
// the four phases are in order, but MWCC unrolled the fixed-count loops where retail keeps them as
// counted do/while bodies (each ends with `uVar4++; ... } while (uVar4 < N)`), and the retail code
// reloads `self->key` for the final `*(int *)&sig = key` write. Next pass: write each loop as
// `i = 0; do { ...; i++; } while (i < N);` with the pointer walking (`psVar3++`) rather than
// indexing, and re-check the 0x5e/0x52 short indexing (retail walks a short* upward).
// near miss from lane fm5 (unreviewed)
