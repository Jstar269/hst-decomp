/* HSTMATCH module=EBOOT.BIN start=0x000008d8 end=0x000009e4 symbol=FUN_000008d8 lang=c */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); names and types await human review. */

typedef void (*ElemFn)(void *elem, int mode);

struct Walker {
  char *base;
  int stride;
  unsigned count;
  ElemFn dtor;
  unsigned i;
};

static void Touch(struct Walker *w);

char *FUN_000008d8(char *self, ElemFn ctor, ElemFn dtor, int stride, unsigned count)
{
  struct Walker w;
  char *base;
  char *p;

  Touch(&w);

  if (self) {
    *(int *)(self + 0) = stride;
    *(int *)(self + 4) = count;
    *(ElemFn *)(self + 8) = dtor;
    base = self + 16;
    if (ctor) {
      w.dtor = dtor;
      w.base = base;
      w.stride = stride;
      w.count = count;
      w.i = 0;
      if (w.i < count) {
        p = w.base;
        do {
          ctor(p, 1);
          p += stride;
        } while (++w.i < count);
      }
      if (w.i < w.count) {
        if (w.dtor) {
          p = w.base + w.stride * w.i;
          if (w.i) {
            do {
              p -= w.stride;
              w.dtor(p, -1);
            } while (--w.i);
          }
        }
        return 0;
      }
      return base;
    }
  }
  return 0;
}

static void Touch(struct Walker *w)
{
}

/* Lane dsn2 shape map (best of 5 compiles; 75 words vs retail 67, 68 differing; shape right, 8 words over).
   What matches: frame 64 layout exactly (8-byte outgoing area, 6 saved regs ra/s4/s3/s2/s1/s0, 20-byte walker
   block at the frame top), the {base,stride,count,dtor,i} local block, the entry guard, the do/while with ++w.i,
   all four struct stores in retail's order (dtor, base, stride, count), the post-check reload of w.count, the
   rollback arithmetic (base + stride*i, countdown on w.i) and the shared `return 0` block.
   What does not: retail's walker fields are FRAME-RESIDENT (lw/sw sp-relative, count cached in s2 for the loop
   test but reloaded after the callbacks), which only happens when the struct's address escapes to an out-of-line
   callee (Touch(&w) here) - and that call costs retail-invisible words (jal + arg setup). An INLINED escape
   (walker_init(&w, ...)) loses the residency completely: MWCC promotes the struct to registers, frame 32, 7
   saved regs, no sp-relative fields. The real source must have had a zero-cost escape; not found in 5 compiles.
   Also still off: i=0 is stored in the branch delay slot here, retail stores it before the branch; the loop wants
   `lw; addiu a0,v0,1; sltu; bnez; sw` (i's store in the delay slot, counter in a0) where we emit `lw; addiu v0;
   sw; sltu; bnez`.
   Next steps: (1) find the zero-cost address escape (candidate: an aggregate/designated initializer that keeps
   the struct an object, or a pointer that is stored into a frame word retail seems to leave unused at sp+0x20..0x2c);
   (2) if the escape can be removed, re-tune the store order and the loop's store placement. */
// near miss from lane dsn2 (unreviewed)
