/* HSTMATCH module=EBOOT.BIN start=0x000e9504 end=0x000e9570 symbol=__dt__10C_000e9504Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000e9570(void *self);
struct Blob_000e9504 { int v; ~Blob_000e9504() {} };
class B_000e9504 { public: Blob_000e9504 *data; ~B_000e9504() { FUN_000e9570(this); delete data; } };
class C_000e9504 : public B_000e9504 { public: int count; ~C_000e9504(); };
C_000e9504::~C_000e9504() { count = 0; }
