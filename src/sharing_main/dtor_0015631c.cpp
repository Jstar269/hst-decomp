/* HSTMATCH module=hstp_trans_main.prx start=0x0015631c end=0x00156388 symbol=__dt__10C_0015631cFv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_001565cc(void *self);
struct Blob_0015631c { int v; ~Blob_0015631c() {} };
class B_0015631c { public: Blob_0015631c *data; ~B_0015631c() { FUN_001565cc(this); delete data; } };
class C_0015631c : public B_0015631c { public: int count; ~C_0015631c(); };
C_0015631c::~C_0015631c() { count = 0; }
