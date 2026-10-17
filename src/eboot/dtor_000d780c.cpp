/* HSTMATCH module=EBOOT.BIN start=0x000d780c end=0x000d7878 symbol=__dt__10C_000d780cFv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000d7878(void *self);
struct Blob_000d780c { int v; ~Blob_000d780c() {} };
class B_000d780c { public: Blob_000d780c *data; ~B_000d780c() { FUN_000d7878(this); delete data; } };
class C_000d780c : public B_000d780c { public: int count; ~C_000d780c(); };
C_000d780c::~C_000d780c() { count = 0; }
