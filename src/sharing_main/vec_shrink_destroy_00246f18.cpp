/* HSTMATCH module=hstp_trans_main.prx start=0x00246f18 end=0x00246f9c symbol=FUN_00246f18 lang=c++ */
/* Clone of src/eboot/vec_shrink_destroy_00236db4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1) corrected by hand: restructured as a vector shrink (inline cut(n, Alloc()) returns data+size and lowers size, then the destroy walk); exact match verified; names and types await human review. */
struct Elem { char pad[0xc4]; char arr[0x18 * 3]; char pad2[0x230 - 0xc4 - 0x18 * 3]; };
struct Alloc {};
extern "C" void FUN_00000788(void *, void *, int, int);
extern "C" void FUN_00245d30(void);

struct Vec {
  Elem *data;
  int size;
  Elem *cut(int n, Alloc) {
    Elem *p = data + size;
    size -= n;
    return p;
  }
};

extern "C" void FUN_00246f18(Vec *v, int n)
{
  Elem *p = v->cut(n, Alloc());
  for (; n != 0; n--) {
    --p;
    if (p) FUN_00000788(p->arr, (void *)FUN_00245d30, 0x18, 3);
  }
}
