/*
 * Test timer1 in cc2530 in IAR
 *
 * @author Qiu Ying <qiuying@mail.nwpu.edu.cn>
 * @date 2012/12/04
 * @description
 */

#include <ioCC2530.h>

#pragma vector=T1_VECTOR
__interrupt void SIG_T1(void )
{
    /* channel 0 overflow */
    if ((T1CCTL0&(1<<6)) && (T1STAT & 1)) {
        T1CCTL0 &= ~(1<<6); /* stop channel 0 */
        P0_0 ^= 1;
    }

    /* timer1 overflow */
    if (T1STAT&(1<<5)) {
        P0_1 ^= 1;
    }
}

void main(void)
{
    /* set clock to 32MHz */
    SLEEPCMD &= ~0x04;
    while(!(SLEEPSTA & 0x40));
    CLKCONCMD &= ~0x47;

    /* set P0 output */
    P0SEL = 0xFC;
    P0DIR = 0x03;
    P0 = 0x00;

    /* set timer1 */
    T1CNTL = 0;
    T1CNTH = 0;
    T1CTL = 0x0d;
    TIMIF = 0x40;

    /* set timer1 channel 0 */
    T1CCTL0 = 0x44;

    /* enable timer1 interrupt */
    T1IE = 1;

    /* enable global interrupt */
    EA = 1;

    while(1) {
    }
}
