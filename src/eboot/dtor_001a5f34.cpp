/* HSTMATCH module=EBOOT.BIN start=0x001a5f34 end=0x001a5fa0 symbol=__dt__10C_001a5f34Fv */
/* Clone of src/eboot/dtor_0008af7c.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_001a7018(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_001a5f34 { public: Item *p; int n; ~C_001a5f34(); };
C_001a5f34::~C_001a5f34() { FUN_001a7018(this, n, Alloc()); delete p; }
