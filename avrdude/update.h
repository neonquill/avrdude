/*
 * avrdude - A Downloader/Uploader for AVR device programmers
 * Copyright (C) 2000-2005  Brian S. Dean <bsd@bsdhome.com>
 * Copyright (C) 2007 Joerg Wunsch
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* $Id$ */

#ifndef update_h
#define update_h

enum {
  DEVICE_READ,
  DEVICE_WRITE,
  DEVICE_VERIFY
};


typedef struct update_t {
  char * memtype;
  int    op;
  char * filename;
  int    format;
} UPDATE;

#ifdef __cplusplus
extern "C" {
#endif

extern UPDATE * parse_op(char * s);
extern UPDATE * dup_update(UPDATE * upd);
extern UPDATE * new_update(int op, char * memtype, int filefmt,
			   char * filename);
extern int do_op(PROGRAMMER * pgm, struct avrpart * p, UPDATE * upd,
		 int nowrite);

#ifdef __cplusplus
}
#endif

#endif
