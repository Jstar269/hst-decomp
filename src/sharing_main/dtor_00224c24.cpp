/* HSTMATCH module=hstp_trans_main.prx start=0x00224c24 end=0x00224c90 symbol=__dt__10C_00224c24Fv */
/* Clone of src/eboot/dtor_0005dbf4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_00224c90(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_00224c24 { public: Item *p; int n; ~C_00224c24(); };
C_00224c24::~C_00224c24() { FUN_00224c90(this, n, Alloc()); delete p; }
