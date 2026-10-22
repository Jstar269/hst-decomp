/* HSTMATCH module=hstp_trans_main.prx start=0x00069104 end=0x00069174 symbol=FUN_00069104 lang=c99 */
/* Clone of src/eboot/call_hook_twice_00067cb0.c (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Calls the given hook twice (with 255.0f and 128.0f as the first argument) and stores the two results in
   the four float slots of the output object. Names provisional. */
typedef struct {
  float f0;
  float f4;
  float f8;
  float fC;
} Out;
typedef float (*Fn)(float, float, float);

void FUN_00069104(Out *out, Fn fn, float t)
{
  out->f0 = out->f4 = out->f8 = fn(255.0f, 0.0f, t);
  out->fC = fn(128.0f, 0.0f, t);
}
