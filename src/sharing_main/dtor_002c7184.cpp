/* HSTMATCH module=hstp_trans_main.prx start=0x002c7184 end=0x002c71f0 symbol=__dt__10C_002c7184Fv */
/* Clone of src/eboot/dtor_0005dbf4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_002c71f0(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_002c7184 { public: Item *p; int n; ~C_002c7184(); };
C_002c7184::~C_002c7184() { FUN_002c71f0(this, n, Alloc()); delete p; }
