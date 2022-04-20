# ArchivoTC1030
Escribir un método main que inicialice el juego
2. El método main debe encontrarse en un archivo denominado snakes.cpp
3. Escribir una clase denominada MyGame que contenga los atributos y métodos necesarios para 
representar el juego
4. Dentro de la clase MyGame crear un método llamado start de tipo void que sirva para empezar la 
ejecución del juego
5. En el método main crea una nueva instancia de tu juego y manda llamar el método start. 
6. El siguiente snippet muestra la estructura mínima que debería tener tu archivo snakes.cpp
7. Utiliza el dado que te hemos proveido dentro del archivo dice.cpp. Impórtalo en tu en tu programa 
principal y utiliza el método roll() para simular el dado. Puedes hacer esto utilizando objetos de la 
siguiente manera:
![image](https://user-images.githubusercontent.com/95431110/164143483-43333663-b84a-4ebe-84d0-920be44bccee.png)

8. Los mensajes impresos en la consola NO deben llevar espacios en blanco al final de cada línea, y debe 
haber un salto de línea entre cada mensaje
9. Los siguientes son ejemplos de información de cada turno
1 1 1 4 N 5 -> Indica que en el turno 1, el jugador 1 está en la casilla 1, y que al tirar el dado le 
salió el número 4, lo cuál lo llevaría a una casilla Normal, que sería la número 5
6 2 3 6 S 3 -> Indica que en el turno 6 el jugador 2 estaba en la casilla 3, y que saco un número 6 
en el dado, lo cuál debió llevarlo a la casilla 9, misma que tiene una serpiente y por ello retrocedió 
6 casillas, quedando nuevamente en la casilla 3
10. El programa debe regresar 0 al finalizar la ejecución
