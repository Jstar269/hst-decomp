/* HSTMATCH module=EBOOT.BIN start=0x0014a95c end=0x0014a9c8 symbol=__dt__10C_0014a95cFv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0014ad2c(void *self);
struct Blob_0014a95c { int v; ~Blob_0014a95c() {} };
class B_0014a95c { public: Blob_0014a95c *data; ~B_0014a95c() { FUN_0014ad2c(this); delete data; } };
class C_0014a95c : public B_0014a95c { public: int count; ~C_0014a95c(); };
C_0014a95c::~C_0014a95c() { count = 0; }
