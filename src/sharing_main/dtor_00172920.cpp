/* HSTMATCH module=hstp_trans_main.prx start=0x00172920 end=0x00172990 symbol=__dt__10D_00172920Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_00172920 { int v; ~Elem_00172920() {} };
class V_00172920 {
public:
    Elem_00172920 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00172920() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_00172920 : public V_00172920 { public: ~D_00172920(); };
D_00172920::~D_00172920() { size = 0; }
