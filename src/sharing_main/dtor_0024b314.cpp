/* HSTMATCH module=hstp_trans_main.prx start=0x0024b314 end=0x0024b380 symbol=__dt__10C_0024b314Fv */
/* Clone of src/eboot/dtor_0005dbf4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_0024b758(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_0024b314 { public: Item *p; int n; ~C_0024b314(); };
C_0024b314::~C_0024b314() { FUN_0024b758(this, n, Alloc()); delete p; }
