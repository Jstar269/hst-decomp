/* HSTMATCH module=EBOOT.BIN start=0x000dad14 end=0x000dad80 symbol=__dt__10C_000dad14Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000dad80(void *self);
struct Blob_000dad14 { int v; ~Blob_000dad14() {} };
class B_000dad14 { public: Blob_000dad14 *data; ~B_000dad14() { FUN_000dad80(this); delete data; } };
class C_000dad14 : public B_000dad14 { public: int count; ~C_000dad14(); };
C_000dad14::~C_000dad14() { count = 0; }
