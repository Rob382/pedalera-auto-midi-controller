# Pedalera-auto-midi-controller (BETA)
Este proyecto es el diseño de una botonera como modificación a un pedal de looper para guitarra la cual automatiza secuencias de pulsaciones a una velocidad que no puede ser replicada por una persona, además se le agregó una segunda función como controlador midi

El diseño está hecho para no requerir de un ordenador para ser configurado, todo se puede hacer desde los mismos botones controlando distintos menús internos.

### Modificaciónes de hardware
Se modificó agregando 9 botones al equipo ya existente los cuales se programan para realizar secuencias de pulsaciones combinando las diferentes funciones de fábrica.

El diseño añade además sincronización con metrónomo que se puede activar, desactivar y configurar desde la misma pedalera.

Posee 50 bancos de memoria para los presets que son guardados en la memoria eeprom, por tanto se mantienen despúes de apagar el equípo y hasta que sean borrados manualmente o por otro programa.

### Controlador midi
Se agregó una función secundaria como controlador midi por usb, haciendolo más versátil ya que no depende del pedal looper (al cual automatiza con el modo principal).

Trabaja en base a 8 secciónes que con los mismos botones se puede cambiar de "plantilla" en la cual a cada pulsador se le configura un comando midi en especial, alcanzando así hasta 68 distintos comandos midi.

Este controlador midi también posee 40 distintos bancos de memoria para almacenar la configuración de comandos.
