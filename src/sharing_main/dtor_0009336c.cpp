/* HSTMATCH module=hstp_trans_main.prx start=0x0009336c end=0x000933d8 symbol=__dt__10C_0009336cFv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000933d8(void *self);
struct Blob_0009336c { int v; ~Blob_0009336c() {} };
class B_0009336c { public: Blob_0009336c *data; ~B_0009336c() { FUN_000933d8(this); delete data; } };
class C_0009336c : public B_0009336c { public: int count; ~C_0009336c(); };
C_0009336c::~C_0009336c() { count = 0; }
