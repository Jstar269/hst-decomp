/* HSTMATCH module=hstp_trans_main.prx start=0x001b3738 end=0x001b37a4 symbol=__dt__10C_001b3738Fv */
/* Clone of src/eboot/dtor_0005dbf4.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_001b4740(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_001b3738 { public: Item *p; int n; ~C_001b3738(); };
C_001b3738::~C_001b3738() { FUN_001b4740(this, n, Alloc()); delete p; }
