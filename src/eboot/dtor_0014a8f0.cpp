/* HSTMATCH module=EBOOT.BIN start=0x0014a8f0 end=0x0014a95c symbol=__dt__10C_0014a8f0Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0014ad50(void *self);
struct Blob_0014a8f0 { int v; ~Blob_0014a8f0() {} };
class B_0014a8f0 { public: Blob_0014a8f0 *data; ~B_0014a8f0() { FUN_0014ad50(this); delete data; } };
class C_0014a8f0 : public B_0014a8f0 { public: int count; ~C_0014a8f0(); };
C_0014a8f0::~C_0014a8f0() { count = 0; }
