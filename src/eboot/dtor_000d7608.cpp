/* HSTMATCH module=EBOOT.BIN start=0x000d7608 end=0x000d7674 symbol=__dt__10C_000d7608Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000d78e4(void *self);
struct Blob_000d7608 { int v; ~Blob_000d7608() {} };
class B_000d7608 { public: Blob_000d7608 *data; ~B_000d7608() { FUN_000d78e4(this); delete data; } };
class C_000d7608 : public B_000d7608 { public: int count; ~C_000d7608(); };
C_000d7608::~C_000d7608() { count = 0; }
