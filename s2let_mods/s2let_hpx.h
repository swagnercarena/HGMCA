// S2LET package
// Copyright (C) 2012
// Boris Leistedt & Jason McEwen

#ifndef S2LET_HPX
#define S2LET_HPX

#include <complex.h>

/*!
 * Restore real healpix map from spherical harmonic coefficients.
 * Interface for HEALPIX Fortran code alm2map.
 *
 * \param[out]  f Output healpix map.
 * \param[in]  flm Spherical harmonic coefficients.
 * \param[in]  nside Healpix resolution of the output map.
 * \param[in]  L Angular harmonic band-limit.
 * \retval none
 */
void s2let_hpx_alm2map_spin_real(double* fQ, double* fU, const complex double* flmE, const complex double* flmB, int nside, int L, int spin);

/*!
 * Compute spherical harmonic coefficients of a real healpix map.
 * Interface for HEALPIX Fortran code map2alm.
 *
 * \param[out]  flm Spherical harmonic coefficients.
 * \param[in]  f Input healpix map.
 * \param[in]  nside Healpix resolution of the output map.
 * \param[in]  L Angular harmonic band-limit.
 * \retval none
 */
void s2let_hpx_map2alm_spin_real(complex double* flmE, complex double* flmB, const double* fQ, const double* fU, int nside, int L, int spin);

/*!
 * Restore real healpix map from spherical harmonic coefficients.
 * Interface for HEALPIX Fortran code alm2map.
 *
 * \param[out]  f Output healpix map.
 * \param[in]  flm Spherical harmonic coefficients.
 * \param[in]  nside Healpix resolution of the output map.
 * \param[in]  L Angular harmonic band-limit.
 * \retval none
 */
void s2let_hpx_alm2map_real(double* f, const complex double* flm, int nside, int L);


/*!
 * Compute spherical harmonic coefficients of a real healpix map.
 * Interface for HEALPIX Fortran code map2alm.
 *
 * \param[out]  flm Spherical harmonic coefficients.
 * \param[in]  f Input healpix map.
 * \param[in]  nside Healpix resolution of the output map.
 * \param[in]  L Angular harmonic band-limit.
 * \retval none
 */
void s2let_hpx_map2alm_real(complex double* flm, const double* f, int nside, int L);


/*!
 * Read Healpix map from a FITS file.
 * Interface for HEALPIX Fortran code read_bintab.
 *
 * \param[out]  f Input healpix map.
 * \param[in]  file Filename.
 * \param[in]  nside Healpix resolution of the output map.
 * \retval none
 */
void s2let_hpx_read_map(double* f, char* file, int nside);

void s2let_hpx_read_maps(double* f, char* file, int nside, int nmaps);


/*!
 * Write Healpix map to a FITS file.
 * Interface for HEALPIX Fortran code write_bintab.
 *
 * \param[in]  file Filename.
 * \param[in]  f Input healpix map.
 * \param[in]  nside Healpix resolution of the output map.
 * \retval none
 */
void s2let_hpx_write_map(char* file, const double* f, int nside);


/*!
 * Allocate Healpix map.
 *
 * \param[inout]  f healpix map.
 * \param[in]  nside Healpix resolution.
 * \retval none
 */
void s2let_hpx_allocate_real(double **f, int nside);

// A variable used to keep track of the sampling scheme.
extern int global_samp;

void s2let_set_hpx_sampling_scheme(int samp);

/*!
 * Return nside for healpix subsampling scheme.
 *
 * \param[in]  j the wavelet scale.
 * \param[in]  nside Healpix resolution.
 * \retval int nside for this wavelet scale
 */
int s2let_scaling_nside(int j, int B, int nside);

void s2let_transform_axisym_allocate_hpx_f_wav_hpx_real(double **f_wav, double **f_scal, int nside, const s2let_parameters_t *parameters);

#endif
