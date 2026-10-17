/* HSTMATCH module=hstp_trans_main.prx start=0x0015ba2c end=0x0015ba98 symbol=__dt__10C_0015ba2cFv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0015ba98(void *self);
struct Blob_0015ba2c { int v; ~Blob_0015ba2c() {} };
class B_0015ba2c { public: Blob_0015ba2c *data; ~B_0015ba2c() { FUN_0015ba98(this); delete data; } };
class C_0015ba2c : public B_0015ba2c { public: int count; ~C_0015ba2c(); };
C_0015ba2c::~C_0015ba2c() { count = 0; }
