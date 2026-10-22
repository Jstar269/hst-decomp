/* HSTMATCH module=EBOOT.BIN start=0x00057648 end=0x00057730 symbol=FUN_00057648 lang=c++ */
struct Node {
  char pad[0xf0];
  unsigned a;
  char pad2[0x1c];
  unsigned b;
};

struct Obj {
  char pad[0xe0];
  void **items;
  unsigned count;
};

extern "C" void FUN_00057b58(float f, void *obj, int idx, int flag);
extern "C" void FUN_00057bc0(float f1, void *obj, int idx, int flag, float f2, float f3);
extern "C" void FUN_000561d4(void *p, int flag);

extern "C" void FUN_00057648(Obj *self, unsigned idx)
{
  if ((int)idx < 0) {
    return;
  }
  if (idx >= self->count) {
    return;
  } else {
    unsigned i = 0;
    Node *n = (Node *)self;
    do {
      if (n->a == idx) {
        FUN_00057b58(0.0f, self, i, -1);
      }
      if (n->b == idx) {
        FUN_00057bc0(0.0f, self, i, -1, 0.0f, 0.0f);
      }
      i++;
      n = (Node *)((char *)n + 0x34);
    } while (i < 2);
    void *item = self->items[idx];
    if (item != 0 && item != 0) {
      FUN_000561d4(item, 1);
      self->items[idx] = 0;
    }
  }
}
// NEAR MISS: 116/116 words, 16 differ (all in the tail: the index*4 temp and the epilogue).
// Diff: retail computes the array index TWICE (`sll a0,s2,0x2` before the load and again after
//   the call FUN_000561d4) while ours keeps idx*4 in the saved register s0 across the call
//   (`sll s0,s2,0x2` once).  That one extra word shifts our whole epilogue 4 bytes down, so the
//   beqzl target (0x57718 vs 0x57714) and the two beqz targets differ as well.
// Ruled out: the `if (cond) return; else {body}` shape (that one DOES give retail's ra-reload in
//   the beqzl delay slot and the private epilogue entry - keep it), an inline getter for the
//   array, a const getter, a cast to an identical struct, volatile casts on either access, a
//   local array pointer, an index copy, and declaring the item local at the top.
// near miss from lane om1 (unreviewed)
