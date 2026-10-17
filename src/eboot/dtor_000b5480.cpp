/* HSTMATCH module=EBOOT.BIN start=0x000b5480 end=0x000b54ec symbol=__dt__10C_000b5480Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000b557c(void *self);
struct Blob_000b5480 { int v; ~Blob_000b5480() {} };
class B_000b5480 { public: Blob_000b5480 *data; ~B_000b5480() { FUN_000b557c(this); delete data; } };
class C_000b5480 : public B_000b5480 { public: int count; ~C_000b5480(); };
C_000b5480::~C_000b5480() { count = 0; }
