/* HSTMATCH module=EBOOT.BIN start=0x0028d7f8 end=0x0028d864 symbol=__dt__10C_0028d7f8Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
extern "C" void FUN_0028d864(void *self);
struct Blob_0028d7f8 { int v; ~Blob_0028d7f8() {} };
class B_0028d7f8 { public: Blob_0028d7f8 *data; ~B_0028d7f8() { FUN_0028d864(this); delete data; } };
class C_0028d7f8 : public B_0028d7f8 { public: int count; ~C_0028d7f8(); };
C_0028d7f8::~C_0028d7f8() { count = 0; }
