/*
 * OperationProtocols.h
 *
 * Created: 06/01/2013 17:24:48
 *  Author: NASSER
 */ 


#ifndef OPERATIONPROTOCOLS_H_
#define OPERATIONPROTOCOLS_H_

/// ************************ Protocols
#define PROTOCOL_RESULT int

// ***** Global results
#define  PROTOCOL_SUCCESS 			0
#define  PROTOCOL_FAILED 			1
#define  PROTOCOL_TIMEOUT			2

// ***** ASIC configuration
#define  PROTOCOL_CONFIG_FAILED 	3
#define  PROTOCOL_WAIT_CONFIG		4
#define  PROTOCOL_CONFIG_DONE		5

// ***** Computer connection
#define  PROTOCOL_INVALID_REQUEST 	6
#define  PROTOCOL_INVALID_USB_DATA  7

// ***** JOB Process
#define  PROTOCOL_NONCE_FOUND 		8
#define  PROTOCOL_NONCE_NOT_FOUND 	9
#define  PROTOCOL_PROCESSING_NONCE  10

// ***** Flash programming
#define  PROTOCOL_FLASH_OK			11
#define  PROTOCOL_FLASH_FAILED		12

// ***** Req numbers
#define PROTOCOL_REQ_INFO_REQUEST			2+65  // C
#define PROTOCOL_REQ_HANDLE_JOB				3+65  // D
#define PROTOCOL_REQ_HANDLE_JOB_P2POOL		15+65 // P
#define PROTOCOL_REQ_GET_STATUS				5+65  // F
#define PROTOCOL_REQ_ID						6+65  // G
#define PROTOCOL_REQ_GET_FIRMWARE_VERSION	9+65  // J
#define PROTOCOL_REQ_TEMPERATURE  			11+65 // L  (ZLX)
#define PROTOCOL_REQ_BLINK					12+65 // M
#define	PROTOCOL_REQ_BUF_PUSH_JOB			13+65 // N
#define	PROTOCOL_REQ_BUF_STATUS			  	14+65 // O
#define PROTOCOL_REQ_BUF_FLUSH				16+65 // Q ZQX
#define PROTOCOL_REQ_GET_VOLTAGES			19+65 // T
#define PROTOCOL_REQ_PRESENCE_DETECTION		17+65 // R // Respond with something if we don't have an ID attached to us...
#define PROTOCOL_REQ_GET_CHAIN_LENGTH		23+65 // X
#define PROTOCOL_REQ_SET_FREQ_FACTOR		21+65 // V
#define PROTOCOL_REQ_GET_FREQ_FACTOR		10+65 // K
#define PROTOCOL_REQ_SET_XLINK_ADDRESS		4+65  // E
#define PROTOCOL_REQ_XLINK_ALLOW_PASS		7+65  // H
#define PROTOCOL_REQ_XLINK_DENY_PASS		8+65  // I
#define PROTOCOL_REQ_ECHO					0+65  // A // Echoes back whatever it hears
#define PROTOCOL_REQ_TEST_COMMAND			1+65  // B // Custom Command

// ***** Functions
PROTOCOL_RESULT Protocol_Echo			 (void);
PROTOCOL_RESULT Protocol_Test_Command	 (void);
PROTOCOL_RESULT Protocol_handle_job		 (void);
PROTOCOL_RESULT Protocol_handle_job_p2p	 (void);
PROTOCOL_RESULT Protocol_info_request	 (void);
PROTOCOL_RESULT Protocol_get_status		 (void);
PROTOCOL_RESULT Protocol_get_voltages	 (void);
PROTOCOL_RESULT Protocol_get_firmware_version(void);
PROTOCOL_RESULT Protocol_id				 (void);
PROTOCOL_RESULT Protocol_Blink			 (void);
PROTOCOL_RESULT Protocol_temperature	 (void);
PROTOCOL_RESULT Protocol_chain_forward   (char iTarget, char* sz_cmd, unsigned short iCmdLen);

// Initiate process for the next job from the buffer
// And returns previous popped job result
PROTOCOL_RESULT  Protocol_P2P_BUF_PUSH(void);

// Returns only the status of the last processed job
// from the buffer, and will not initiate the next job process
PROTOCOL_RESULT	Protocol_P2P_BUF_STATUS (void);

// This function flushes the P2P FIFO
PROTOCOL_RESULT  Protocol_P2P_BUF_FLUSH(void);

// This sets/gets our ASICs frequency
PROTOCOL_RESULT  Protocol_get_freq_factor(void);
PROTOCOL_RESULT  Protocol_set_freq_factor(void);

// Our XLINK Support...
PROTOCOL_RESULT  Protocol_set_xlink_address(void);
PROTOCOL_RESULT  Protocol_xlink_allow_pass(void);
PROTOCOL_RESULT  Protocol_xlink_deny_pass(void);
PROTOCOL_RESULT  Protocol_xlink_presence_detection(void);

// Flush the P2P job into engine
void Flush_p2p_buffer_into_engines(void);


// Some AUX functions
void 	init_mcu_led(void);
void	blink_fast(void);
void	blink_slow(void);
void 	blink_medium(void);
void 	blink_high_freq(void);

int		Delay_1(void);
int 	Delay_2(void);
int 	Delay_3(void);

// Some Auxiliary functions
void clear_buffer(char* sz_stream, unsigned int ilen);
void stream_to_hex(char* sz_stream, char* sz_hex, unsigned int i_stream_len, unsigned int *i_hex_len);

#endif /* OPERATIONPROTOCOLS_H_ */