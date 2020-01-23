#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define tam 50
void Facil (int[], int[], int);
void Medio (int[], int[], int);
void Dificil (int[], int[], int);
void Puntuacion (char[][20], int[], int[]);
void Ingreso (char[], char[][20], int[], int[], int);
void OrdenaDatos (char[][20],int[], int[]);

void main()
{
    int op, count=0, puntos[tam]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, dificultad[tam]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char usuario[tam][20], pin[10];
    char FAC[10]={"FACIL"}, MED[10]="MEDI", DIF[10]="DIFI";
    do
    {
        printf("MENU\n1)Empezar\n2)Puntuacion\n3)Salir\nEscoja una opcion: ");
        scanf("%d",&op);
        switch(op)
        {
        	case 1:
        		
        		printf("Para escoger una dificultad, escriba su usario y uno d los tres siguientes codigos:\n");
                printf("Facil: FACIL\nMedio:MEDI\nDificil: DIFI\n");
                printf("Nombre de usuario: ");
                fflush(stdin);
                gets(usuario[count]);
                printf("Contrasena: ");
                gets(pin);
                do
                {
            	    if (strcmp(pin,FAC)==0||strcmp(pin, MED)==0||strcmp(pin,DIF)==0)
				    {
				        Ingreso (pin, usuario, puntos, dificultad, count);
				    }
				    else
				    {
				    	printf("Nombre de usuario: ");
    		            fflush(stdin);
    		            gets(usuario[count]);
    		            printf("Contrasena: ");
    		            gets(pin);
					}
				}while(strcmp(pin,FAC)!=0||strcmp(pin, MED)!=0||strcmp(pin,DIF)!=0);
                getch();
            	system("cls");
            break;
            case 2:
            	Puntuacion(usuario,puntos,dificultad);
            	getch();
            	system("cls");
            break;
            case 3:
            	exit(0);
            break;
            default:
            	printf("Opcion no valida, regresando a MENU...");
            	getch();
            	system("cls");
            break;
		}
		count++;
    }while (op!=3);
}
void Ingreso (char pin[10], char usuario[tam][20],int puntos[tam], int dificultad[tam], int count)
{
    if(strcmp(pin,"FACIL")==0)
    {
    	printf("Ha elegido la dificultad FACIL");
        Facil(puntos, dificultad, count);
    }
    else if (strcmp(pin,"MEDI")==0)
    {
        printf("Ha elegido la dificultad MEDIA");
        Medio(puntos, dificultad, count);
    }
    else if (strcmp(pin,"DIFI")==0)
    {
        printf("Ha elegido la dificultad DIFICIL");
        Dificil(puntos, dificultad, count);
    }
    main();
    
}
void Facil (int puntos[tam], int dificultad[tam], int count)
{
	int buenas[21]={0,2,2,1,0,2,1,0,1,0,2,2};//aquie pones las respuestas correctas
    int i,j,k,respondio;
    int pregunta[21]={0,2,2,1,0,2,1,0,1,0,2,2};
    srand(time(NULL));
	int Selrand;
	char preguntas[25][100]={"¿Quién fundo San Francisco de Quito? ", //AQui van preguntas
                             "¿Qué es la Colonia? ",
                             "¿Qué eran los obrajes?",
                             "¿Quién descubrió el Río Amazonas? ",
                             "¿Quiénes eran los criollos?",
                             "¿Cuál era el máximo Tribunal de Justicia durante la Colonia?",
                             "¿Qué eran las Mitas?",
                             "¿Qué países conformaron la Gran Colombia",
                             "¿De quién eran los ideales que conformaron la Gran Colombia?",
                             "¿Sobre que pareja en particular habla la Leyenda del Lago Titicaca?",
                             "¿Cómo era su religión?",
                             "¿Quién fue el último emperador inca?",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta"};
    char respuestas[25][3][60]={//aqui van respuestas
                               {"1.Sebastian de Benalcazar","2.Francisco Pizarro","3.Hernán Cortés"},
                               {"1.Período de sometimiento indígena","2.Período de independencia","3.Período de sometimiento español"},
                               {"1.Centros de producción de materia prima","2.Centros de producción de alimentos y medicina","3.Centros de producción textil, alpargatas,sogas"},
                               {"1.Francisco Pizarro","2.Francisco de Orellana","3.Atahualpa"},
                               {"1.Hijos de españoles nacidos en Ecuador","2.Trabajadores de los obrajes","3.Escalvos indígenos"},
                               {"1.Municipios","2.Asambleas","3.Real Audiencia de Quito"},
                               {"1.Impuestos","2.Trabajo de indígenas en las minas","3.Criollos"},
                               {"1.Ecuador,Colombia,Venezuela y Panamá","2.Chile,Ecuador y Argentina","3.Perú y Bolivia"},
                               {"1.Juan José Flores","2.Simón Bolivar","3.José de San Martin"},
                               {"1.Manco Capac y Mama Ocllo","2.Guayas y Quil","3.Solo habla sobre Atahualpa"},
                               {"1.Ateos","2.Monoteístas","3.Politeístas"},
                               {"1.Tupac Yupanqui","2.Huayna Capac","3.Atahualpa"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"}};
	
	Selrand=rand()%20;
	k=Selrand;
	for (i=0;i<5;i++)
	{
		if(k>20)
		{
			k=0;
		}
		printf("%d  %d  %s\n",i+1,k,preguntas[k]);
		for (j=0;j<3;j++)
		{
			printf("%s\n",respuestas[k][j]);
		}
		printf("Respuesta: ");
		scanf("%d",&respondio);
		if((respondio-1)==buenas[pregunta[k]])
		{
			printf("Correcto\n");
			puntos=puntos+100;
		}
		else
		{
			printf("Incorrecto\n");
		}
		k++;		
	}
	getch();
	system("cls");
}
void Dificil (int puntos[tam], int dificultad[tam], int count)
{
	int buenas[61]={0,2,2,1,2,0,1,0,0,2,1,0,2,2,0};//aquie pones las respuestas correctas
    int i,j,k,respondio;
    int pregunta[61]={0,2,2,1,2,0,1,0,0,2,1,0,2,2,0};
    srand(time(NULL));
	int Selrand, op;
	char preguntas[65][100]={"La primera universidad que se formó en la Colonia es:", 
                             "¿Durante la Colonia que personaje sobresalió en el campo de la escultura de la Escuela Quiteña?",
                             "¿Durante la Colonia cual fue el pintor que sobresalió?",
                             "¿A qué se consideraba reducciones?",
                             "Los Ayllus fueron comunidades campesinas que formaban parte de……………………y éstos a su vez formaban parte de ……………………",
                             "La relación Real de los Incas Gobernantes, se llamaba: ",
                             "Una definición correcta de Sapci sería: ",
                             "Las Tacllas fueron en el Incanato:",
                             "La Etnias Ichmay, Chancay y tallanes de la costa, cómo los pocras, cabanas, diaguitas, collas, de las Sierra; demuestran que el Estado Tahuantisuyo, Social y Culturalmente tuvo un carácter: ",
                             "¿Cuál fue el origen de la Revolución de las Alcabalas?",
                             "¿Qué hecho social se produjo en 1767 en las colonias españolas?",
                             "¿Cuántos años estuvo vigente la Gran Colombia?",
                             "El nexo entre el Estado Inca y el Pueblo fue: ",
                             "El Reino de los Huancas integró la Región del: ",
                             "¿Qué fueron las Panacas en la organización Social y Política del Estado Incaico?",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta"};
    char respuestas[65][3][60]={//aqui van respuestas
                               {"1.San Gregorio","2.Universidad Central","3.Universidad de Santo Tomás"},
                               {"1.Nicolas Goribar","2.Pedro Beón","3.José Olmos"},
                               {"1.Oswaldo Guayasamín","2.Nicolás Kingman","3.Miguel de Santiago"},
                               {"1.Religión","2.Adoctrinamiento de indígenas en la fe cristiana","3.Asamblea"},
                               {"1.Los suyos – los Huamanis","2.Los Hurin Saya- Los Hanan Saya","3.Los Huamanis- Los Suyos"},
                               {"1.Capac Cuna ","2.Realeza","3.Panaca"},
                               {"1.Extensión de terreno entregada a un Hatun Runa para ser usufructuada","2.Extensión de tierra entregada al Ayllu para ser trabajada por los Hatun Runas.","3.Cárceles del Estado"},
                               {"1.Palos encorvados y puntiagudos usados para arar la tierra","2.Prendas de vestir","3.Los caminos incas"},
                               {"1.Multinacional","2.Monocultural","3.Estrictamente quechua"},
                               {"1.Rechazo al pago de un nuevo impuesto del 5% sobre materia prima","2.Rechazo al intento de monopolizar el estado de la producción de aguardiente","3.Rechazo al pago de un nuevo impuesto del 2% sobre ventas y permutas"},
                               {"1.Expulsión de la inglesia","2.Expulsión de los jesuitas","3.LLegada de los españoles"},
                               {"1.10 años","2.7 años","3.8 meses"},
                               {"1.Los suyos","2.Los Huamanis","3.El Curaca"},
                               {"1.Collasuyo","2.Antisuyo","3.Chichaysuyo"},
                               {"1.Descendientes del Spa Inca","2.Los nobles de provincia","3.Lista real de Gobernantes"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"}};
	
	Selrand=rand()%20;
	k=Selrand;
	for (i=0;i<15;i++)
	{
		if(k>60)
		{
			k=0;
		}
		printf("%d  %d  %s\n",i+1,k,preguntas[k]);
		for (j=0;j<3;j++)
		{
			printf("%s\n",respuestas[k][j]);
		}
		printf("Respuesta: ");
		scanf("%d",&respondio);
		if((respondio-1)==buenas[pregunta[k]])
		{
			printf("Correcto\n");
			puntos=puntos+100;
		}
		else
		{
			printf("Incorrecto\n");
			puntos=puntos-100;
		}
		k++;		
	}
	getch();
	system("cls");
}
void Medio (int puntos[tam], int dificultad[tam], int count)
{
	int buenas[41]={2,0,1,2,0,2,2,1,2,0,2,1,2,1};//aquie pones las respuestas correctas
    int i,j,k,respondio;
    int pregunta[41]={2,0,1,2,0,2,2,1,2,0,2,1,2,1};
    srand(time(NULL));
	int Selrand, op;
	char preguntas[45][100]={"¿Quién creo la Real Audiencia de Quito?", //AQui van preguntas
                             "¿Cuándo se creo la Real Audiencia de Quito?",
                             "¿Qué movimiento se produjo en 1795 debido al alza del aguardiente?",
                             "¿Qué eran los batanes?",
                             "Entre otros mecanismos de explotación indígena en la Colonia fueron:",
                             "¿Cuándo inicio la Gran Colombia?",
                             "¿Quién es considerado el Mayor Conquistador Incaico?",
                             "Los Catus en la organización económica Inca eran: ",
                             "El sistema de explotación Incaico que consistió en el aprovechamiento obligatorio y no remunerado del trabajo de los Ayllus para la realización de obras públicas, se denominó: ",
                             "El Ayni fue un sistema de trabajo donde se aplicó genuinamente el principio económico de: ",
                             "La agrupación de tribus confederaciones y guerras de expansión es un proceso que en el Horizonte Tardío estructuró: ",
                             "Durante el Tahuantinsuyo, los nobles recompensados vinieron a representar una nobleza:",
                             "¿Qué función cumplían los Capacñam en el Estado Incaico",
                             "La famosa Piedra de Sayhuite representa: ",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta"};
    char respuestas[45][3][60]={//aqui van respuestas
                               {"1.Francisco Pizarro","2.Isabel de Castilla","3.Felipe II"},
                               {"1.1563","2.1492","3.1845"},
                               {"1.Revolución de las alcabalas","2.Revolución de los Estancos","3.Revolución del Aguardiente"},
                               {"1.Centros dobde se producían lingotes de metales preciosos","2.Centros donde se fabricaban armas y municiones","3.Centro donde se preparaba la materia prima para textiles"},
                               {"1.Los obrajes y batanes","2.Los cabildos","3.Los virreinatos"},
                               {"1.1934","2.1754","3.1822"},
                               {"1.Hurin Cusco","2.Huascar","3.Tupac Yupanqui"},
                               {"1.Campesinos de los Ayllus","2.Especie de Centros comerciales","3.Prisioneros de Guerra"},
                               {"1.Chaco","2.Ayni","3.Mita"},
                               {"1.Reciprocidad simétrica","2.Productividad","3.Redistribución estatal"},
                               {"1.La formación del Imperio Wari","2.La formación de reinos autónomos","3.La fundación del Tahuantinsuyo"},
                               {"1.De sangre","2.Meritocrática","3.Advenediza"},
                               {"1.Era los aposentos de mensajeros y soldados","2.Eran los jefes en la contrucción y mantenimiento de puentes","3.Eran caminos para el transporte de tributación y movilización de grandes ejércitos"},
                               {"1.La piedra de los 12 ángulos","2.La planificación agrícola e hidráulica en una maqueta","3.La base militar Inca"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"}};
	
	Selrand=rand()%40;
	k=Selrand;
		for (i=0;i<10;i++)
	{
		if(k>40)
		{
			k=0;
		}
		printf("%d  %d  %s\n",i+1,k,preguntas[k]);
		for (j=0;j<3;j++)
		{
			printf("%s\n",respuestas[k][j]);
		}
		printf("Respuesta: ");
		scanf("%d",&respondio);
		if((respondio-1)==buenas[pregunta[k]])
		{
			printf("Correcto\n");
			puntos=puntos+100;
		}
		else
		{
			printf("Incorrecto\n");
			puntos=puntos-50;
		}
		k++;		
	}
	getch();
	system("cls");
}
void Puntuacion (char usuario[tam][20],int puntos[tam], int dificultad[tam])
{
	int op, i;
	char DIF[30];
	do
	{
		
		if(dificultad[i]==0)
		{
			strcpy(DIF,"INDEFINIDO");
		}
		else if(dificultad[i]==1)
		{
			strcpy(DIF,"FACIL");
		}
		else if (dificultad[i]==2)
		{
			strcpy(DIF,"MEDIO");
		}
		else
		{
			strcpy(DIF,"DIFICIL");
		}		
		printf("\tNOMBRE\t\tDIFICULTAD\t\tPUNTUACION\n\n");
		printf("\t%s\t\t%s\t\t%d",usuario,DIF,puntos);
		printf("\nQue accion desea realizar\n1. cambiar nombre de usuario\n2.Eliminar puntuacion\n3.regresar al menu\nEleccion: ");
		scanf("%d",&op);
		switch (op)
		{
			case 1:
				getch();
				system("cls");
        	break;
        	case 2:
        		getch();
				system("cls");
			break;
			case 3:
				getch();
				system("cls");
			break;
			default:
				printf("Por favor ingrese una opcion valida.");
				getch();
				system("cls");
			break;
		}
	}while(op!=3);
}
void OrdenaDatos (char usuario[][20],int puntos[], int dificultad[])
{
	char USU;
  int cont=0,num,i,j=0,k;
  for (i=0; i<tam; i++)
  {
      printf("Introduce el valor [%d]: ", i+1);
      scanf("%d",&v_original[i]);
  }
  for (i=0;i<tam;i++)
  {
  	for(j=0;j<tam;j++)
  	{
   		if (v_original[j]>v_original[i])
   		{
   			num=v_original[i];
   			v_original[i]=v_original[j];
   			v_original[j]=num;
   			dificultad[i]=vidf[i];
   			vdif[i]=vdif[j];
   			vidf[j]=dificultad[i];
   			USU=usuario[i];
   			usuario[i]=usuario[j];
   			usuario[i]=USU;
		}
	}    
   }
}
