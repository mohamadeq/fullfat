/*****************************************************************************
 *  FullFAT - High Performance, Thread-Safe Embedded FAT File-System         *
 *                                                                           *
 *  Copyright(C) 2009 James Walmsley  (james@fullfat-fs.co.uk)               *
 *  Copyright(C) 2010 Hein Tibosch    (hein_tibosch@yahoo.es)                *
 *                                                                           *
 *  See RESTRICTIONS.TXT for extra restrictions on the use of FullFAT.       *
 *                                                                           *
 *  Removing this notice is illegal and will invalidate this license.        *
 *****************************************************************************
 *  See http://www.fullfat-fs.co.uk/ for more information.                   *
 *  Or  http://fullfat.googlecode.com/ for latest releases and the wiki.     *
 *****************************************************************************
 * As of 19-July-2011 FullFAT has abandoned the GNU GPL License in favour of *
 * the more flexible Apache 2.0 license. See License.txt for full terms.     *
 *                                                                           *
 *            YOU ARE FREE TO USE FULLFAT IN COMMERCIAL PROJECTS             *
 *****************************************************************************/

#ifndef _FULLFAT_H_
#define _FULLFAT_H_

#ifdef	__cplusplus
extern "C" {
#endif

#define FF_VERSION		"2.0.0-beta2"	// The official version number for this release.
#define FF_REVISION		"SVN-r390"		// The official version control commit code for this release.

#include "ff_config.h"
#include "ff_ioman.h"
#include "ff_crc.h"
#include "ff_dir.h"
#include "ff_error.h"
#include "ff_fat.h"
#include "ff_file.h"
#include "ff_hash.h"
#include "ff_time.h"
#include "ff_string.h"
#include "ff_types.h"
#include "ff_unicode.h"
//#include "ff_format.h"

#ifdef	__cplusplus
}	// extern "C"
#endif

#endif
