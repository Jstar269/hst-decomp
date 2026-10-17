/* HSTMATCH module=hstp_trans_main.prx start=0x000f2ed8 end=0x000f2f44 symbol=__dt__10C_000f2ed8Fv */
/* Clone of src/eboot/dtor_0005dbf4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_000f3000(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_000f2ed8 { public: Item *p; int n; ~C_000f2ed8(); };
C_000f2ed8::~C_000f2ed8() { FUN_000f3000(this, n, Alloc()); delete p; }
