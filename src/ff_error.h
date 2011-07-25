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

#ifndef _FF_ERROR_H_
#define _FF_ERROR_H_

/**
 *	@file		ff_error.h
 *	@author		James Walmsley
 *	@ingroup	ERROR
 **/

#include "ff_config.h"
#include "ff_types.h"

/**
 * Error codes are 32-bit numbers, and consist of three items:
 *    1Bit     7Bits      8Bits           16Bits
 *     .     ........   ........    ........  ........
 * [ErrFlag][ModuleID][FunctionID][--   ERROR CODE   --]
 *
 * Error Codes should always have the ErrFlag set, this is the reason why all module
 * codes include it.
 *
 * When returning an error simply return the defined Error Code, OR'd with the function
 * name (capitalised) in which the error has occured.
 *
 * When receiving an Error code from another layer, do not modify the code, as this will
 * prevent the error code from containing the origin of the error, simply pass it to the
 * next layer.
 *
 * Some API's have been defined to provide, useful and meaningful Error messages to the
 * the 'userspace' application layer.
 *
 **/

#define FF_MODULE_SHIFT		24
#define FF_FUNCTION_SHIFT	16

#define FF_GETERROR(x)		(x & 0xFFFF)
#define FF_GETMODULE(x)		( (x >> FF_MODULE_SHIFT) & 0xFF)
#define FF_GETFUNCTION(x)	( (x >> FF_FUNCTION_SHIFT) & 0xFF)
#define FF_ERRFLAG			0x80000000									// Used for Signed errors (FF_SINT32) returns.
#define FF_isERR(x)			(x & FF_ERRFLAG)

//----- FullFAT Module Identifiers
#define FF_MODULE_IOMAN		(( 1 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_DIR		(( 2 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_FILE		(( 3 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_FAT		(( 4 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_CRC		(( 5 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_FORMAT	(( 6 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_HASH		(( 7 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_MEMORY	(( 8 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_STRING	(( 9 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_UNICODE	((10 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_SAFETY	((11 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_TIME		((12 << FF_MODULE_SHIFT) | FF_ERRFLAG)
#define FF_MODULE_DRIVER	((13 << FF_MODULE_SHIFT) | FF_ERRFLAG)	// We can mark errors from underlying layers with this code.

//----- FullFAT Function Identifiers (In Modular Order)
//----- FF_IOMAN - The FullFAT I/O Manager.
#define FF_CREATEIOMAN				((1	<< FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_DESTROYIOMAN				((2	<< FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_REGISTERBLKDEVICE		((3	<< FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_UNREGISTERBLKDEVICE		((4	<< FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_MOUNTPARTITION			((5	<< FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_UNMOUNTPARTITION			((6	<< FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_FLUSHCACHE				((7	<< FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_GETPARTITIONBLOCKSIZE	((8	<< FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_BLOCKREAD				((9	<< FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_BLOCKWRITE				((10 << FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_DETERMINEFATTYPE			((11 << FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_GETEFIPARTITIONENTRY		((12 << FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)
#define FF_USERDRIVER				((13 << FF_FUNCTION_SHIFT) | FF_MODULE_IOMAN)

//----- FullFAT Return codes for user Rd/Wr routines
#define FF_ERR_DRIVER_BUSY			(FF_ERR_IOMAN_DRIVER_BUSY | FF_USERDRIVER | FF_MODULE_DRIVER)
#define FF_ERR_DRIVER_FATAL_ERROR	(FF_ERR_IOMAN_DRIVER_FATAL_ERROR | FF_USERDRIVER | FF_MODULE_DRIVER)


//----- FF_DIR - The FullFAT directory handling routines.
// -- COMPLETE THESE ERROR CODES TOMORROW :P
#define FF_FINDNEXTINDIR			((1	<< FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_FETCHENTRYWITHCONTEXT	((2	<< FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_PUSHENTRYWITHCONTEXT		((3	<< FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_GETENTRY					((4	<< FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_FINDFIRST				((5	<< FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_FINDNEXT					((6	<< FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_REWINDFIND				((7	<< FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_FINDFREEDIRENT			((8	<< FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_PUTENTRY					((9	<< FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_CREATESHORTNAME			((10 << FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_CREATELFNS				((11 << FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_EXTENDDIRECTORY			((12 << FF_FUNCTION_SHIFT) | FF_MODULE_DIR)
#define FF_MKDIR					((13 << FF_FUNCTION_SHIFT) | FF_MODULE_DIR)

//----- FF_FILE - The FullFAT file handling routines.
#define FF_GETMODEBITS				((1	<< FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_OPEN						((2 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_ISDIREMPTY				((3	<< FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_RMDIR					((4	<< FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_RMFILE					((5	<< FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_MOVE						((6	<< FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_ISEOF					((7	<< FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_GETSEQUENTIALCLUSTERS	((8	<< FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_READCLUSTERS				((9	<< FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_EXTENDFILE				((10 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_WRITECLUSTERS			((11 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_READ						((12 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_GETC						((13 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_GETLINE					((14 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_TELL						((15 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_WRITE					((16 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_PUTC						((17 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_SEEK						((18 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_INVALIDATE				((19 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_CHECKVALID				((20 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_CLOSE					((21 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_SETTIME					((22 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_BYTESLEFT				((23 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)
#define FF_SETFILETIME				((24 << FF_FUNCTION_SHIFT) | FF_MODULE_FILE)

//----- FF_FAT - The FullFAT FAT handling routines.
#define FF_GETFATENTRY				((1	<< FF_FUNCTION_SHIFT) | FF_MODULE_FAT)
#define FF_CLEARCLUSTER				((2	<< FF_FUNCTION_SHIFT) | FF_MODULE_FAT)
#define FF_PUTFATENTRY				((3	<< FF_FUNCTION_SHIFT) | FF_MODULE_FAT)
#define FF_FINDFREECLUSTER			((4	<< FF_FUNCTION_SHIFT) | FF_MODULE_FAT)
#define FF_COUNTFREECLUSTERS		((5	<< FF_FUNCTION_SHIFT) | FF_MODULE_FAT)

//----- FF_HASH - The FullFAT hashing routines.
#define FF_CLEARHASHTABLE			((1	<< FF_FUNCTION_SHIFT) | FF_MODULE_HASH)
#define FF_SETHASH					((2	<< FF_FUNCTION_SHIFT) | FF_MODULE_HASH)
#define FF_CLEARHASH				((3	<< FF_FUNCTION_SHIFT) | FF_MODULE_HASH)
#define FF_DESTROYHASHTABLE			((4	<< FF_FUNCTION_SHIFT) | FF_MODULE_HASH)

//----- FF_UNICODE - The FullFAT hashing routines.
#define FF_UTF8CTOUTF16C			((1	<< FF_FUNCTION_SHIFT) | FF_MODULE_UNICODE)
#define FF_UTF16CTOUTF8C			((2	<< FF_FUNCTION_SHIFT) | FF_MODULE_UNICODE)
#define FF_UTF32CTOUTF16C			((3	<< FF_FUNCTION_SHIFT) | FF_MODULE_UNICODE)
#define FF_UTF16CTOUTF32C			((4	<< FF_FUNCTION_SHIFT) | FF_MODULE_UNICODE)

#define FF_FORMATPARTITION			((1	<< FF_FUNCTION_SHIFT) | FF_MODULE_FORMAT)

/*	FullFAT defines different Error-Code spaces for each module. This ensures
	that all error codes remain unique, and their meaning can be quickly identified.
*/
// Global Error Codes
#define FF_ERR_NONE								 0	///< No Error
//#define FF_ERR_GENERIC							  1	///< BAD NEVER USE THIS! -- Therefore commented out.
#define FF_ERR_NULL_POINTER						 2	///< pIoman was NULL.
#define FF_ERR_NOT_ENOUGH_MEMORY				 3	///< malloc() failed! - Could not allocate handle memory.
#define FF_ERR_DEVICE_DRIVER_FAILED				 4	///< The Block Device driver reported a FATAL error, cannot continue.

// User return codes for Rd/Wr functions:
#define FF_ERR_IOMAN_DRIVER_BUSY				10
#define FF_ERR_IOMAN_DRIVER_FATAL_ERROR			11

// IOMAN Error Codes
#define	FF_ERR_IOMAN_BAD_BLKSIZE				11	///< The provided blocksize was not a multiple of 512.
#define FF_ERR_IOMAN_BAD_MEMSIZE				12	///< The memory size was not a multiple of the blocksize.
#define FF_ERR_IOMAN_DEV_ALREADY_REGD			13 ///< Device was already registered. Use FF_UnRegister() to re-use this IOMAN with another device.
#define FF_ERR_IOMAN_NO_MOUNTABLE_PARTITION		14	///< A mountable partition could not be found on the device.
#define FF_ERR_IOMAN_INVALID_FORMAT				15	///< The 
#define FF_ERR_IOMAN_INVALID_PARTITION_NUM		16	///< The partition number provided was out of range.
#define FF_ERR_IOMAN_NOT_FAT_FORMATTED			17	///< The partition did not look like a FAT partition.
#define FF_ERR_IOMAN_DEV_INVALID_BLKSIZE		18 ///< IOMAN object BlkSize is not compatible with the blocksize of this device driver.
#define FF_ERR_IOMAN_PARTITION_MOUNTED			19	///< Device is in use by an actively mounted partition. Unmount the partition first.
#define FF_ERR_IOMAN_ACTIVE_HANDLES				20 ///< The partition cannot be unmounted until all active file handles are closed. (There may also be active handles on the cache).
#define FF_ERR_IOMAN_GPT_HEADER_CORRUPT			21	///< The GPT partition table appears to be corrupt, refusing to mount.
#define FF_ERR_IOMAN_NOT_ENOUGH_FREE_SPACE		22
#define FF_ERR_IOMAN_OUT_OF_BOUNDS_READ			23
#define FF_ERR_IOMAN_OUT_OF_BOUNDS_WRITE		24


// File Error Codes								30 +
#define FF_ERR_FILE_ALREADY_OPEN				30	///< File is in use.
#define FF_ERR_FILE_NOT_FOUND					31	///< File was not found.
#define FF_ERR_FILE_OBJECT_IS_A_DIR				32	///< Tried to FF_Open() a Directory.
#define FF_ERR_FILE_IS_READ_ONLY				33	///< Tried to FF_Open() a file marked read only.
#define FF_ERR_FILE_INVALID_PATH				34	///< The path of the file was not found.
#define FF_ERR_FILE_NOT_OPENED_IN_WRITE_MODE	35
#define FF_ERR_FILE_NOT_OPENED_IN_READ_MODE		36
#define FF_ERR_FILE_EXTEND_FAILED				37	///< Could not extend the file.
#define FF_ERR_FILE_DESTINATION_EXISTS			38
#define FF_ERR_FILE_SOURCE_NOT_FOUND			39
#define FF_ERR_FILE_DIR_NOT_FOUND				40
#define FF_ERR_FILE_COULD_NOT_CREATE_DIRENT		41
#define FF_ERR_FILE_BAD_HANDLE					42	///< A file handle was invalid
#define FF_ERR_FILE_MEDIA_REMOVED				43	///< File handle got invalid because media was removed

// Directory Error Codes						50 +
#define FF_ERR_DIR_OBJECT_EXISTS				50	///< A file or folder of the same name already exists in the current directory.
#define FF_ERR_DIR_DIRECTORY_FULL				51	///< No more items could be added to the directory.
#define FF_ERR_DIR_END_OF_DIR					52	///
#define FF_ERR_DIR_NOT_EMPTY					53	///< Cannot delete a directory that contains files or folders.
#define FF_ERR_DIR_INVALID_PATH					54 ///< Could not find the directory specified by the path.
#define FF_ERR_DIR_CANT_EXTEND_ROOT_DIR			55	///< Can't extend the root dir.
#define FF_ERR_DIR_EXTEND_FAILED				56	///< Not enough space to extend the directory.
#define FF_ERR_DIR_NAME_TOO_LONG				57	///< Name exceeds the number of allowed charachters for a filename.

// Fat Error Codes								70 +
#define FF_ERR_FAT_NO_FREE_CLUSTERS				70	///< No more free space is available on the disk.

// UNICODE Error Codes							100 +
#define FF_ERR_UNICODE_INVALID_CODE				100 ///< An invalid Unicode charachter was provided!
#define FF_ERR_UNICODE_DEST_TOO_SMALL			101 ///< Not enough space in the UTF-16 buffer to encode the entire sequence as UTF-16.
#define FF_ERR_UNICODE_INVALID_SEQUENCE			102 ///< An invalid UTF-16 sequence was encountered.
#define FF_ERR_UNICODE_CONVERSION_EXCEEDED		103 ///< Filename exceeds MAX long-filename length when converted to UTF-16.

#ifdef FF_DEBUG
const FF_T_INT8 *FF_GetErrMessage	(FF_ERROR iErrorCode);
const FF_T_INT8 *FF_GetErrModule	(FF_ERROR iErrorCode);
const FF_T_INT8 *FF_GetErrFunction	(FF_ERROR iErrorCode);
#else
#define FF_GetErrMessage(X)		""				// A special MACRO incase FF_GetErrMessage() isn't gated with FF_DEBUG
#define FF_GetErrModule(X)		""
#define FF_GetErrFunction(X)	""
#endif											// Function call is safely replaced with a NULL string.

#endif
