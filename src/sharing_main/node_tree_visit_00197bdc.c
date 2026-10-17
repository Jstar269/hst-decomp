/* HSTMATCH module=hstp_trans_main.prx start=0x00197bdc end=0x00197eec symbol=FUN_00197bdc lang=c99 */
/* Clone of src/eboot/node_tree_visit_0018b490.c (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* The recursion MWCC unrolled 6 levels deep is spelled out as static inline levels W1..W6 (inline_depth 8), each with its own loop index and child node (sibling of 0x96e18, which has 7 levels and one visit call per node). */
#pragma inline_depth(8)
typedef struct Node Node;

extern void FUN_0001ef24(Node *, int, int);
extern int FUN_0001f0f0(Node *);
extern Node *FUN_0001f0f8(Node *, int);
extern void FUN_00197bdc(Node *, int);

static inline void W6(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001ef24(n, 0, arg);
  FUN_0001ef24(n, 2, arg);
  for (i = 0; i < FUN_0001f0f0(n); i++) {
    c = FUN_0001f0f8(n, i);
    FUN_00197bdc(c, arg);
  }
}

static inline void W5(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001ef24(n, 0, arg);
  FUN_0001ef24(n, 2, arg);
  for (i = 0; i < FUN_0001f0f0(n); i++) {
    c = FUN_0001f0f8(n, i);
    W6(c, arg);
  }
}

static inline void W4(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001ef24(n, 0, arg);
  FUN_0001ef24(n, 2, arg);
  for (i = 0; i < FUN_0001f0f0(n); i++) {
    c = FUN_0001f0f8(n, i);
    W5(c, arg);
  }
}

static inline void W3(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001ef24(n, 0, arg);
  FUN_0001ef24(n, 2, arg);
  for (i = 0; i < FUN_0001f0f0(n); i++) {
    c = FUN_0001f0f8(n, i);
    W4(c, arg);
  }
}

static inline void W2(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001ef24(n, 0, arg);
  FUN_0001ef24(n, 2, arg);
  for (i = 0; i < FUN_0001f0f0(n); i++) {
    c = FUN_0001f0f8(n, i);
    W3(c, arg);
  }
}

static inline void W1(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001ef24(n, 0, arg);
  FUN_0001ef24(n, 2, arg);
  for (i = 0; i < FUN_0001f0f0(n); i++) {
    c = FUN_0001f0f8(n, i);
    W2(c, arg);
  }
}

void FUN_00197bdc(Node *n, int arg)
{
  int i;
  Node *c;

  FUN_0001ef24(n, 0, arg);
  FUN_0001ef24(n, 2, arg);
  for (i = 0; i < FUN_0001f0f0(n); i++) {
    c = FUN_0001f0f8(n, i);
    W1(c, arg);
  }
}

