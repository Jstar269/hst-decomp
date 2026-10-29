/* HSTMATCH module=EBOOT.BIN start=0x00096e18 end=0x00097110 symbol=FUN_00096e18 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* The recursion MWCC unrolled 7 levels deep is spelled out as static inline levels VisitLevel1..VisitLevel7 (inline_depth 8), each with its own loop index and child node. */
#pragma inline_depth(8)
typedef struct Node Node;

extern void FUN_0001f20c(Node *, int, int);
extern int FUN_0001f2f8(Node *);
extern Node *FUN_0001f300(Node *, int);
extern void FUN_00096e18(Node *, int);

static inline void VisitLevel7(Node *node, int arg)
{
  int i;
  Node *child;

  FUN_0001f20c(node, 2, arg);
  for (i = 0; i < FUN_0001f2f8(node); i++) {
    child = FUN_0001f300(node, i);
    FUN_00096e18(child, arg);
  }
}

static inline void VisitLevel6(Node *node, int arg)
{
  int i;
  Node *child;

  FUN_0001f20c(node, 2, arg);
  for (i = 0; i < FUN_0001f2f8(node); i++) {
    child = FUN_0001f300(node, i);
    VisitLevel7(child, arg);
  }
}

static inline void VisitLevel5(Node *node, int arg)
{
  int i;
  Node *child;

  FUN_0001f20c(node, 2, arg);
  for (i = 0; i < FUN_0001f2f8(node); i++) {
    child = FUN_0001f300(node, i);
    VisitLevel6(child, arg);
  }
}

static inline void VisitLevel4(Node *node, int arg)
{
  int i;
  Node *child;

  FUN_0001f20c(node, 2, arg);
  for (i = 0; i < FUN_0001f2f8(node); i++) {
    child = FUN_0001f300(node, i);
    VisitLevel5(child, arg);
  }
}

static inline void VisitLevel3(Node *node, int arg)
{
  int i;
  Node *child;

  FUN_0001f20c(node, 2, arg);
  for (i = 0; i < FUN_0001f2f8(node); i++) {
    child = FUN_0001f300(node, i);
    VisitLevel4(child, arg);
  }
}

static inline void VisitLevel2(Node *node, int arg)
{
  int i;
  Node *child;

  FUN_0001f20c(node, 2, arg);
  for (i = 0; i < FUN_0001f2f8(node); i++) {
    child = FUN_0001f300(node, i);
    VisitLevel3(child, arg);
  }
}

static inline void VisitLevel1(Node *node, int arg)
{
  int i;
  Node *child;

  FUN_0001f20c(node, 2, arg);
  for (i = 0; i < FUN_0001f2f8(node); i++) {
    child = FUN_0001f300(node, i);
    VisitLevel2(child, arg);
  }
}

/* Applies the node operation (FUN_0001f20c) to a node and, recursively, to all of its children. */
void FUN_00096e18(Node *node, int arg)
{
  int i;
  Node *child;

  FUN_0001f20c(node, 2, arg);
  for (i = 0; i < FUN_0001f2f8(node); i++) {
    child = FUN_0001f300(node, i);
    VisitLevel1(child, arg);
  }
}

