/* HSTMATCH module=EBOOT.BIN start=0x0018b490 end=0x0018b7a0 symbol=FUN_0018b490 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* The recursion MWCC unrolled 6 levels deep is spelled out as static inline levels W1..W6 (inline_depth 8), each with its own loop index and child node (sibling of 0x96e18, which has 7 levels and one visit call per node). */
#pragma inline_depth(8)
typedef struct Node Node;

extern void FUN_0001f20c(Node *, int, int);
extern int FUN_0001f2f8(Node *);
extern Node *FUN_0001f300(Node *, int);
extern void FUN_0018b490(Node *, int);

static inline void W6(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001f20c(n, 0, arg);
  FUN_0001f20c(n, 2, arg);
  for (i = 0; i < FUN_0001f2f8(n); i++) {
    c = FUN_0001f300(n, i);
    FUN_0018b490(c, arg);
  }
}

static inline void W5(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001f20c(n, 0, arg);
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

  FUN_0001f20c(n, 0, arg);
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

  FUN_0001f20c(n, 0, arg);
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

  FUN_0001f20c(n, 0, arg);
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

  FUN_0001f20c(n, 0, arg);
  FUN_0001f20c(n, 2, arg);
  for (i = 0; i < FUN_0001f2f8(n); i++) {
    c = FUN_0001f300(n, i);
    W2(c, arg);
  }
}

void FUN_0018b490(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001f20c(n, 0, arg);
  FUN_0001f20c(n, 2, arg);
  for (i = 0; i < FUN_0001f2f8(n); i++) {
    c = FUN_0001f300(n, i);
    W1(c, arg);
  }
}

