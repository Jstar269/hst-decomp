/* HSTMATCH module=EBOOT.BIN start=0x00060984 end=0x000609f8 symbol=FUN_00060984 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies the twelve transform floats of the source object into the twelve float slots at +0x1d0 of the
   destination (the global at 0x3313c4 when no destination is given). Names provisional. */
typedef struct {
  char pad0[0x20];
  float f20, f24, f28, f2C, f30, f34, f38, f3C, f40, f44, f48, f4C;
} Src;
typedef struct {
  char pad0[0x1d0];
  float f1D0, f1D4, f1D8, f1DC, f1E0, f1E4, f1E8, f1EC, f1F0, f1F4, f1F8, f1FC;
} Dst;
extern Dst *DAT_003313c4;

void FUN_00060984(Src *s, Dst *d)
{
  if (d == 0) {
    d = DAT_003313c4;
  }
  d->f1E0 = s->f30;
  d->f1E4 = s->f34;
  d->f1E8 = s->f38;
  d->f1EC = s->f3C;
  d->f1F0 = s->f20;
  d->f1F4 = s->f24;
  d->f1F8 = s->f28;
  d->f1FC = s->f2C;
  d->f1D0 = s->f40;
  d->f1D4 = s->f44;
  d->f1D8 = s->f48;
  d->f1DC = s->f4C;
}
