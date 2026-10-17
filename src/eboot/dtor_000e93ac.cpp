/* HSTMATCH module=EBOOT.BIN start=0x000e93ac end=0x000e9418 symbol=__dt__10C_000e93acFv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000e95b8(void *self);
struct Blob_000e93ac { int v; ~Blob_000e93ac() {} };
class B_000e93ac { public: Blob_000e93ac *data; ~B_000e93ac() { FUN_000e95b8(this); delete data; } };
class C_000e93ac : public B_000e93ac { public: int count; ~C_000e93ac(); };
C_000e93ac::~C_000e93ac() { count = 0; }
