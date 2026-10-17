/* HSTMATCH module=hstp_trans_main.prx start=0x00124158 end=0x00124214 symbol=FUN_00124158 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { char pad[8]; float v; } Inner;
typedef struct { Inner *inner; } Holder;
typedef struct {
  int pad0;
  Holder *h;
  int pad1[3];
  float limit;
  char pad2[28];
} Entry;
typedef struct {
  char pad0[0xf0];
  Entry entries[2];
  int first;
  int last;
} Sub;
typedef struct {
  char pad0[0x48];
  Sub *slots[27];
  unsigned char flags[27];
} Obj;

static inline int LimitsOk(Sub *s)
{
  int j;
  for (j = s->first; j <= s->last; j++) {
    Holder *h = s->entries[j].h;
    float lim = h ? h->inner->v : 0.0f;
    if (s->entries[j].limit < lim) {
      return 0;
    }
  }
  return 1;
}

int FUN_00124158(Obj *self)
{
  int i;
  for (i = 0; i < 27; i++) {
    if (self->flags[i] != 0) {
      if (!LimitsOk(self->slots[i])) return 0;
    }
  }
  return 1;
}
