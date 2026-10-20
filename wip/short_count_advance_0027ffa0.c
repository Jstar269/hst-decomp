/* HSTMATCH module=EBOOT.BIN start=0x0027ffa0 end=0x0028007c symbol=FUN_0027ffa0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  int f0;
  short s4;
  short s6;
  short s8;
} Node;

typedef struct {
  Node *node;
  short pos;
  short pad;
  unsigned int count;
  unsigned char flag;
} Obj;

extern unsigned char DAT_002caa90[];

void FUN_0027ffa0(Obj *o, float scale)
{
  if (o->count >= 21) {
    Node *n = o->node;
    short v = o->pos;
    short old = n->s4;
    n->s4 = v;
    n->s8 += (short)(v - old);
  }
  else {
    short d = (short)((float)DAT_002caa90[o->count % 21] * scale);
    Node *n;
    short old;
    short v;
    d = o->flag ? (short)-d : d;
    v = (short)(o->pos + d);
    n = o->node;
    old = n->s4;
    n->s4 = o->pos + d;
    n->s8 += (short)(v - old);
    o->count++;
  }
}

// NEAR MISS: same instruction set (one extra word: a `seh` copy before the `negu`), 24 of 55 words
// differ because of two register-permutation groups: (a) the flag negate emits
// `seh v1,a1; negu v1,v1` where retail has `negu v1,a1`; (b) the else block keeps `o` in a0 and puts
// the position in a2 where this source reuses a0 for it (and `s8`/delta swap a0/v1). Tried: forward
// branch order without the swap (worse), `d = (short)-d` / `(short)(0-d)` / ternary negate, `int v`,
// `n->s8 += (short)(v - old)` vs a `delta` local, reading `o->pos` twice. The block layout itself
// (`bnezl` to the scale block, count>=21 in the fall-through) is the reversed if/else.
// near miss from lane ds7 (unreviewed)
