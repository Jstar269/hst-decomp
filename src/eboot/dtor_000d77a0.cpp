/* HSTMATCH module=EBOOT.BIN start=0x000d77a0 end=0x000d780c symbol=__dt__10C_000d77a0Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000d789c(void *self);
struct Blob_000d77a0 { int v; ~Blob_000d77a0() {} };
class B_000d77a0 { public: Blob_000d77a0 *data; ~B_000d77a0() { FUN_000d789c(this); delete data; } };
class C_000d77a0 : public B_000d77a0 { public: int count; ~C_000d77a0(); };
C_000d77a0::~C_000d77a0() { count = 0; }
