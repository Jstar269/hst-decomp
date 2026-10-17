/* HSTMATCH module=EBOOT.BIN start=0x001666a8 end=0x00166714 symbol=__dt__10C_001666a8Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00166714(void *self);
struct Blob_001666a8 { int v; ~Blob_001666a8() {} };
class B_001666a8 { public: Blob_001666a8 *data; ~B_001666a8() { FUN_00166714(this); delete data; } };
class C_001666a8 : public B_001666a8 { public: int count; ~C_001666a8(); };
C_001666a8::~C_001666a8() { count = 0; }
