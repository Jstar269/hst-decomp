/* HSTMATCH module=hstp_trans_main.prx start=0x000e3f64 end=0x000e3fbc symbol=FUN_000e3f64 lang=c99 */
typedef unsigned int uint;
typedef struct Node { struct Node *p; int n; } Node;
typedef struct Hdr {
  char *self;
  int f4;
  uint size;
  int f12;
  int f16;
  Node *head;
  Node *last;
} Hdr;

void FUN_000e3f64(Hdr *h, uint size)
{
  uint n = (size - 0x18) >> 3;
  Node *first = (Node *)((char *)h + 0x18);
  char *self = (char *)h - 1;
  Node *end = first + n;
  Node *last = end - 1;
  int cnt = n - 1;
  if (((uint)h < 1) | (size < 0x31)) return;
  h->self = self;
  h->size = size;
  h->head = first;
  h->f12 = 0;
  h->last = last;
  first->n = cnt;
  end[-1].p = first;
  last->n = 0;
}

// NEAR MISS (agent snS5-00): 14 words differ, all register numbers/ordering of the straight-line setup (the stores, offsets and
// the delay-slot fill of `addiu t0,a3,-8` already match). Retail interleaves: sub, srl, sll, addiu(first), sltiu(h<1), sltiu(size<49), addu(end),
// addiu(n-1), or, addiu(h-1), bnez, [slot: addiu last] using a3,t3,t0,a2,t4,v0,a3,t1,t3,t2,t0; ours uses v1,a2,t3,... .
// The guard must be `((uint)h < 1) | (size < 0x31)` (a materialised OR; `h == 0` gives xor+sltiu and `||` gives branches).
// Ruled out: all 294 orders of the independent setup statements, declaration order, int/uint types, accessor members, end[-1] vs last->.
