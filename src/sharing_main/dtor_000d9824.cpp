/* HSTMATCH module=hstp_trans_main.prx start=0x000d9824 end=0x000d9890 symbol=__dt__10C_000d9824Fv */
/* Clone of src/eboot/dtor_0005dbf4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: shrink by the current size through a non-inline helper that takes
   an empty allocator class by value (the by-value temporary is what reserves the 32-byte frame), then
   delete the element block (element type has a destructor, hence the null check). Names provisional. */
struct Alloc {};
extern "C" void FUN_000daa54(void *self, int n, Alloc a);
struct Item { int x; ~Item() {} };
class C_000d9824 { public: Item *p; int n; ~C_000d9824(); };
C_000d9824::~C_000d9824() { FUN_000daa54(this, n, Alloc()); delete p; }
