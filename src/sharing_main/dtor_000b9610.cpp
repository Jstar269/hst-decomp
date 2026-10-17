/* HSTMATCH module=hstp_trans_main.prx start=0x000b9610 end=0x000b9680 symbol=__dt__10D_000b9610Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000b9610 { int v; ~Elem_000b9610() {} };
class V_000b9610 {
public:
    Elem_000b9610 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000b9610() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000b9610 : public V_000b9610 { public: ~D_000b9610(); };
D_000b9610::~D_000b9610() { size = 0; }
