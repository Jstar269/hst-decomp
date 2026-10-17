/* HSTMATCH module=EBOOT.BIN start=0x0006d798 end=0x0006d804 symbol=__dt__10C_0006d798Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0006d804(void *self);
struct Blob_0006d798 { int v; ~Blob_0006d798() {} };
class B_0006d798 { public: Blob_0006d798 *data; ~B_0006d798() { FUN_0006d804(this); delete data; } };
class C_0006d798 : public B_0006d798 { public: int count; ~C_0006d798(); };
C_0006d798::~C_0006d798() { count = 0; }
