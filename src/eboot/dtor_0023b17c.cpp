/* HSTMATCH module=EBOOT.BIN start=0x0023b17c end=0x0023b1e8 symbol=__dt__10C_0023b17cFv */
/* Clone of src/eboot/dtor_0008af7c.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_0023b5c0(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_0023b17c { public: Item *p; int n; ~C_0023b17c(); };
C_0023b17c::~C_0023b17c() { FUN_0023b5c0(this, n, Alloc()); delete p; }
