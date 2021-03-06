/***************************************************************************
 * $Id: fmatrix.h,v 1.8 2003/04/24 13:49:40 renev Exp $
 *
 * Copyright (C) 2001-2002 by Rene Villiger <rvilliger@smile.ch>
 *                            Prakash Dayal <prakash@comp-phys.org>
 *                            Matthias Troyer <troyer@comp-phys.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *
 **************************************************************************/

#ifndef IETL_FMATRIX_H
#define IETL_FMATRIX_H

#include <cstddef>

#undef minor

namespace ietl
{

    template <class T>
    class FortranMatrix 
    {
      private:
         T* p;
         std::size_t n_;
         std::size_t m_;
      public:
         typedef std::size_t size_type;
         FortranMatrix(size_type n, size_type m) : n_(n), m_(m) { p = new T[m*n]; };
         ~FortranMatrix() { delete[] p; };
         T* data() { return p; };
         const T* data() const { return p; };
         T operator()(size_type i, size_type j) const { return p[i+j*n_]; };
         T& operator()(size_type i, size_type j) { return p[i+j*n_]; };
         void resize(size_type n, size_type m) { m_=m; n_=n; delete[] p; p = new T[m*n]; };
         size_type nrows() { return n_; };
         size_type ncols() { return m_; };
         size_type minor() { return n_; };
    };  
}
#endif

