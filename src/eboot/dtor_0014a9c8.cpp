/* HSTMATCH module=EBOOT.BIN start=0x0014a9c8 end=0x0014aa34 symbol=__dt__10C_0014a9c8Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0014ad08(void *self);
struct Blob_0014a9c8 { int v; ~Blob_0014a9c8() {} };
class B_0014a9c8 { public: Blob_0014a9c8 *data; ~B_0014a9c8() { FUN_0014ad08(this); delete data; } };
class C_0014a9c8 : public B_0014a9c8 { public: int count; ~C_0014a9c8(); };
C_0014a9c8::~C_0014a9c8() { count = 0; }
