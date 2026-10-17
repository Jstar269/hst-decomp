/* HSTMATCH module=hstp_trans_main.prx start=0x0015211c end=0x00152188 symbol=__dt__10C_0015211cFv */
/* Clone of src/eboot/dtor_0005dbf4.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_00153660(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_0015211c { public: Item *p; int n; ~C_0015211c(); };
C_0015211c::~C_0015211c() { FUN_00153660(this, n, Alloc()); delete p; }
