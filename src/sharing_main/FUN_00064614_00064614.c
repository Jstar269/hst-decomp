/* HSTMATCH module=hstp_trans_main.prx start=0x00064614 end=0x000646b4 symbol=FUN_00064614 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  char pad0[12];
  float value;
  int marker;
  char pad1[60];
  unsigned char active;
  unsigned char blocked;
  unsigned char enabled;
  unsigned char pending;
} State;
void FUN_00064614(State *p)
{
  int active;
  int changed;
  float f;
  active = p->enabled != 0;
  if (active) active = (p->blocked != 0) ^ 1;
  if (active && p->active == 0) {
    f = p->value;
    changed = 0;
    if (!(f < 0.0f)) {
      if (f > 1.0f) {
        changed = 1;
        p->value = f - 1.0f;
      } else {
        p->value = 0.0f;
        p->marker = (int)0xbf800000;
      }
    }
    if (!changed && p->pending != 0) {
      p->value = 0.0f;
      p->enabled = 0;
      p->pending = 0;
    }
  }
}