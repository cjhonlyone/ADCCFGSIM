/***************************************************************************//**
 *   @file   flash.h
 *   @brief  Header file for flash controller driver.
 *   @author Andrei Drimbarean (andrei.drimbarean@analog.com)
********************************************************************************
 * Copyright 2021(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#ifndef FLASH_H_
#define FLASH_H_

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/

#include <stdint.h>

/******************************************************************************/
/*************************** Types Declarations *******************************/
/******************************************************************************/

/**
 * @struct flash_dev
 * @brief Flash controller device structure
 */
struct flash_dev {
	/** Flash Device ID */
	uint8_t id;
	/** Size of flash memory in bytes */
	uint32_t flash_size;
	/** Size of flash page in bytes */
	uint32_t page_size;
	/** Flash extra parameters */
	void *extra;
};

/**
 * @struct flash_init_param
 * @brief Flash controller initialization structure
 */
struct flash_init_param {
	/** Flash Device ID */
	uint8_t id;
	/** Size of flash memory in bytes */
	uint32_t flash_size;
	/** Size of flash page in bytes */
	uint32_t flash_page_size;
	/** Flash extra parameters */
	void *extra;
};

/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/

/** Initialize flash controller. */
int32_t flash_init(struct flash_dev **device,
		   struct flash_init_param *init_param);

/** Free memory allocated by flash_init(). */
int32_t flash_remove(struct flash_dev *dev);

/** Erase a flash page. */
int32_t flash_clear_page(struct flash_dev *dev, int32_t page_no);

/** Write a flash page. */
int32_t flash_write_page(struct flash_dev *dev, int32_t page_no,
			 uint32_t *data);

/** Read a flash page. */
int32_t flash_read_page(struct flash_dev *dev, int32_t page_no, uint32_t *data);

/** Write data in flash memory. */
int32_t flash_write(struct flash_dev *dev, uint32_t flash_addr,
		    uint32_t *array, uint32_t array_size);

/** Read data from the flash memory. */
int32_t flash_read(struct flash_dev *dev, uint32_t flash_addr, uint32_t *array,
		   uint32_t size);

#endif /* FLASH_H_ */
