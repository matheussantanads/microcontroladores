English | [Portuguese](https://github.com/matheussantanads/microcontroladores/blob/main/README_ptbr.md)

# Microcontrollers with PIC16F887

Let's adopt the frenquency of the crystal oscillator $F_{xtal}$ equal to 20MHz.

**Machine Cycle** is the period of each clock in the crystal oscillator.
$$\dfrac{1}{F_{xtal}}$$

Then the machine cycle is $0,00000005s$ or $0,00005ms$ or $0,05\mu s$ or $50ns$.

**Instruction Cycle** is the time it takes the microcontroller to execute an instruction
$$\dfrac{4}{F_{xtal}}$$
Then the instruction cycle is $0,0000002s$ or $0,0002ms$ or $0,2\mu s$ or $200ns$.

# [Experiment 1](https://github.com/matheussantanads/microcontroladores/tree/main/01_Blink)
Blink an LED at 0.5s intervals.