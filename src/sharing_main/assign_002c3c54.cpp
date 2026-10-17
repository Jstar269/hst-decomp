/* HSTMATCH module=hstp_trans_main.prx start=0x002c3c54 end=0x002c3d38 symbol=FUN_002c3c54 lang=c++ */
/* Clone of src/eboot/assign_002b40b0.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Implicit (memberwise) copy assignment of a 0x64-byte record, same shape as assign_00097b2c.cpp: the class is
   non-POD (user-declared constructor), so each char array is a count-down block copy (two elements per
   iteration) and the scalar bytes/words are copied one by one (lb = char, lbu = unsigned char). Field names are
   offsets. */
struct S_002c3c54 {
    int w00;
    char a04[32];
    char a24[32];
    char c44, c45, c46;
    unsigned char b47, b48;
    char c49, c4a, c4b;
    int w4c, w50;
    char a54[16];
    S_002c3c54();
};
extern "C" S_002c3c54 *FUN_002c3c54(S_002c3c54 *a, const S_002c3c54 *b)
{
    *a = *b;
    return a;
}
