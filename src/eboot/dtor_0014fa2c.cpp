/* HSTMATCH module=EBOOT.BIN start=0x0014fa2c end=0x0014fa98 symbol=__dt__10C_0014fa2cFv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0014fa98(void *self);
struct Blob_0014fa2c { int v; ~Blob_0014fa2c() {} };
class B_0014fa2c { public: Blob_0014fa2c *data; ~B_0014fa2c() { FUN_0014fa98(this); delete data; } };
class C_0014fa2c : public B_0014fa2c { public: int count; ~C_0014fa2c(); };
C_0014fa2c::~C_0014fa2c() { count = 0; }
