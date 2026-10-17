/* HSTMATCH module=EBOOT.BIN start=0x00096e18 end=0x00097110 symbol=FUN_00096e18 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* The recursion MWCC unrolled 7 levels deep is spelled out as static inline levels W1..W7 (inline_depth 8), each with its own loop index and child node. */
#pragma inline_depth(8)
typedef struct Node Node;

extern void FUN_0001f20c(Node *, int, int);
extern int FUN_0001f2f8(Node *);
extern Node *FUN_0001f300(Node *, int);
extern void FUN_00096e18(Node *, int);

static inline void W7(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001f20c(n, 2, arg);
  for (i = 0; i < FUN_0001f2f8(n); i++) {
    c = FUN_0001f300(n, i);
    FUN_00096e18(c, arg);
  }
}

static inline void W6(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001f20c(n, 2, arg);
  for (i = 0; i < FUN_0001f2f8(n); i++) {
    c = FUN_0001f300(n, i);
    W7(c, arg);
  }
}

static inline void W5(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001f20c(n, 2, arg);
  for (i = 0; i < FUN_0001f2f8(n); i++) {
    c = FUN_0001f300(n, i);
    W6(c, arg);
  }
}

static inline void W4(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001f20c(n, 2, arg);
  for (i = 0; i < FUN_0001f2f8(n); i++) {
    c = FUN_0001f300(n, i);
    W5(c, arg);
  }
}

static inline void W3(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001f20c(n, 2, arg);
  for (i = 0; i < FUN_0001f2f8(n); i++) {
    c = FUN_0001f300(n, i);
    W4(c, arg);
  }
}

static inline void W2(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001f20c(n, 2, arg);
  for (i = 0; i < FUN_0001f2f8(n); i++) {
    c = FUN_0001f300(n, i);
    W3(c, arg);
  }
}

static inline void W1(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001f20c(n, 2, arg);
  for (i = 0; i < FUN_0001f2f8(n); i++) {
    c = FUN_0001f300(n, i);
    W2(c, arg);
  }
}

void FUN_00096e18(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001f20c(n, 2, arg);
  for (i = 0; i < FUN_0001f2f8(n); i++) {
    c = FUN_0001f300(n, i);
    W1(c, arg);
  }
}

