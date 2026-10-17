/* HSTMATCH module=hstp_trans_main.prx start=0x0022503c end=0x002250a8 symbol=__dt__10C_0022503cFv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_002250a8(void *self);
struct Blob_0022503c { int v; ~Blob_0022503c() {} };
class B_0022503c { public: Blob_0022503c *data; ~B_0022503c() { FUN_002250a8(this); delete data; } };
class C_0022503c : public B_0022503c { public: int count; ~C_0022503c(); };
C_0022503c::~C_0022503c() { count = 0; }
