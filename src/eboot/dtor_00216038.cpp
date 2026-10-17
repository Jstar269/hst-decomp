/* HSTMATCH module=EBOOT.BIN start=0x00216038 end=0x002160a4 symbol=__dt__10C_00216038Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_002160a4(void *self);
struct Blob_00216038 { int v; ~Blob_00216038() {} };
class B_00216038 { public: Blob_00216038 *data; ~B_00216038() { FUN_002160a4(this); delete data; } };
class C_00216038 : public B_00216038 { public: int count; ~C_00216038(); };
C_00216038::~C_00216038() { count = 0; }
