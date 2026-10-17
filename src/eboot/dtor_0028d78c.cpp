/* HSTMATCH module=EBOOT.BIN start=0x0028d78c end=0x0028d7f8 symbol=__dt__10C_0028d78cFv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0028d888(void *self);
struct Blob_0028d78c { int v; ~Blob_0028d78c() {} };
class B_0028d78c { public: Blob_0028d78c *data; ~B_0028d78c() { FUN_0028d888(this); delete data; } };
class C_0028d78c : public B_0028d78c { public: int count; ~C_0028d78c(); };
C_0028d78c::~C_0028d78c() { count = 0; }
