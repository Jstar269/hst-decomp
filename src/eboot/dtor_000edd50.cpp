/* HSTMATCH module=EBOOT.BIN start=0x000edd50 end=0x000eddbc symbol=__dt__10C_000edd50Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000eddbc(void *self);
struct Blob_000edd50 { int v; ~Blob_000edd50() {} };
class B_000edd50 { public: Blob_000edd50 *data; ~B_000edd50() { FUN_000eddbc(this); delete data; } };
class C_000edd50 : public B_000edd50 { public: int count; ~C_000edd50(); };
C_000edd50::~C_000edd50() { count = 0; }
