# Pico y cedula
Las medidas de aislamiento y restricción de movilidad se han debido endurecer en los siguientes seis meses, debido a los problemas asociados con la deficiente atención médica, la vulnerabilidad de la población en términos sanitarios y aspectos culturales. Teniendo en cuenta que se tomó la decision de implementar un pico y cédula estricto observando el último dígito de la cédula (dia par = cédula que termina en cero y par, dia impar = cédula que termina en número impar), y utilizando un archivo que contiene los números de cédula para una población especifica obtenido del último censo electoral de 2019, responda las siguientes preguntas:

-¿ Cuántas personas con cédula par e impar saldrían en cada dia correspondiente para su pico y cédula de los meses de febrero, marzo y abril? (Tenga en cuenta que cada mes tiene dias diferentes y asignaciones de fecha por dia diferentes).

-¿Cuántas veces las personas con pico y cédula par, pueden salir sin restricción los dias sábado?.

-¿Cuántas personas con pico y cédula impar pueden salir sin restricción los dias domingo?.

-Las personas con cédula de identificación de 10 dígitos son personas de 18 a 20 años. ¿Cuántas son y cómo es la distribución de salida por mes los fines de semana?

-Proporcione datos para dar información de análisis a los tomadores de decisiones políticos y ver si es proporcional y justa la medida del pico y cédula para esa población, observando números pares e impares, tomando, la población en general (cantidad total de habitantes), personas de menos de 20 años (cédulas con diez cifras), personas de mayores de 60 años (Entre 6 y 7 cifras) y extranjeros (cédulas con menos de 7 cifras).

## Solucion
Para la realizacion del diseño en paralelo se definieron primero 5 tareas: contar dias pares e impares mes 1, contar dias pares e impares mes 2, contar dias pares e impares mes 3, contar cedulas pares e impares y los numeros de digitos en estas y la impresion de las cuentas. Una vez definidas estas tareas se procedio a distribuirla sobre 4 procesos usando MPI:

- proceso master:este proceso realiza lo siguiente:
   - le asigna a los otros tres procesos las tareas de contar dias pares e impares mes 1, contar dias pares e impares mes 2 y contar dias pares e impares mes 3.
   - cuenta cedulas pares e impares y los numeros de digitos en estas.
   - recibe el resultado devuelto por los otros 3 procesos.
   - imprime los resultados de todos los procesos incluyendose.
   
- proceso worker 1:  cuenta los dias pares e impares mes 1, y luego le envia los resultados al proceso master.
- proceso worker 2:  cuenta los dias pares e impares mes 2, y luego le envia los resultados al proceso master.
- proceso worker 3:  cuenta los dias pares e impares mes 3, y luego le envia los resultados al proceso master.
