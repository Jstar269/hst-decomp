/* HSTMATCH module=EBOOT.BIN start=0x0012f3f0 end=0x0012f414 symbol=FUN_0012f3f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
/* View of the camera object that only shows the two four-word blocks this function copies. */
typedef struct CameraWords {
  char pad00[0x70];
  float src[4];   /* 0x70 */
  char pad80[0x10];
  float dst[4];   /* 0x90 */
} CameraWords;

extern void FUN_0012f248(CameraWords *);

/* Copy the four words at 0x70 over those at 0x90, then run the camera state update. */
void FUN_0012f3f0(CameraWords *self)
{
  self->dst[0] = self->src[0];
  self->dst[1] = self->src[1];
  self->dst[2] = self->src[2];
  self->dst[3] = self->src[3];
  FUN_0012f248(self);
  return;
}
