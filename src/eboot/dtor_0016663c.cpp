/* HSTMATCH module=EBOOT.BIN start=0x0016663c end=0x001666a8 symbol=__dt__10C_0016663cFv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00166738(void *self);
struct Blob_0016663c { int v; ~Blob_0016663c() {} };
class B_0016663c { public: Blob_0016663c *data; ~B_0016663c() { FUN_00166738(this); delete data; } };
class C_0016663c : public B_0016663c { public: int count; ~C_0016663c(); };
C_0016663c::~C_0016663c() { count = 0; }
