void jugar1v1(char **Tablero, int filas, int columnas){
#define JUGADOR1 1
#define JUGADOR2 2
int turno, opcion, noMoreMoves = 1;
int aux;
int vec[4];
int terminado=0;

turno = randInt(1,2);

printf("La partida ha comenzado!\n");
printf("Empieza el jugador %d.\n",turno);
while (terminado == 0){

    switch(turno){

        case JUGADOR1:

            if(noMoreMoves == 0){ // si el jugador anterior se quedo sin movimientos. (se indico que no hay movimientos en
                    completarRestantes(Tablero,filas,columnas,turno); //rellena los casilleros vacios con fichas del jugador1.
                    terminado = 1;
                    imprimirTablero(Tablero,filas,columnas);
                    break;}

            noMoreMoves = quedanJugadas(Tablero,filas,columnas,turno); //0 si NO hay jugadas 1 si hay.

            if(noMoreMoves == 0){
                turno = JUGADOR2;
                break;}

            else{
                printf("Turno jugador 1.\n");
                imprimirTablero(Tablero,filas,columnas);
                opcion = menuOpciones();    //1- jugada 2-guardar 3-quit (y pregunta si queres guardar)

                    switch(opcion){

                            case 1: //jugada   //   //validar la jugada y capturar fichas luego de la jugada.
                                    do{

                                        if( leerJugada(vec) ){
                                            aux = jugadaValida(Tablero,vec,turno);
                                            if ( aux == 1 ){
                                                realizarJugada(Tablero,vec,turno);
                                                }
                                            else if(aux == -1){
                                                printf("No se encontro una ficha en esa posicion.\n");
                                            }
                                            else{
                                            printf("Movimiento invalido para la ficha indicada.\n");}
                                        }
                                        else{
                                            printf("Ingreso invalido.\n");
                                            aux = -1;
                                        }

                                    }while(aux != 1);

                                    break;

                            case 2: break;

                            case 3: break;
                        }
                }

            turno = JUGADOR2;
            break;


        case JUGADOR2:


            if(noMoreMoves == 0){ 
                    completarRestantes(Tablero,filas,columnas,turno); 
                    terminado = 1;
                    imprimirTablero(Tablero,filas,columnas);
                    break;}

            noMoreMoves = quedanJugadas(Tablero,filas,columnas,turno); //0 si NO hay jugadas 1 si hay.

            if(noMoreMoves == 0){
                turno = JUGADOR2;
                break;}

            else{
                printf("Turno jugador 2.\n");
                imprimirTablero(Tablero,filas,columnas);
                opcion = menuOpciones();    //1- jugada 2-guardar 3-quit (y pregunta si queres guardar)

                    switch(opcion){

                            case 1: //jugada   //   //validar la jugada y capturar fichas luego de la jugada.
                                    do{

                                        if( leerJugada(vec) ){
                                            aux = jugadaValida(Tablero,vec,turno);
                                            if ( aux == 1 ){
                                                realizarJugada(Tablero,vec,turno);
                                                }
                                            else if(aux == -1){
                                                printf("No se encontro una ficha en esa posicion.\n");
                                            }
                                            else{
                                            printf("Movimiento invalido para la ficha indicada.\n");}
                                        }
                                        else{
                                            printf("Ingreso invalido.\n");
                                            aux = -1;
                                        }

                                    }while(aux != 1);

                                    break;

                            case 2: break;//guardar

                            case 3: break; //quit and ask for save
                    }
                }

            turno = JUGADOR1;
            break;

    }//switch
}//while
printf("FIN DEL JUEGO!\n");
}//funcion
