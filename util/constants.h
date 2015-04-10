/**
 \file 		constants.h
 \author	michael.zohner@ec-spride.de
 \copyright	________________
 \brief		File containing all constants used throughout the source
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "typedefs.h"

//Defines for parameterizing the OT extension
#define DEBUG
//#define FIXED_KEY_AES_HASHING
//#define AES_OWF
#define VERIFY_OT
//#define DEBUG_OT_HASH_IN
//#define DEBUG_OT_HASH_OUT
//#define DEBUG_OT_SEED_EXPANSION
//#define DEBUG_BASE_OT_HASH_RET
//#define DEBUG_RECEIVE_THREAD
//#define DEBUG_SEND_THREAD
//#define OTTiming
//#define HIGH_SPEED_ROT_LT
//#define DEBUG_ALSZ_CHECKS
//#define DEBUG_ALSZ_CHECKS_INPUT
//#define DEBUG_ALSZ_CHECKS_OUTPUT



#define AES_KEY_BITS			128
#define AES_KEY_BYTES			16
#define AES_BITS				128
#define AES_BYTES				16
#define LOG2_AES_BITS			ceil_log2(AES_BITS)

#define NUMOTBLOCKS 256
#define MAX_NUM_COMM_CHANNELS 256
#define ADMIN_CHANNEL MAX_NUM_COMM_CHANNELS-1
#define OT_ADMIN_CHANNEL ADMIN_CHANNEL-1



enum field_type {
	P_FIELD, ECC_FIELD
};

static const seclvl ST = { 40, 80, 1024, 160, 163 };
static const seclvl MT = { 40, 112, 2048, 192, 233 };
static const seclvl LT = { 40, 128, 3072, 256, 283 };
static const seclvl XLT = { 40, 192, 7680, 384, 409 };
static const seclvl XXLT = { 40, 256, 15360, 512, 571 };

enum ot_ext_prot {IKNP, ALSZ, NNOB};

enum snd_ot_flavor { Snd_OT, Snd_C_OT, Snd_R_OT, Snd_GC_OT, Snd_OT_LAST };
enum rec_ot_flavor { Rec_OT, Rec_R_OT, Rec_OT_LAST };

const uint8_t m_vFixedKeyAESSeed[AES_KEY_BYTES] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF };
/** \var m_vSeed
 \brief Static seed for various testing functionalities
 */
const uint8_t m_vSeed[AES_KEY_BYTES] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF };

static const char* getSndFlavor(snd_ot_flavor stype) {
	switch (stype) {
	case Snd_OT: return "Snd_OT";
	case Snd_C_OT: return "Snd_C_OT";
	case Snd_R_OT: return "Snd_R_OT";
	case Snd_GC_OT: return "Snd_GC_OT";
	default: return "unknown snd type";
	}
}

static const char* getRecFlavor(rec_ot_flavor rtype) {
	switch (rtype) {
	case Rec_OT: return "Rec_OT";
	case Rec_R_OT: return "Rec_R_OT";
	default: return "unknown rec type";
	}
}
#endif /* CONSTANTS_H_ */