# AVR software engineering
Tips regarding ATMega328 programming.

# Introduction

I hate black boxes and IDEs in general, and MPLAB and Arduino IDE in particular. They try to support
far too many functions, which is detrimental to their ergonomy and efficiency; and they
break the KISS rule on top!

Instead I use a wonderful programming editor (https://pulsar-edit.dev/) to write my code together
with a Make building process.

However when doing so, you loose the single selling point of these IDEs aka the libraries. So admittedly
I had either to write libraries by myself, or to find some on the net. Doing so gives you the advantage 
that your own library solves your own problem in your own way. That is huge when you think about it.
This is demonstrated in one of the files you'll find here: `regportstructs.h` which is a complete model
of the AT328 in terms of C structs; they allow you to write such nice things as `PORTBbits.pb0 = 1;` instead
of the ugly macro stuff you'll find elsewhere. 

# Contents

So this repository holds my standard Makefile and a small code sample using the above mentioned header.

Ah and a last thing, I do not use the bootloader at all. I burn the code directly in the processor with
`avrdude`.


