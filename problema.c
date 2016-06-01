case NUMERO: //pensar en dos digitos
					{
						if(isdigit(c)) //segundo numero, guardado en aux por 10 mas c me da nro de dos digitos
							{
								vec_posiciones[i]=(aux*10)+c;
								estado=NUMERO;
								flag=0;
								i++;
								break;
							}
						else if(flag == 1 && c == ',')  //caso si hay un solo nro, guardo el valor de aux y restauro flag
							{
								vec_posiciones[i]=aux;
								i++;
								estado=COMA;
								flag=0;
								break;
