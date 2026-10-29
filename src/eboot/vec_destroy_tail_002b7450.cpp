/* HSTMATCH module=EBOOT.BIN start=0x002b7450 end=0x002b74b8 symbol=FUN_002b7450 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: the function takes a trailing empty by-value tag parameter that Ghidra omits (it adds 16 bytes of frame); readability pass; exact match verified; names and types await human review. */
struct False {};
struct VC_0 { virtual void m(int); };

/* Vector of 8-byte polymorphic elements: data pointer and element count. */
struct ElemVec { int data; int size; };

/* Removes the last n elements: lowers the size, then runs the virtual deleting call (-1) on each removed element from the back. */
extern "C" void FUN_002b7450(ElemVec *vec, int n, False)
{
  int *p;

  p = (int *)(vec->data + vec->size * 8);
  vec->size = vec->size - n;
  for (; n != 0; n = n + -1) {
    p = p + -2;
    ((VC_0 *)(p))->m((int)(0xffffffff));
  }
}
