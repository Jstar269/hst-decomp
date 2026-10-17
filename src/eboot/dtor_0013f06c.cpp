/* HSTMATCH module=EBOOT.BIN start=0x0013f06c end=0x0013f0d8 symbol=__dt__10C_0013f06cFv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0013f1f8(void *self);
struct Blob_0013f06c { int v; ~Blob_0013f06c() {} };
class B_0013f06c { public: Blob_0013f06c *data; ~B_0013f06c() { FUN_0013f1f8(this); delete data; } };
class C_0013f06c : public B_0013f06c { public: int count; ~C_0013f06c(); };
C_0013f06c::~C_0013f06c() { count = 0; }
