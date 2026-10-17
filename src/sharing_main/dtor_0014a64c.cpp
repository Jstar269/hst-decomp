/* HSTMATCH module=hstp_trans_main.prx start=0x0014a64c end=0x0014a6b8 symbol=__dt__10C_0014a64cFv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0014a868(void *self);
struct Blob_0014a64c { int v; ~Blob_0014a64c() {} };
class B_0014a64c { public: Blob_0014a64c *data; ~B_0014a64c() { FUN_0014a868(this); delete data; } };
class C_0014a64c : public B_0014a64c { public: int count; ~C_0014a64c(); };
C_0014a64c::~C_0014a64c() { count = 0; }
