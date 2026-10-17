/* HSTMATCH module=EBOOT.BIN start=0x0008af7c end=0x0008afe8 symbol=__dt__10C_0008af7cFv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_0008b198(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_0008af7c { public: Item *p; int n; ~C_0008af7c(); };
C_0008af7c::~C_0008af7c() { FUN_0008b198(this, n, Alloc()); delete p; }
