/* HSTMATCH module=hstp_trans_main.prx start=0x000b7768 end=0x000b77d4 symbol=__dt__10C_000b7768Fv */
/* Clone of src/eboot/dtor_0005dbf4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_000b8368(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_000b7768 { public: Item *p; int n; ~C_000b7768(); };
C_000b7768::~C_000b7768() { FUN_000b8368(this, n, Alloc()); delete p; }
