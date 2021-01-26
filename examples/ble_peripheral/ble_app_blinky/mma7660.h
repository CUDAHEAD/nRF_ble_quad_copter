#ifndef MPU6050_H__
#define MPU6050_H__


#include "nrf_twi_mngr.h"

#ifdef __cplusplus
extern "C" {
#endif


// 0x68 is the MPU-6050's address in the mbed Application Shield, it contains
// R/W bit and "nrf_drv_twi" (and consequently "nrf_twi_mngr") requires slave
// address without this bit, hence shifting.
#define MPU6050_ADDR        (0x68)

#define MPU6050_REG_XOUT    0x3b//0x43//0x3B //0x75 - Who am i//0x3B;//0x00
// #define MPU6050_REG_YOUT    0x61
// #define MPU6050_REG_ZOUT    0x63
// #define MPU6050_REG_TILT    0x03
// #define MPU6050_REG_SRST    0x04
// #define MPU6050_REG_SPCNT   0x05
// #define MPU6050_REG_INTSU   0x06
// #define MPU6050_REG_MODE    0x1B
// #define MPU6050_REG_SR      0x08
// #define MPU6050_REG_PDET    0x09
// #define MPU6050_REG_PD      0x0A

#define MPU6050_NUMBER_OF_REGISTERS 14

// The Alert bit (6) set signals that the register must be read again, since
// its value may be inaccurate (it was read at the same time as the device was
// attempting to update it).
// Applies to XOUT, YOUT, ZOUT and TILT registers.
// #define MPU6050_DATA_IS_VALID(reg_data)  (!((reg_data) & (1U << 6)))

// Gets acceleration (g) value (6-bit 2's complement) from register data.
// [use "/ 4" instead of ">> 2", as the result of right-shifting of a signed
//  type value is implementation-defined]
// #define MPU6050_GET_ACC(reg_data)  ((int8_t)((reg_data) << 2) / 4)

// // Get orientation of the device (PoLa bits from the Tilt Status register).
// #define MPU6050_GET_ORIENTATION(tilt_status)  (tilt_status & 0x1C)
// #define MPU6050_ORIENTATION_LEFT    0x04
// #define MPU6050_ORIENTATION_RIGHT   0x08
// #define MPU6050_ORIENTATION_DOWN    0x14
// #define MPU6050_ORIENTATION_UP      0x18

// #define MPU6050_TAP_DETECTED(tilt_status)   (tilt_status & (1U << 5))
// #define MPU6050_SHAKE_DETECTED(tilt_status) (tilt_status & (1U << 7))

extern uint8_t NRF_TWI_MNGR_BUFFER_LOC_IND MPU6050_xout_reg_addr;

#define MPU6050_READ(p_reg_addr, p_buffer, byte_cnt) \
    NRF_TWI_MNGR_WRITE(MPU6050_ADDR, p_reg_addr, 1,        NRF_TWI_MNGR_NO_STOP), \
    NRF_TWI_MNGR_READ (MPU6050_ADDR, p_buffer,   byte_cnt, 0)

//TODO should convert to 16 bit
// #define MPU6050_READ_XYZ_AND_TILT(p_buffer) \
//     MPU6050_READ(&MPU6050_xout_reg_addr, p_buffer, MPU6050_NUMBER_OF_REGISTERS)


#define MPU6050_INIT_TRANSFER_COUNT 3

extern nrf_twi_mngr_transfer_t const
    MPU6050_init_transfers[MPU6050_INIT_TRANSFER_COUNT];

#ifdef __cplusplus
}
#endif

#endif // MPU6050_H__
