/* HSTMATCH module=hstp_trans_main.prx start=0x000bfe40 end=0x000c012c symbol=FUN_000bfe40 lang=c99 */
typedef struct { char c[6]; } Str6;
typedef struct { Str6 name; unsigned char used; } Slot;
typedef struct {
  char pad[0x38];
  Str6 key;
  char pad1[0x58 - 0x3e];
  Slot slots[16];
  int vals[16];
  char pad2[0x190 - 0x108];
  int count;
  int pad3;
  int found;
  char pad4[0x21c - 0x19c];
  unsigned char flags[16];
} Obj;
typedef struct { int f0, f1, f2, f3, f4; } Hdr;
typedef struct { int f0, f1, f2; unsigned char f3; } Item;
extern Str6 DAT_003e1dfc;
extern char DAT_0037bd0c[];
extern int FUN_0001100c(void *, void *, int);
extern void *FUN_00011090(void *, void *, int);
extern void FUN_000bd6f0(char *);
extern void FUN_000becfc(Obj *, Item *, int, int, int);

void FUN_000bfe40(Obj *o, char *src)
{
  int i;
  Hdr h;
  Item it;
  for (i = 0; i < 16; i++) {
    o->slots[i].name = DAT_003e1dfc;
    o->slots[i].used = 0;
    o->vals[i] = 0;
  }
  h.f0 = 0;
  FUN_00011090(&h, src, 20);
  src += 20;
  if (h.f1 == h.f4 * 16 + 20) FUN_000bd6f0(DAT_0037bd0c);
  o->count = h.f4;
  for (i = 0; i < h.f4; i++) {
    FUN_00011090(&it, src, 16);
    src += 16;
    FUN_000becfc(o, &it, 0, 0, it.f2);
    o->flags[i] = it.f3;
  }
  {
    char *key = (char *)o + 0x38;
    int n = 0;
    unsigned char *p = (unsigned char *)o;
    do {
      if (p[0x5e] != 0 && FUN_0001100c(p + 0x58, key, 6) == 0) {
        o->found = n;
        return;
      }
      n++;
      p += 7;
    } while (n < 16);
    n = -1;
    o->found = n;
  }
}
// Near miss, 2 words differ (from try/agent-snSB-00/c_bfe40.c, hand-written): everything matches (16-iteration init loop unrolled 8x by the compiler with 6-byte struct copies, hoisted `key` in s3, char-pointer search loop with unsigned char p, index in s2 / cursor in s0) except the final
//   retail: li s2,-1 ; sw s2,408(s1)        ours: li v1,-1 ; sw v1,408(s1)
// i.e. retail keeps the -1 in the loop counter's register. Ruled out: `n = -1; o->found = n;`, `o->found = (n = -1)`, inline SetFound(o,-1), `n = n - 17` (compiler knows n == 16), `~0`, unsigned n, a separate `last = -1`,
// sharing the earlier `i` for the search counter (swaps s0/s2), all 6 declaration orders of key/p/i, goto-merged single store (gets li s2,-1 but lays out `beqzl v0,END; sw` instead of retail's `bnez v0; nop; b END; sw`).
