/* HSTMATCH module=hstp_trans_main.prx start=0x0008c7b0 end=0x0008c81c symbol=__dt__10C_0008c7b0Fv */
/* Clone of src/eboot/dtor_0005dbf4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_0008c8b8(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_0008c7b0 { public: Item *p; int n; ~C_0008c7b0(); };
C_0008c7b0::~C_0008c7b0() { FUN_0008c8b8(this, n, Alloc()); delete p; }
