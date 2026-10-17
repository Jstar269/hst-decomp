/* HSTMATCH module=hstp_trans_main.prx start=0x000db5f8 end=0x000db668 symbol=__dt__10D_000db5f8Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000db5f8 { int v; ~Elem_000db5f8() {} };
class V_000db5f8 {
public:
    Elem_000db5f8 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000db5f8() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000db5f8 : public V_000db5f8 { public: ~D_000db5f8(); };
D_000db5f8::~D_000db5f8() { size = 0; }
