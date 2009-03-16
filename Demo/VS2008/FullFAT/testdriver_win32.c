/*****************************************************************************
 *  FullFAT - High Performance, Thread-Safe Embedded FAT File-System         *
 *  Copyright (C) 2009  James Walmsley (james@worm.me.uk)                    *
 *                                                                           *
 *  This program is free software: you can redistribute it and/or modify     *
 *  it under the terms of the GNU General Public License as published by     *
 *  the Free Software Foundation, either version 3 of the License, or        *
 *  (at your option) any later version.                                      *
 *                                                                           *
 *  This program is distributed in the hope that it will be useful,          *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU General Public License for more details.                             *
 *                                                                           *
 *  You should have received a copy of the GNU General Public License        *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 *                                                                           *
 *  IMPORTANT NOTICE:                                                        *
 *  =================                                                        *
 *  Alternative Licensing is available directly from the Copyright holder,   *
 *  (James Walmsley). For more information consult LICENSING.TXT to obtain   *
 *  a Commercial license.                                                    *
 *                                                                           *
 *  See EXCEPTIONS.TXT for extra restrictions on the use of FullFAT.         *
 *                                                                           *
 *  Removing the above notice is illegal and will invalidate this license.   *
 *****************************************************************************
 *  See http://worm.me.uk/fullfat for more information.                      *
 *  Or  http://fullfat.googlecode.com/ for latest releases and the wiki.     *
 *****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>

/*
	This driver can inteface with Hard drives up to 2TB in size.
*/
signed int fnRead_512(unsigned char *buffer, unsigned long sector, unsigned short sectors, void *pParam) {
	unsigned long long address;
	address = (unsigned long long) sector * 512;
	_fseeki64(pParam, address, SEEK_SET);
	fread(buffer, 512, sectors, pParam);
	return sectors;
}

signed int fnNewRead_512(unsigned char *buffer, unsigned long sector, unsigned short sectors, void *pParam) {
	unsigned long long address;
	int retVal;
	address = (unsigned long long) sector * 512;
	lseek((int)pParam, address, SEEK_SET);
	retVal = read((int)pParam, buffer, 512);
	return sectors;
}

signed int fnNewWrite_512(unsigned char *buffer, unsigned long sector, unsigned short sectors, void *pParam) {
	unsigned long long address;
	int retVal;
	address = (unsigned long long) sector * 512;
	lseek((int)pParam, address, SEEK_SET);
	retVal = write((int)pParam, buffer, 512);
	return sectors;
}

signed int fnWrite_512(unsigned char *buffer, unsigned long sector, unsigned short sectors, void *pParam) {
	unsigned long long address;
	unsigned long retVal;
	address = (unsigned long long) sector * 512;
	_fseeki64(pParam, address, SEEK_SET);
	retVal = fwrite(buffer, 512, sectors, pParam);
	return sectors;
}

/*
	This driver works for devices with blocksizes of 2048.
*/
signed int test_2048(unsigned char *buffer, unsigned long sector, unsigned short sectors, void *pParam){
	unsigned long long address;
	address = (unsigned long long) sector * 2048;
	_fseeki64(pParam, address, SEEK_SET);
	fread(buffer, 2048, sectors, pParam);
	return sectors;
}
