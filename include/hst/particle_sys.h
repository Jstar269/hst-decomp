/* Particle system of the 0x219000 sources: a view object plus a fixed array of particles. */
#ifndef HST_PARTICLE_SYS_H
#define HST_PARTICLE_SYS_H

#define PARTICLE_COUNT 200    /* particles in the array */
#define PARTICLE_SIZE 0xa0    /* bytes per particle */

/* Values of the mode word set by the mode switch. */
enum {
  PARTICLE_MODE_WARMUP = 0,   /* initialise every particle and advance it three steps, then run */
  PARTICLE_MODE_RUN = 1,
  PARTICLE_MODE_REINIT = 2,   /* initialise every particle only, then run */
  PARTICLE_MODE_3 = 3         /* does nothing */
};

typedef struct ParticleSys {
  void *view;                 /* 0x0 owned, virtual destructor; also the render target of the draw pass */
  char *parts;                /* 0x4 owned, PARTICLE_COUNT particles of PARTICLE_SIZE bytes */
} ParticleSys;

#endif
