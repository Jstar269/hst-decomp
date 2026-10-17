/* HSTMATCH module=hstp_trans_main.prx start=0x0010d2d4 end=0x0010d340 symbol=__dt__10C_0010d2d4Fv */
/* Clone of src/eboot/dtor_0005dbf4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_0010e590(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_0010d2d4 { public: Item *p; int n; ~C_0010d2d4(); };
C_0010d2d4::~C_0010d2d4() { FUN_0010e590(this, n, Alloc()); delete p; }
