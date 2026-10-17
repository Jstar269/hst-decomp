/* HSTMATCH module=EBOOT.BIN start=0x00108bf4 end=0x00108c60 symbol=__dt__10C_00108bf4Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00108c60(void *self);
struct Blob_00108bf4 { int v; ~Blob_00108bf4() {} };
class B_00108bf4 { public: Blob_00108bf4 *data; ~B_00108bf4() { FUN_00108c60(this); delete data; } };
class C_00108bf4 : public B_00108bf4 { public: int count; ~C_00108bf4(); };
C_00108bf4::~C_00108bf4() { count = 0; }
