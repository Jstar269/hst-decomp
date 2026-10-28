/* HSTMATCH module=EBOOT.BIN start=0x0001b584 end=0x0001b6b0 symbol=FUN_0001b584 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); names and types await human review. */
extern "C" int DAT_002cfae8[8];
extern "C" void *FUN_00000a90(int);
extern "C" void *FUN_000008d8(void *, void *, int, int, int);
extern "C" void FUN_0001b6c4(int *, int *);
extern "C" void LAB_0001b6b0();

struct Pool {
  void *buf;    /* 0 */
  int count;    /* 4 */
};

struct Elem {
  int f[4];     /* 16 bytes */
};

struct ElemList {
  Elem *first;  /* 0 */
  int count;    /* 4 */
};

extern "C" int *FUN_0001b584(Pool *pool, ElemList *src)
{
  int count = src->count;
  int i;
  for (i = 0; i < 8; i++) {
    if (count + 200 < DAT_002cfae8[i]) break;
  }
  int size = (i < 8) ? DAT_002cfae8[i] : 0xc005;
  for (i = 0; i < 8; i++) {
    if (size < DAT_002cfae8[i]) break;
  }
  size = (i < 8) ? DAT_002cfae8[i] : 0xc005;
  pool->count = size;
  void *p = FUN_00000a90(size * 8 + 0x10);
  p = FUN_000008d8(p, (void *)&LAB_0001b6b0, 0, 8, size);
  pool->buf = p;
  for (int k = 0; k < count; k++) {
    FUN_0001b6c4((int *)pool, (int *)&src->first[k]);
  }
  return (int *)pool;
}

/* PARK NOTES (lane dsn2 session 6, 5 compiles; the file above is the ternary attempt at 81/75 - the best
   SEMANTICALLY complete shape is the goto variant at 77/75, and the closest in length was the plain
   `int size = 0xc005;` + break form at 76/75, which however never runs a second fallback).
   Cracked pieces (from the batch's own pseudocode file ram-0x0001b584.c):
     - two 8-entry scans over the int table DAT_002cfae8 (0x002cfae8): first finds the entry above
       count+200, second the entry above the first result; each falls back to 0xc005 on the not-found path;
     - pool->count (+4) = size; p = FUN_00000a90(size*8 + 0x10); p = FUN_000008d8(p, &LAB_0001b6b0, 0, 8, size)
       (FUN_000008d8 is the pool-create parked at wip/FUN_000008d8_near.c: (self, ctor, dtor, stride, count));
       pool->buf (+0) = p; then a per-element FUN_0001b6c4(pool, elem) over `count` entries of 16 bytes.
   REMAINING DELTAS: (a) the not-found/ternary exit shape - retail loads tbl[i] unconditionally then tests
   `i < 8` (slti) and overwrites with 0xc005 on the not-found path, which our ternary does too but at +6 words,
   while the goto and plain-init forms land at 77 and 76; (b) the final loop: retail keeps ONE induction
   variable (s3) and recomputes `k*16` with `sll v1,s3,0x4` per iteration, ours strength-reduces to a second
   accumulator (s4) and an extra save/restore pair - expressing the element as a 16-byte struct member
   (`&src->first[k]`) did not stop the reduction (that IS the ternary file above).
   Next step: try the first-loop body with the load-then-test order spelled as an explicit
   `int v = DAT_002cfae8[i]; if (count + 200 < v) ...` and the second loop's result carried in a SECOND
   variable, which is what retail's register pattern (a1 -> s3) suggests. */
// near miss from lane dsn2 (unreviewed)
