/***********************************************************************
 *                   GNU Lesser General Public License
 *
 * This file is part of the GFDL FRE NetCDF tools package (FRE-NCTools).
 *
 * FRE-NCtools is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 *
 * FRE-NCtools is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FRE-NCTools.  If not, see
 * <http://www.gnu.org/licenses/>.
 **********************************************************************/
/*******************************************************************************
                             create_hgrid.h
  This header file provide interface to create different types of horizontal 
  grid. geographical grid location, cell length, cell area and rotation
  angle are returned. All the returned data are on supergrid.

  contact: Zhi.Liang@noaa.gov
  Modifications:
  05/10/2020  -- Added multiple nest capability.  Bill Ramstrom, AOML/HRD
*******************************************************************************/
#ifndef CREATE_HGRID_H_
#define CREATE_HGRID_H_

#define MAX_NESTS 128

void create_regular_lonlat_grid( int *nxbnds, int *nybnds, double *xbnds, double *ybnds,
		         	 int *nlon, int *nlat, double *dlon, double *dlat,
				 int use_legacy, int *isc, int *iec,
				 int *jsc, int *jec, double *x, double *y, double *dx,
				 double *dy, double *area, double *angle_dx, const char *center,
                                 int  use_great_circle_algorithm);

void create_simple_cartesian_grid( double *xbnds, double *ybnds, int *nlon, int *nlat,
				   double *simple_dx, double *simple_dy, int *isc, int *iec,
				   int *jsc, int *jec, double *x, double *y,
				   double *dx, double *dy, double *area, double *angle_dx);

void create_grid_from_file( char *file, int *nlon, int *nlat, double *x, double *y, double *dx, double *dy,
           		    double *area, double *angle_dx, int  use_great_circle_algorithm );

void create_spectral_grid( int *nlon, int *nlat, int *isc, int *iec,
			   int *jsc, int *jec, double *x, double *y, double *dx,
			   double *dy, double *area, double *angle_dx, int  use_great_circle_algorithm );

void create_tripolar_grid( int *nxbnds, int *nybnds, double *xbnds, double *ybnds,
			   int *nlon, int *nlat, double *dlon, double *dlat,
			   int use_legacy, double *lat_join_in, int *isc, int *iec,
			   int *jsc, int *jec, double *x, double *y, double *dx, double *dy,
			   double *area, double *angle_dx, const char *center, unsigned int verbose,
                           int  use_great_circle_algorithm);

void create_conformal_cubic_grid( int *npts, int *nratio, char *method, char *orientation, double *x,
			          double *y, double *dx, double *dy, double *area, double *angle_dx,
			          double *angle_dy );

void create_gnomonic_cubic_grid( char* grid_type, int *nlon, int *nlat, double *x, double *y,
				 double *dx, double *dy, double *area, double *angle_dx,
			         double *angle_dy, double shift_fac, int do_schmidt, int do_cube_transform, double stretch_factor,
				 double target_lon, double target_lat, int nest_grids,
				 int parent_tile[MAX_NESTS], int refine_ratio[MAX_NESTS], int istart_nest[MAX_NESTS],
				 int iend_nest[MAX_NESTS], int jstart_nest[MAX_NESTS], int jend_nest[MAX_NESTS],
				 int halo, int output_angle_length );
void create_f_plane_grid( int *nxbnds, int *nybnds, double *xbnds, double *ybnds,
                          int *nlon, int *nlat, double *dlon, double *dlat,
			  int use_legacy, double f_plane_latitude, int *isc, int *iec,
                          int *jsc, int *jec, double *x, double *y, double *dx,
                          double *dy, double *area, double *angle_dx, const char *center );
#endif
