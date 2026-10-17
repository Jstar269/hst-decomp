/* HSTMATCH module=EBOOT.BIN start=0x0005e748 end=0x0005e7b4 symbol=__dt__10C_0005e748Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0005e7b4(void *self);
struct Blob_0005e748 { int v; ~Blob_0005e748() {} };
class B_0005e748 { public: Blob_0005e748 *data; ~B_0005e748() { FUN_0005e7b4(this); delete data; } };
class C_0005e748 : public B_0005e748 { public: int count; ~C_0005e748(); };
C_0005e748::~C_0005e748() { count = 0; }
