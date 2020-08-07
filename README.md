<h1> PROYECTO DE FIN DE CICLO DEL CURSO DE MICROCONTROLADORES</h1>
<h2>DISEÑO DE PROTOTIPO DE ROBOT DE CUATRO MOTORES CONTROLADO A DISTANCIA</h1>
<img src="https://elcomercio.pe/resizer/pLymX33bz6ov6RJxMU8g4gZxjek=/640x0/smart/arc-anglerfish-arc2-prod-elcomercio.s3.amazonaws.com/public/7WJFMMYD3VFGXNTXORNJPOVJSQ.jpg">

## DESCRIPCION DEL PROYECTO
el robot funciona a partir de datos recibidos por el puerto UART1.
- e: habilita todo el funcionamiento.
- [0-9]: regula la velocidad de los motores (PWM).
- w: el robot avanza.
- s: el robot retrocede.
- a: el robot gira a la derecha.
- d: el robot gira a la izquierda.
- t: mide la temperatura.
- x: detiene el robot.
para que el robot entre en funcionamiento lo primero que se le envia es una e.
## FINALIDAD DEL PROYECTO
este proyecto es un prototipo basico del control de un robot de 4 ruedas, el cual servirá como base para futuros proyectos.
## MATERIALES USADOS
- dsPIC33fj32mc204
- hc-05
- 4 motores dc 
- una pantalla lcd 16x2
- un sensor de temperatura LM35
- un led azul
- 5 leds verdes y 5 leds rojos
- 2 l293d
- un buzzer
- un transistor 2n2222a
## LINK
hoja de datos [`datasheet`](http://ww1.microchip.com/downloads/en/DeviceDoc/70283J.pdf)
### AUTORES
- Quino Briceño Jeffry
- Jara Morales Stefhano
- Carrillo Marin Diego
- Herrera Ayala Anderson
