
#include "mma7660.h"

uint8_t NRF_TWI_MNGR_BUFFER_LOC_IND MPU6050_xout_reg_addr = MPU6050_REG_XOUT;




// // Set Active mode.
// static uint8_t NRF_TWI_MNGR_BUFFER_LOC_IND default_config[] = { 0x6b, 0x20};
// static uint8_t NRF_TWI_MNGR_BUFFER_LOC_IND default_config2[] = { 0x6c, 0xc0};
// static uint8_t NRF_TWI_MNGR_BUFFER_LOC_IND default_config3[] = { 0x19, 0x00};

static uint8_t NRF_TWI_MNGR_BUFFER_LOC_IND default_config[] = { 0x6b, 0x00};
static uint8_t NRF_TWI_MNGR_BUFFER_LOC_IND default_config2[] = { 0x1c, 0x10};
static uint8_t NRF_TWI_MNGR_BUFFER_LOC_IND default_config3[] = { 0x1b, 0x10};


nrf_twi_mngr_transfer_t const MPU6050_init_transfers[MPU6050_INIT_TRANSFER_COUNT] =
{
    NRF_TWI_MNGR_WRITE(MPU6050_ADDR, default_config, sizeof(default_config), 0),
    NRF_TWI_MNGR_WRITE(MPU6050_ADDR, default_config2, sizeof(default_config2), 0),
    NRF_TWI_MNGR_WRITE(MPU6050_ADDR, default_config3, sizeof(default_config3), 0)


};
