/* HSTMATCH module=EBOOT.BIN start=0x001b6db0 end=0x001b6e14 symbol=FUN_001b6db0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restructured with a typed list node/self struct and typed callee arguments (fixes the argument-setup order); exact match verified; names and types await human review. */
typedef struct Node { struct Node *prev; struct Node *next; int val; } Node;
typedef struct Self {
  char pad0[0x3c];
  int f3c;
  int f40;
  char pad1[0xf4 - 0x44];
  Node head;
} Self;

extern int FUN_001b9608(char *, int *, int **, int *);

void FUN_001b6db0(Self *self)
{
  Node *n;
  char buf[8];
  int *p;

  n = self->head.next;
  if (n != &self->head) {
    do {
      p = &self->f40;
      FUN_001b9608(buf, &self->f3c, &p, &n->val);
      n = n->next;
    } while (n != &self->head);
  }
}
