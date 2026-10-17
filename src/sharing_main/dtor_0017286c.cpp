/* HSTMATCH module=hstp_trans_main.prx start=0x0017286c end=0x001728d8 symbol=__dt__10C_0017286cFv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_001728d8(void *self);
struct Blob_0017286c { int v; ~Blob_0017286c() {} };
class B_0017286c { public: Blob_0017286c *data; ~B_0017286c() { FUN_001728d8(this); delete data; } };
class C_0017286c : public B_0017286c { public: int count; ~C_0017286c(); };
C_0017286c::~C_0017286c() { count = 0; }
