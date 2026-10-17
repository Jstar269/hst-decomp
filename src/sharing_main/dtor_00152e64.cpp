/* HSTMATCH module=hstp_trans_main.prx start=0x00152e64 end=0x00152ed0 symbol=__dt__10C_00152e64Fv */
/* Clone of src/eboot/dtor_0005dbf4.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_00155a08(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_00152e64 { public: Item *p; int n; ~C_00152e64(); };
C_00152e64::~C_00152e64() { FUN_00155a08(this, n, Alloc()); delete p; }
