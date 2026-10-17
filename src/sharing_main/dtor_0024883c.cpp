/* HSTMATCH module=hstp_trans_main.prx start=0x0024883c end=0x002488a8 symbol=__dt__10C_0024883cFv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00248a54(void *self);
struct Blob_0024883c { int v; ~Blob_0024883c() {} };
class B_0024883c { public: Blob_0024883c *data; ~B_0024883c() { FUN_00248a54(this); delete data; } };
class C_0024883c : public B_0024883c { public: int count; ~C_0024883c(); };
C_0024883c::~C_0024883c() { count = 0; }
