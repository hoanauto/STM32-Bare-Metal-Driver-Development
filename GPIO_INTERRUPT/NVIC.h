
/** _NVIC - Size of Registers Arrays */
#define F1_NVIC_ISER_COUNT                      8u
#define F1_NVIC_ICER_COUNT                      8u
#define F1_NVIC_ISPR_COUNT                      8u
#define F1_NVIC_ICPR_COUNT                      8u
#define F1_NVIC_IABR_COUNT                      8u
#define F1_NVIC_IP_COUNT                        32u

/** _NVIC - Register Layout Typedef */
typedef struct {
  volatile unsigned int ISER[F1_NVIC_ISER_COUNT];         /**< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
					 unsigned int RESERVED_0[24];
  volatile unsigned int ICER[F1_NVIC_ICER_COUNT];         /**< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
           unsigned int RESERVED_1[24];
  volatile unsigned int ISPR[F1_NVIC_ISPR_COUNT];         /**< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
           unsigned int RESERVED_2[24];
  volatile unsigned int ICPR[F1_NVIC_ICPR_COUNT];         /**< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
           unsigned int RESERVED_3[24];
  volatile unsigned int IABR[F1_NVIC_IABR_COUNT];         /**< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
					 unsigned char RESERVED_4[224];
  volatile unsigned char IP[F1_NVIC_IP_COUNT];            /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
//					 unsigned char RESERVED_5[2576];
//  volatile unsigned int STIR;                             /**< Software Trigger Interrupt Register, offset: 0xE00 */
} NVIC_Type;

/* _NVIC - Peripheral instance base addresses */
/** Peripheral _NVIC base address */
#define NVIC_BASE                            (0xE000E100u)
/** Peripheral _NVIC base pointer */
#define NVIC                                 ((NVIC_Type *)NVIC_BASE)