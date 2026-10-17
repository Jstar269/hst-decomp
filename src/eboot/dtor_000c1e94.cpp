/* HSTMATCH module=EBOOT.BIN start=0x000c1e94 end=0x000c1f00 symbol=__dt__10C_000c1e94Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000c1f00(void *self);
struct Blob_000c1e94 { int v; ~Blob_000c1e94() {} };
class B_000c1e94 { public: Blob_000c1e94 *data; ~B_000c1e94() { FUN_000c1f00(this); delete data; } };
class C_000c1e94 : public B_000c1e94 { public: int count; ~C_000c1e94(); };
C_000c1e94::~C_000c1e94() { count = 0; }
