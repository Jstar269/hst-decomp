/* HSTMATCH module=EBOOT.BIN start=0x0013f0d8 end=0x0013f144 symbol=__dt__10C_0013f0d8Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0013f1d4(void *self);
struct Blob_0013f0d8 { int v; ~Blob_0013f0d8() {} };
class B_0013f0d8 { public: Blob_0013f0d8 *data; ~B_0013f0d8() { FUN_0013f1d4(this); delete data; } };
class C_0013f0d8 : public B_0013f0d8 { public: int count; ~C_0013f0d8(); };
C_0013f0d8::~C_0013f0d8() { count = 0; }
