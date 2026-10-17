/* HSTMATCH module=EBOOT.BIN start=0x000d5a84 end=0x000d5af0 symbol=__dt__10C_000d5a84Fv */
/* Clone of src/eboot/dtor_0008af7c.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_000d68ac(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_000d5a84 { public: Item *p; int n; ~C_000d5a84(); };
C_000d5a84::~C_000d5a84() { FUN_000d68ac(this, n, Alloc()); delete p; }
