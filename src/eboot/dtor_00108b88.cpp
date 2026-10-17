/* HSTMATCH module=EBOOT.BIN start=0x00108b88 end=0x00108bf4 symbol=__dt__10C_00108b88Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00108c84(void *self);
struct Blob_00108b88 { int v; ~Blob_00108b88() {} };
class B_00108b88 { public: Blob_00108b88 *data; ~B_00108b88() { FUN_00108c84(this); delete data; } };
class C_00108b88 : public B_00108b88 { public: int count; ~C_00108b88(); };
C_00108b88::~C_00108b88() { count = 0; }
