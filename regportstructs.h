#ifndef __REGPORTSTRUCTS__
#define __REGPORTSTRUCTS__

struct PORTBbits_t
{
   uint8_t pb0:1;
   uint8_t pb1:1;
   uint8_t pb2:1;
   uint8_t pb3:1;
   uint8_t pb4:1;
   uint8_t pb5:1;
   uint8_t pb6:1;
   uint8_t pb7:1;
};

#define PORTBbits (*(volatile struct PORTBbits_t *)_SFR_MEM_ADDR(PORTB))

struct DDRBbits_t
{
   uint8_t ddb0:1;
   uint8_t ddb1:1;
   uint8_t ddb2:1;
   uint8_t ddb3:1;
   uint8_t ddb4:1;
   uint8_t ddb5:1;
   uint8_t ddb6:1;
   uint8_t ddb7:1;
};

#define DDRBbits (*(volatile struct DDRBbits_t *)_SFR_MEM_ADDR(DDRB))



struct PORTCbits_t
{
   uint8_t pc0:1;
   uint8_t pc1:1;
   uint8_t pc2:1;
   uint8_t pc3:1;
   uint8_t pc4:1;
   uint8_t pc5:1;
   uint8_t pc6:1;
   uint8_t unusd:1;
};

#define PORTCbits (*(volatile struct PORTCbits_t *)_SFR_MEM_ADDR(PORTC))

struct DDRCbits_t
{
   uint8_t ddc0:1;
   uint8_t ddc1:1;
   uint8_t ddc2:1;
   uint8_t ddc3:1;
   uint8_t ddc4:1;
   uint8_t ddc5:1;
   uint8_t ddc6:1;
   uint8_t unusd:1;
};

#define DDRCbits (*(volatile struct DDRCbits_t *)_SFR_MEM_ADDR(DDRC))




struct PORTDbits_t
{
   uint8_t pd0:1;
   uint8_t pd1:1;
   uint8_t pd2:1;
   uint8_t pd3:1;
   uint8_t pd4:1;
   uint8_t pd5:1;
   uint8_t pd6:1;
   uint8_t pd7:1;
};

#define PORTDbits (*(volatile struct PORTDbits_t *)_SFR_MEM_ADDR(PORTD))

struct DDRDbits_t
{
   uint8_t ddd0:1;
   uint8_t ddd1:1;
   uint8_t ddd2:1;
   uint8_t ddd3:1;
   uint8_t ddd4:1;
   uint8_t ddd5:1;
   uint8_t ddd6:1;
   uint8_t ddd7:1;
};

#define DDRDbits (*(volatile struct DDRDbits_t *)_SFR_MEM_ADDR(DDRD))


// external interrupts

struct EICRAbits_t
{
   uint8_t isc00:1;
   uint8_t isc01:1;
   uint8_t isc10:1;
   uint8_t isc11:1;
   uint8_t unusd:4;
};

#define EICRAbits (*(volatile struct EICRAbits_t *)_SFR_MEM_ADDR(EICRA))


struct EIMSKbits_t
{
   uint8_t int0:1;
   uint8_t int1:1;
   uint8_t unusd:6;
};

#define EIMSKbits (*(volatile struct EIMSKbits_t *)_SFR_MEM_ADDR(EIMSK))


struct PCICRbits_t
{
   uint8_t pcie0:1;
   uint8_t pcie1:1;
   uint8_t pcie2:1;
   uint8_t unusd:5;
};

#define PCICRbits (*(volatile struct PCICRbits_t *)_SFR_MEM_ADDR(PCICR))


struct PCMSK2bits_t
{
  uint8_t pcint16:1;
  uint8_t pcint17:1;
  uint8_t pcint18:1;
  uint8_t pcint19:1;
  uint8_t pcint20:1;
  uint8_t pcint21:1;
  uint8_t pcint22:1;
  uint8_t pcint23:1;
};

#define PCMSK2bits (*(volatile struct PCMSK2bits_t *)_SFR_MEM_ADDR(PCMSK2))


struct PCMSK1bits_t
{
  uint8_t pcint8:1;
  uint8_t pcint9:1;
  uint8_t pcint10:1;
  uint8_t pcint11:1;
  uint8_t pcint12:1;
  uint8_t pcint13:1;
  uint8_t pcint14:1;
  uint8_t unusd:1;
};

#define PCMSK1bits (*(volatile struct PCMSK1bits_t *)_SFR_MEM_ADDR(PCMSK1))

struct PCMSK0bits_t
{
  uint8_t pcint0:1;
  uint8_t pcint1:1;
  uint8_t pcint2:1;
  uint8_t pcint3:1;
  uint8_t pcint4:1;
  uint8_t pcint5:1;
  uint8_t pcint6:1;
  uint8_t pcint7:1;
};

#define PCMSK0bits (*(volatile struct PCMSK0bits_t *)_SFR_MEM_ADDR(PCMSK0))


// serial

// UDR0: data in and out

// UCSR0A – USART Control and Status Register 0 A

struct UCSR0Abits_t
{
  uint8_t mpcm0:1;
  uint8_t u2x0:1;
  uint8_t upe0:1;
  uint8_t dor0:1;
  uint8_t fe0:1;
  uint8_t udre0:1;
  uint8_t txc0:1;
  uint8_t rxc0:1;
};

#define UCSR0Abits (*(volatile struct UCSR0Abits_t *)_SFR_MEM_ADDR(UCSR0A))


// timer 0

struct TCCR0Abits_t
{
  uint8_t wgm00:1;
  uint8_t wgm01:1;
  uint8_t unusd0:1;
  uint8_t unusd1:1;
  uint8_t com0b0:1;
  uint8_t com0b1:1;
  uint8_t com0a0:1;
  uint8_t com0a1:1;
};

#define TCCR0Abits (*(volatile struct TCCR0Abits_t *)_SFR_MEM_ADDR(TCCR0A))


struct TCCR0Bbits_t
{
  uint8_t  cs0:3;
  uint8_t wgm02:1;
  uint8_t unusd:2;
  uint8_t foc0b:1;
  uint8_t foc0a:1;
};

#define TCCR0Bbits (*(volatile struct TCCR0Bbits_t *)_SFR_MEM_ADDR(TCCR0B))


struct TIMSK0bits_t
{
  uint8_t toie0:1;
  uint8_t ocie0a:1;
  uint8_t ocie0b:1;
  uint8_t :5;
};

#define TIMSK0bits (*(volatile struct TIMSK0bits_t *)_SFR_MEM_ADDR(TIMSK0))



// timer 1

struct TCCR1Abits_t
{
   uint8_t wgm10:1;
   uint8_t wgm11:1;
   uint8_t unusd0:1;
   uint8_t unusd1:1;
   uint8_t com1b0:1;
   uint8_t com1b1:1;
   uint8_t com1a0:1;
   uint8_t com1a1:1;
};

#define TCCR1Abits (*(volatile struct TCCR1Abits_t *)_SFR_MEM_ADDR(TCCR1A))

struct TCCR1Bbits_t
{
   uint8_t cs1:3;
   uint8_t wgm12:1;
   uint8_t wgm13:1;
   uint8_t unusd0:1;
   uint8_t ices1:1;
   uint8_t icnc1:1;
};

#define TCCR1Bbits (*(volatile struct TCCR1Bbits_t *)_SFR_MEM_ADDR(TCCR1B))


// timer 2

struct TCCR2Abits_t
{
   uint8_t wgm20:1;
   uint8_t wgm21:1;
   uint8_t unusd0:1;
   uint8_t unusd1:1;
   uint8_t com2b0:1;
   uint8_t com2b1:1;
   uint8_t com2a0:1;
   uint8_t com2a1:1;
};

#define TCCR2Abits (*(volatile struct TCCR2Abits_t *)_SFR_MEM_ADDR(TCCR2A))

struct TCCR2Bbits_t
{
   uint8_t cs2:3;
   uint8_t wgm22:1;
   uint8_t unusd0:1;
   uint8_t unusd1:1;
   uint8_t foc2b:1;
   uint8_t foc2a:1;
};

#define TCCR2Bbits (*(volatile struct TCCR2Bbits_t *)_SFR_MEM_ADDR(TCCR2B))

struct TIMSK2bits_t
{
   uint8_t toie2:1;
   uint8_t ocie2a:1;
   uint8_t ocie2b:1;
   uint8_t unusd:5;
};

#define TIMSK2bits (*(volatile struct TIMSK2bits_t *)_SFR_MEM_ADDR(TIMSK2))

struct TIFR2bits_t
{
   uint8_t tov2:1;
   uint8_t ocf2a:1;
   uint8_t ocf2b:1;
   uint8_t unusd:5;
};

#define TIFR2bits (*(volatile struct TIFR2bits_t *)_SFR_MEM_ADDR(TIFR2))



// ADC

struct ADMUXbits_t
{
   uint8_t mux0:4;
   uint8_t unusd1:1;
   uint8_t adlar:1;
   uint8_t refs0:1;
   uint8_t refs1:1;
};

#define ADMUXbits (*(volatile struct ADMUXbits_t *)_SFR_MEM_ADDR(ADMUX))

struct ADCSRAbits_t
{
   uint8_t adps0:3;
   uint8_t adie:1;
   uint8_t adif:1;
   uint8_t adate:1;
   uint8_t adsc:1;
   uint8_t aden:1;
};

#define ADCSRAbits (*(volatile struct ADCSRAbits_t *)_SFR_MEM_ADDR(ADCSRA))

struct ADCSRBbits_t
{
   uint8_t adts0:3;
   uint8_t unusd0:3;
   uint8_t acme:1;
   uint8_t unusd1:1;
};

#define ADCSRBbits (*(volatile struct ADCSRBbits_t *)_SFR_MEM_ADDR(ADCSRB))


#endif
