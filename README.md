[English](https://github.com/matheussantanads/microcontroladores/blob/main/README.md) | Portuguese

# Microcontroladores com PIC16F887

Vamos adotar a frequência do cristal oscilador $F_{xtal}$ igual a 20MHz.

**Ciclo de Máquina ($C_M$)** é o período de cada clock no cristal oscilador
$$C_M=\dfrac{1}{F_{xtal}}$$

Então o ciclo de máquina é de $0,00000005s$ ou $0,00005ms$ ou $0,05\mu s$ ou $50ns$.

**Ciclo de Instrução ($C_I$)** é o tempo no qual o microcontrolador demora para executar uma instrução
$$C_I=\dfrac{4}{F_{xtal}}$$
Então o ciclo de instrução é de $0,0000002s$ ou $0,0002ms$ ou $0,2\mu s$ ou $200ns$.

# [Experimento 1](https://github.com/matheussantanads/microcontroladores/tree/main/01_Blink)
Piscar um LED em intervalos de 0,5s.