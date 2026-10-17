/* HSTMATCH module=hstp_trans_main.prx start=0x00101e50 end=0x00101ec0 symbol=__dt__10D_00101e50Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_00101e50 { int v; ~Elem_00101e50() {} };
class V_00101e50 {
public:
    Elem_00101e50 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00101e50() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_00101e50 : public V_00101e50 { public: ~D_00101e50(); };
D_00101e50::~D_00101e50() { size = 0; }
