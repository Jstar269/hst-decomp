/* HSTMATCH module=EBOOT.BIN start=0x0005a0ec end=0x0005a158 symbol=__dt__10C_0005a0ecFv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0005a158(void *self);
struct Blob_0005a0ec { int v; ~Blob_0005a0ec() {} };
class B_0005a0ec { public: Blob_0005a0ec *data; ~B_0005a0ec() { FUN_0005a158(this); delete data; } };
class C_0005a0ec : public B_0005a0ec { public: int count; ~C_0005a0ec(); };
C_0005a0ec::~C_0005a0ec() { count = 0; }
