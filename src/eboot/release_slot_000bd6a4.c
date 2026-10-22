/* HSTMATCH module=EBOOT.BIN start=0x000bd6a4 end=0x000bd704 symbol=FUN_000bd6a4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. (matching idiom: the byte offset is held in an `int off` local so the addu's operands come out as offset+base) */
typedef struct {
  int pad;
  void *dst;
  void *src;
  int len;
  unsigned char flag;
} Node;

extern void FUN_00011090(void *, void *, unsigned);

int FUN_000bd6a4(int param_1, int param_2)
{
  int off = param_2 * 4;
  Node **slot = (Node **)(off + param_1 + 0x1dc);
  Node *p = *slot;

  if (p == 0)
    return 0;
  if (p->flag != 0) {
    FUN_00011090(p->dst, p->src, p->len);
    (*slot)->flag = 0;
  }
  return 1;
}
