fanIR
=====

The project builds a remote control system for a floor fan. Care was taken as to alter the fan itself as little as possible. The main hardware consists of a `servo`, an [`IR Receiver`](https://www.sparkfun.com/products/10266), an [`IR Remote`](https://www.sparkfun.com/products/11759), an [`Arduino Mini`](http://arduino.cc/en/Main/ArduinoBoardMini), and a `5V power supply`.

![promo](https://github.com/nlamprian/fanIR/wiki/assets/promo.jpg)

The control system is a finite state machine with 4 states (`off`, `speed_1`, `speed_2`, `speed_3`). The `remote` is able to switch the fan between those 4 states.

For more details on the construction process, take a look at the [wiki](https://github.com/nlamprian/fanIR/wiki/Tutorial) page. For an example of the system's performance, there is a short [video](https://www.youtube.com/watch?v=_2cOVIHtIOk) on YouTube.

The [project](https://codebender.cc/sketch:49068) is also available at codebender.
