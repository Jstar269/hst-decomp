/* HSTMATCH module=EBOOT.BIN start=0x0028d720 end=0x0028d78c symbol=__dt__10C_0028d720Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0028d8ac(void *self);
struct Blob_0028d720 { int v; ~Blob_0028d720() {} };
class B_0028d720 { public: Blob_0028d720 *data; ~B_0028d720() { FUN_0028d8ac(this); delete data; } };
class C_0028d720 : public B_0028d720 { public: int count; ~C_0028d720(); };
C_0028d720::~C_0028d720() { count = 0; }
