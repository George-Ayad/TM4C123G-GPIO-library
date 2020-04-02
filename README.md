# TM4C123G-GPIO-library
ASU CSE 318 Lab Group Assignment - TM4C123G Tiva-C GPIO management library

Github repo link:	https://github.com/George-Ayad/TM4C123G-GPIO-library



## Usage

pins are defined by port then pin number
example :

PA4 - pin 4 of port A



### pinmode()

Use the pinmode(pin, setup)  to set any given pin to INPUT, OUTPUT, input with PULLUP or input with PULLDOWN
example: 

```C
pinmode(PF1, OUTPUT);
```

or 

```c
pinmode(PF0, PULLUP);
```



### pinwrite()
User pinwrite(pin, state) to set the state of an output pin to HIGH or LOW
example:

```c
pinwrite(PF1, HIGH);
```



### pinread()
User pinread(pin) to read the state of an input pin which is HIGH or LOW
example:

```c
if(pinread(PF0) == LOW) pinwrite(PF1, HIGH);
```





## Team Members :
1. Omar Zohdi - 17p8190
2. George Guirguis -17p8181
3. Abanoub Tarek - 17p8196
4. Fady Mina - 17p8187

