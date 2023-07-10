#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo {
        
        int tipo_tarjeta;
        int numero_tarjeta;
        int saldo;
        int viajes[2];
        int estadistica;
        int ida;
        int llegada;
        Nodo *link;
        
        };

typedef Nodo *Lista;

//funcion que crea un nodo y lo deja en el principio de la lista
//recibe como argumento variables que se asignaran al nodo
void Comprar_tarjeta(Lista *L, int *numero_tarjeta)
{ 
     int tipo;
     printf("Ingrese el tipo de tarjeta(un 0 para Bip. 1 para TNE, 2 Bip adulto mayor):");
     scanf("%d", &tipo);
     int saldo=0;
     
     //validacion para el saldo inicial
     if(tipo == 0|| tipo ==2)
     {
           saldo= 1000;  
     }
     else
     {
          if(tipo == 1)
          {
          saldo= 500;
          }
     
     }
     
     Lista p;
     p = (Lista) malloc(sizeof(Nodo));
     
     //asignamos el tipo de tarjeta al campo del nodo
     p->tipo_tarjeta = tipo;
     
     //asignamos el numero de la tarjeta al campo del nodo
     p->numero_tarjeta = *numero_tarjeta;
     //aumentamos la variable que lleva la numeracion de las tarjetas
     *numero_tarjeta = *numero_tarjeta + 1;
     
     //asignamos el saldo inicial a la tarjeta
     p->saldo = saldo;
     
     //dejamos en cero las dos casilas del vector que guarda el ultimo viaje
     p->viajes[0] = 0;
     p->viajes[1] = 0;
     
     //estadistica de los viajes.
     p->estadistica = 0;
     //Tipo de viaje
     p->llegada=0;
     p->ida=0;
     
     p->link = *L;
     *L = p;
}

void imprimir(Lista L)
{
     Lista q;
     q = L;
     if(q->tipo_tarjeta == 1 || q->tipo_tarjeta == 2 || q->tipo_tarjeta == 0)
     {
         printf("Tipo tarjeta : %d\n",q->tipo_tarjeta);
         printf("Numero tarjeta : %d\n",q->numero_tarjeta);
         printf("Saldo tarjeta : %d\n\n",q->saldo);
     }
     else
     {
              printf(" no existe tarjeta\n\n");                
     }
     q = q->link;
}

void Recargar(Lista L)// arreglar. con cuatica.
{
     Lista q;
     q = L;
     
     int numero=0;
     int recarga;
     
     printf("Ingrese numero de la tarjeta a cargar: ");
     scanf("%d", &numero);
     
     while (q != NULL)
     {
           if(q->numero_tarjeta == numero)
           {
               if (q->tipo_tarjeta == 0)
               {   
                printf("introduzca la carga: "); 
                scanf("%d", &recarga);        
                       if(recarga>=800)
                       {
                          if(recarga<25500 && recarga<10000)
                          {
                             q->saldo = q->saldo + recarga;
                                if(q->saldo<25500)
                                {
                                    printf("Su saldo es: %d\n\n",q->saldo);           
                                }
                                else
                                {
                                  q->saldo = q->saldo - recarga;
                                  printf("Su saldo no se efectuo porque sobre pasa el limite maximoes de la tarjeta\n\n");
                                }
                          }
                          else
                          {
                             q->saldo = q->saldo + recarga + 1000;
                               if(q->saldo<25500)
                               {
                                           printf("Su saldo es: %d\n\n",q->saldo);
                               }
                               else
                               {
                                  q->saldo = q->saldo - recarga - 1000;
                                  printf("Su saldo no se efectuo porque sobre pasa el limite maximo de la tarjeta\n\n");
                               }
                          }
                       }
                       else
                       {
                          printf("Su saldo es insuficiente\n\n");
                       }  
              }
              else
              {
                  if(q->tipo_tarjeta == 1)
                  {
                       printf("introduzca la carga: "); 
                       scanf("%d", &recarga);        
                       
                       if(recarga>=300)
                       {
                           if(recarga<25500)
                         {
                             q->saldo = q->saldo + recarga;
                             if(q->saldo<25500)
                             {
                                     printf("Su saldo es: %d\n\n",q->saldo);
                             }
                             else
                             {
                                  q->saldo = q->saldo - recarga;
                                  printf("Su saldo no se efectuo porque sobre pasa el limite maximo de la tarjeta\n\n");
                             }
                         }            
                       }
                  }
                  else
                  {
                    if (q->tipo_tarjeta == 2)
                    {   
                     printf("introduzca la carga: "); 
                     scanf("%d", &recarga);        
                       if(recarga>=500)
                       {
                          if(recarga<25500 && recarga<10000)
                          {
                             q->saldo = q->saldo + recarga;
                                if(q->saldo<25500)
                                {
                                    printf("Su saldo es: %d\n\n",q->saldo);           
                                }
                                else
                                {
                                  q->saldo = q->saldo - recarga;
                                  printf("Su saldo no se efectuo porque sobre pasa el limite maximoes de la tarjeta\n\n");
                                }
                          }
                          else
                          {
                             q->saldo = q->saldo + recarga + 1000;
                               if(q->saldo<25500)
                               {
                                           printf("Su saldo es: %d\n\n",q->saldo);
                               }
                               else
                               {
                                  q->saldo = q->saldo - recarga - 1000;
                                  printf("Su saldo no se efectuo porque sobre pasa el limite maximo de la tarjeta\n\n");
                               }
                          }
                       }
                       else
                       {
                          printf("Su saldo es insuficiente\n\n");
                       }  
              }
                    
                      
                  }
                  
              }
           }
     
     q = q->link;
     }
}

void Saldo(Lista L)
{
     Lista q;
     q = L;
     int numero=0;
     
     printf("Numero tarjeta :");
     scanf("%d",&numero);
     
     while (q != NULL)
     {
        if(q->numero_tarjeta == numero)
        {
            printf("Su saldo es: %d\n\n", q->saldo);
        }    
     q = q->link;
     }     
}



void Pagar(Lista L, int a[])
{
     Lista q;
     q = L;
     int numero=0;
     int ida=0;
     int llegada=0;
     int aux;
     float tiempo;
     int x;
     int y;
     
     printf("Introduza el numero de tarjeta:");
     scanf("%d",&numero);
     while (q != NULL)
     {
        if(q->numero_tarjeta == numero)
        {
           if (q->tipo_tarjeta == 0  )
           {
              if (q->saldo>=500)
              {
                printf("la tarjeta es Bip Normal\n");
                q->saldo = q->saldo - 500;
                printf("Su saldo es: %d\n\n",q->saldo);  
                printf("En que linea se encuentra. Elija un numero.\n 1. Linea 1\n 2. Linea 2\n 3. Linea 4A\n 4. Linea 4 \n 5. Linea 5\n\n");    
                scanf("%d",&aux);
                
                switch(aux)
                 {
                 case 1: 
                       printf("Se encuentra en la linea 1 (L1)\n");
                       printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                       printf("En que estacion se encuentra: ");
                       scanf("%d",&ida);
                       printf("A que estacion desea llegar: ");
                       scanf("%d",&llegada);
                       
                       //calculamos el tiempo de llegada
                       if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      if(llegada==1)
                      {
                      printf("Uds se encuentra en la estacion San Pablo, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n "); 
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    
                                    tiempo = y - 3;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==11)
                      {
                      printf("Uds se encuentra en la estacion Los Heroes, desea hacer combinacion a la linea 2 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n 1.  Vespucio Norte\n 2.  Zapadores\n 3.  Dorsal\n 4.  Einstein\n 5.  Cementerios\n 6.  Cerro blanco\n 7.  Patronato \n 8.  Cal y canto\n 9.  Santa ana (combinacion a linea 5 <L.5>)\n 10.  Los Heroes(combinacion a linea 1, <L.1>) \n 11. toesca\n 12. Parque O'Higgins\n 10. Rondizzoni\n 11. Franklin\n 12. El llano\n 13. San Miguel\n 14. Lo vial\n 15. Departamental\n 16. Ciudad del ni�o\n 17. Lo Ovalle \n 18. El parron\n 19. La cisterna (combinacion a linea 4A <L. 4A>)\n\n");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    
                                    tiempo = y - 10;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==20)
                      {
                      printf("Uds se encuentra en la estacion Tobalaba, desea hacer combinacion a la linea 4 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n 1.Cristobal Colon\n 2.Francisco Bilbao\n 3.Principe de Gales \n 4.Simon Bolivar\n 5.Plaza Ega�a\n 6.Los Orientales \n 7.Grecia\n 8.Los Presidentes\n 9.Quilin\n 10.Las Torres\n 11.Macul\n 12.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 13.Vicente Valdes(combinacion a linea 2 <L.2>) \n 14.Rojas Magallanes\n 15.Trinidad\n 16.San Jose de la Estrella\n 17.Los Quillajes\n 18.Hospital Sotero del Rio\n 19.Protectora de la Infancia\n 20.Las mercedes\n 21.Plaza Puente Alto\n\n");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 0;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==15)
                      {
                      printf("Uds se encuentra en la estacion Baquedano, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n ");          printf("En que estacion se encuentra: ");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 11;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      
                      break;
                      
                 case 2:
                      printf("Se encuentra en la linea 2 (L2)\n");
                      printf("\n 1.  Vespucio Norte\n 2.  Zapadores\n 3.  Dorsal\n 4.  Einstein\n 5.  Cementerios\n 6.  Cerro blanco\n 7.  Patronato \n 8.  Cal y canto\n 9.  Santa ana (combinacion a linea 5 <L.5>)\n 10.  Los Heroes(combinacion a linea 1, <L.1>) \n 11. toesca\n 12. Parque O'Higgins\n 10. Rondizzoni\n 11. Franklin\n 12. El llano\n 13. San Miguel\n 14. Lo vial\n 15. Departamental\n 16. Ciudad del ni�o\n 17. Lo Ovalle \n 18. El parron\n 19. La cisterna (combinacion a linea 4A <L. 4A>)\n\n");          
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      
                      if(llegada==9)
                      {
                      printf("Uds se encuentra en la estacion Santa Ana, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n "); 
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    
                                    tiempo = y - 8;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==10)
                      {
                      printf("Uds se encuentra en la estacion Los Heroes, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    
                                    tiempo = y - 11;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==19)
                      {
                      printf("Uds se encuentra en la estacion La cisterna, desea hacer combinacion a la linea 4A (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.La cisterna (combinacion a linea 4A <L.4A>)\n 2.San Ramon\n 3.San Rosa\n 4.La granja\n 5.Santa Julia\n 6.Vicu�a Mackena(combinacion a linea 5 <L.5>)\n\n");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 1;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      }
                      break;
                      
                 case 3:
                      printf("Se encuentra en la linea 4A (L4A)\n");
                      printf("\n 1.La cisterna (combinacion a linea 4A <L.4A>)\n 2.San Ramon\n 3.San Rosa\n 4.La granja\n 5.Santa Julia\n 6.Vicu�a Mackena(combinacion a linea 5 <L.5>)\n\n");    
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      if(llegada==6)
                      {
                      printf("Uds se encuentra en la estacion Vicu�a mackena, desea hacer combinacion a la linea 4 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.Tobalaba (combinacion a linea 1 <L.1>)\n 2.Cristobal Colon\n 3.Francisco Bilbao\n 4.Principe de Gales \n 5.Simon Bolivar\n 6.Plaza Ega�a\n 7.Los Orientales \n 8.Grecia\n 9.Los Presidentes\n 10.Quilin\n 11.Las Torres\n 12.Macul\n 13.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 14.Vicente Valdes(combinacion a linea 2 <L.2>) \n 15.Rojas Magallanes\n 16.Trinidad\n 17.San Jose de la Estrella\n 18.Los Quillajes\n 19.Hospital Sotero del Rio\n 20.Protectora de la Infancia\n 21.Las mercedes\n 22.Plaza Puente Alto\n\n");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 13;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      
                      
                      break;
                      
                             
                      
                 case 4:
                      printf("Se encuentra en la linea 4 (L4)\n");
                      printf("\n 1.Tobalaba (combinacion a linea 1 <L.1>)\n 2.Cristobal Colon\n 3.Francisco Bilbao\n 4.Principe de Gales \n 5.Simon Bolivar\n 6.Plaza Ega�a\n 7.Los Orientales \n 8.Grecia\n 9.Los Presidentes\n 10.Quilin\n 11.Las Torres\n 12.Macul\n 13.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 14.Vicente Valdes(combinacion a linea 2 <L.2>) \n 15.Rojas Magallanes\n 16.Trinidad\n 17.San Jose de la Estrella\n 18.Los Quillajes\n 19.Hospital Sotero del Rio\n 20.Protectora de la Infancia\n 21.Las mercedes\n 22.Plaza Puente Alto\n\n");
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      
                      if(llegada==13)
                      {
                      printf("Uds se encuentra en la estacion Vicu�a mackena, desea hacer combinacion a la linea 4A (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.La cisterna (combinacion a linea 4A <L.4A>)\n 2.San Ramon\n 3.San Rosa\n 4.La granja\n 5.Santa Julia\n 6.Vicu�a Mackena(combinacion a linea 5 <L.5>)\n\n");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 6;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==14)
                      {
                      printf("Uds se encuentra en la estacion Vicente Valdes, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n ");          
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 23;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==1)
                      {
                      printf("Uds se encuentra en la estacion Tobalaba, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 20;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      break;
                      
                 case 5:
                      printf("Se encuentra en la linea 5 (L5)\n");
                      printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n ");          printf("En que estacion se encuentra: ");
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      if(llegada==2)
                      {
                      printf("Uds se encuentra en la estacion San Pablo, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 1;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==11)
                      {
                      printf("Uds se encuentra en la estacion Baquedano, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 15;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==9)
                      {
                      printf("Uds se encuentra en la estacion Santa ana, desea hacer combinacion a la linea 2 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  Vespucio Norte\n 2.  Zapadores\n 3.  Dorsal\n 4.  Einstein\n 5.  Cementerios\n 6.  Cerro blanco\n 7.  Patronato \n 8.  Cal y canto\n 9.  Santa ana (combinacion a linea 5 <L.5>)\n 10.  Los Heroes(combinacion a linea 1, <L.1>) \n 11. toesca\n 12. Parque O'Higgins\n 10. Rondizzoni\n 11. Franklin\n 12. El llano\n 13. San Miguel\n 14. Lo vial\n 15. Departamental\n 16. Ciudad del ni�o\n 17. Lo Ovalle \n 18. El parron\n 19. La cisterna (combinacion a linea 4A <L. 4A>)\n\n");          
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 9;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==23)
                      {
                      printf("Uds se encuentra en la estacion Vicente Valdes, desea hacer combinacion a la linea 4 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.Tobalaba (combinacion a linea 1 <L.1>)\n 2.Cristobal Colon\n 3.Francisco Bilbao\n 4.Principe de Gales \n 5.Simon Bolivar\n 6.Plaza Ega�a\n 7.Los Orientales \n 8.Grecia\n 9.Los Presidentes\n 10.Quilin\n 11.Las Torres\n 12.Macul\n 13.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 14.Vicente Valdes(combinacion a linea 2 <L.2>) \n 15.Rojas Magallanes\n 16.Trinidad\n 17.San Jose de la Estrella\n 18.Los Quillajes\n 19.Hospital Sotero del Rio\n 20.Protectora de la Infancia\n 21.Las mercedes\n 22.Plaza Puente Alto\n\n");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 14;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      
                      
                      break;
                      
                 }
                
                                             
              }
              else
              {
                printf("Su saldo es insuficiente\n\n");
              }
           }
           else
           {
               if(q->tipo_tarjeta == 1 )
               {
                     if (q->saldo>=130)
                     {
                                       printf("la tarjeta es una TNE\n");
                                       q->saldo = q->saldo - 130;
                                       printf("Su saldo es: %d\n\n",q->saldo);
                                       printf("En que linea se encuentra. Elija un numero.\n 1. Linea 1\n 2. Linea 2\n 3. Linea 4A\n 4. Linea 4 \n 5. Linea 5\n\n");    
                                       scanf("%d",&aux);
                                       switch(aux)
                                             {
                                             case 1: 
                       printf("Se encuentra en la linea 1 (L1)\n");
                       printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                       printf("En que estacion se encuentra: ");
                       scanf("%d",&ida);
                       printf("A que estacion desea llegar: ");
                       scanf("%d",&llegada);
                       
                       //calculamos el tiempo de llegada
                       if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      if(llegada==1)
                      {
                      printf("Uds se encuentra en la estacion San Pablo, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n "); 
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    
                                    tiempo = y - 3;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==11)
                      {
                      printf("Uds se encuentra en la estacion Los Heroes, desea hacer combinacion a la linea 2 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n 1.  Vespucio Norte\n 2.  Zapadores\n 3.  Dorsal\n 4.  Einstein\n 5.  Cementerios\n 6.  Cerro blanco\n 7.  Patronato \n 8.  Cal y canto\n 9.  Santa ana (combinacion a linea 5 <L.5>)\n 10.  Los Heroes(combinacion a linea 1, <L.1>) \n 11. toesca\n 12. Parque O'Higgins\n 10. Rondizzoni\n 11. Franklin\n 12. El llano\n 13. San Miguel\n 14. Lo vial\n 15. Departamental\n 16. Ciudad del ni�o\n 17. Lo Ovalle \n 18. El parron\n 19. La cisterna (combinacion a linea 4A <L. 4A>)\n\n");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    
                                    tiempo = y - 10;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==20)
                      {
                      printf("Uds se encuentra en la estacion Tobalaba, desea hacer combinacion a la linea 4 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n 1.Cristobal Colon\n 2.Francisco Bilbao\n 3.Principe de Gales \n 4.Simon Bolivar\n 5.Plaza Ega�a\n 6.Los Orientales \n 7.Grecia\n 8.Los Presidentes\n 9.Quilin\n 10.Las Torres\n 11.Macul\n 12.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 13.Vicente Valdes(combinacion a linea 2 <L.2>) \n 14.Rojas Magallanes\n 15.Trinidad\n 16.San Jose de la Estrella\n 17.Los Quillajes\n 18.Hospital Sotero del Rio\n 19.Protectora de la Infancia\n 20.Las mercedes\n 21.Plaza Puente Alto\n\n");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 0;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==15)
                      {
                      printf("Uds se encuentra en la estacion Baquedano, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n ");          printf("En que estacion se encuentra: ");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 11;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      
                      break;
                      
                 case 2:
                      printf("Se encuentra en la linea 2 (L2)\n");
                      printf("\n 1.  Vespucio Norte\n 2.  Zapadores\n 3.  Dorsal\n 4.  Einstein\n 5.  Cementerios\n 6.  Cerro blanco\n 7.  Patronato \n 8.  Cal y canto\n 9.  Santa ana (combinacion a linea 5 <L.5>)\n 10.  Los Heroes(combinacion a linea 1, <L.1>) \n 11. toesca\n 12. Parque O'Higgins\n 10. Rondizzoni\n 11. Franklin\n 12. El llano\n 13. San Miguel\n 14. Lo vial\n 15. Departamental\n 16. Ciudad del ni�o\n 17. Lo Ovalle \n 18. El parron\n 19. La cisterna (combinacion a linea 4A <L. 4A>)\n\n");          
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      
                      if(llegada==9)
                      {
                      printf("Uds se encuentra en la estacion Santa Ana, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n "); 
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    
                                    tiempo = y - 8;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==10)
                      {
                      printf("Uds se encuentra en la estacion Los Heroes, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    
                                    tiempo = y - 11;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==19)
                      {
                      printf("Uds se encuentra en la estacion La cisterna, desea hacer combinacion a la linea 4A (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.La cisterna (combinacion a linea 4A <L.4A>)\n 2.San Ramon\n 3.San Rosa\n 4.La granja\n 5.Santa Julia\n 6.Vicu�a Mackena(combinacion a linea 5 <L.5>)\n\n");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 1;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      }
                      break;
                      
                 case 3:
                      printf("Se encuentra en la linea 4A (L4A)\n");
                      printf("\n 1.La cisterna (combinacion a linea 4A <L.4A>)\n 2.San Ramon\n 3.San Rosa\n 4.La granja\n 5.Santa Julia\n 6.Vicu�a Mackena(combinacion a linea 5 <L.5>)\n\n");    
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      if(llegada==6)
                      {
                      printf("Uds se encuentra en la estacion Vicu�a mackena, desea hacer combinacion a la linea 4 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.Tobalaba (combinacion a linea 1 <L.1>)\n 2.Cristobal Colon\n 3.Francisco Bilbao\n 4.Principe de Gales \n 5.Simon Bolivar\n 6.Plaza Ega�a\n 7.Los Orientales \n 8.Grecia\n 9.Los Presidentes\n 10.Quilin\n 11.Las Torres\n 12.Macul\n 13.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 14.Vicente Valdes(combinacion a linea 2 <L.2>) \n 15.Rojas Magallanes\n 16.Trinidad\n 17.San Jose de la Estrella\n 18.Los Quillajes\n 19.Hospital Sotero del Rio\n 20.Protectora de la Infancia\n 21.Las mercedes\n 22.Plaza Puente Alto\n\n");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 13;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      
                      
                      break;
                      
                             
                      
                 case 4:
                      printf("Se encuentra en la linea 4 (L4)\n");
                      printf("\n 1.Tobalaba (combinacion a linea 1 <L.1>)\n 2.Cristobal Colon\n 3.Francisco Bilbao\n 4.Principe de Gales \n 5.Simon Bolivar\n 6.Plaza Ega�a\n 7.Los Orientales \n 8.Grecia\n 9.Los Presidentes\n 10.Quilin\n 11.Las Torres\n 12.Macul\n 13.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 14.Vicente Valdes(combinacion a linea 2 <L.2>) \n 15.Rojas Magallanes\n 16.Trinidad\n 17.San Jose de la Estrella\n 18.Los Quillajes\n 19.Hospital Sotero del Rio\n 20.Protectora de la Infancia\n 21.Las mercedes\n 22.Plaza Puente Alto\n\n");
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      
                      if(llegada==13)
                      {
                      printf("Uds se encuentra en la estacion Vicu�a mackena, desea hacer combinacion a la linea 4A (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.La cisterna (combinacion a linea 4A <L.4A>)\n 2.San Ramon\n 3.San Rosa\n 4.La granja\n 5.Santa Julia\n 6.Vicu�a Mackena(combinacion a linea 5 <L.5>)\n\n");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 6;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==14)
                      {
                      printf("Uds se encuentra en la estacion Vicente Valdes, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n ");          
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 23;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==1)
                      {
                      printf("Uds se encuentra en la estacion Tobalaba, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 20;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      break;
                      
                 case 5:
                      printf("Se encuentra en la linea 5 (L5)\n");
                      printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n ");          printf("En que estacion se encuentra: ");
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      if(llegada==2)
                      {
                      printf("Uds se encuentra en la estacion San Pablo, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 1;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==11)
                      {
                      printf("Uds se encuentra en la estacion Baquedano, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 15;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==9)
                      {
                      printf("Uds se encuentra en la estacion Santa ana, desea hacer combinacion a la linea 2 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  Vespucio Norte\n 2.  Zapadores\n 3.  Dorsal\n 4.  Einstein\n 5.  Cementerios\n 6.  Cerro blanco\n 7.  Patronato \n 8.  Cal y canto\n 9.  Santa ana (combinacion a linea 5 <L.5>)\n 10.  Los Heroes(combinacion a linea 1, <L.1>) \n 11. toesca\n 12. Parque O'Higgins\n 10. Rondizzoni\n 11. Franklin\n 12. El llano\n 13. San Miguel\n 14. Lo vial\n 15. Departamental\n 16. Ciudad del ni�o\n 17. Lo Ovalle \n 18. El parron\n 19. La cisterna (combinacion a linea 4A <L. 4A>)\n\n");          
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 9;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==23)
                      {
                      printf("Uds se encuentra en la estacion Vicente Valdes, desea hacer combinacion a la linea 4 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.Tobalaba (combinacion a linea 1 <L.1>)\n 2.Cristobal Colon\n 3.Francisco Bilbao\n 4.Principe de Gales \n 5.Simon Bolivar\n 6.Plaza Ega�a\n 7.Los Orientales \n 8.Grecia\n 9.Los Presidentes\n 10.Quilin\n 11.Las Torres\n 12.Macul\n 13.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 14.Vicente Valdes(combinacion a linea 2 <L.2>) \n 15.Rojas Magallanes\n 16.Trinidad\n 17.San Jose de la Estrella\n 18.Los Quillajes\n 19.Hospital Sotero del Rio\n 20.Protectora de la Infancia\n 21.Las mercedes\n 22.Plaza Puente Alto\n\n");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 14;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                                                  break;
                                                  
                                             }
                                       
                                                                      
                     }
                     else
                     {
                                       printf("Su saldo es insuficiente\n\n");
                     }
               }
               else
               {
                   if(q->tipo_tarjeta == 2)
               {
                     if (q->saldo>=500)
                     {
                                       printf("la tarjeta es una BIP Adulto mayor\n");
                                       q->saldo = q->saldo - 500;
                                       printf("Su saldo es: %d\n\n",q->saldo);
                                       
                                       printf("En que linea se encuentra. Elija un numero.\n 1. Linea 1\n 2. Linea 2\n 3. Linea 4A\n 4. Linea 4 \n 5. Linea 5\n\n");    
                                       scanf("%d",&aux);
                                       switch(aux)
                                     {
                                     case 1: 
                                           printf("Se encuentra en la linea 1 (L1)\n");
                                           printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                           printf("En que estacion se encuentra: ");
                                           scanf("%d",&ida);
                                           printf("A que estacion desea llegar: ");
                                           scanf("%d",&llegada);
                                           
                                           //calculamos el tiempo de llegada
                                           if(ida != llegada)
                                          {       tiempo = llegada - ida;
                                                       if (tiempo < 0) tiempo=tiempo*-1;
                                                           printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                                          }
                                          if(llegada==1)
                                          {
                                          printf("Uds se encuentra en la estacion San Pablo, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor\n\n");
                                          scanf("%d",&x);
                                            if(x ==1)
                                            {
                                            printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n "); 
                                            printf("A que estacion desea llegar: ");
                                            scanf("%d",&y);
                                            
                                            tiempo = y - 3;
                                            if (tiempo < 0) tiempo=tiempo*-1;
                                             printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                            }
                                            }
                                          if(llegada==11)
                                          {
                                          printf("Uds se encuentra en la estacion Los Heroes, desea hacer combinacion a la linea 2 (un 1 para si, si no coloque otro valor\n\n");
                                          scanf("%d",&x);
                                             if(x ==1)
                                          {
                                          printf("\n 1.  Vespucio Norte\n 2.  Zapadores\n 3.  Dorsal\n 4.  Einstein\n 5.  Cementerios\n 6.  Cerro blanco\n 7.  Patronato \n 8.  Cal y canto\n 9.  Santa ana (combinacion a linea 5 <L.5>)\n 10.  Los Heroes(combinacion a linea 1, <L.1>) \n 11. toesca\n 12. Parque O'Higgins\n 10. Rondizzoni\n 11. Franklin\n 12. El llano\n 13. San Miguel\n 14. Lo vial\n 15. Departamental\n 16. Ciudad del ni�o\n 17. Lo Ovalle \n 18. El parron\n 19. La cisterna (combinacion a linea 4A <L. 4A>)\n\n");
                                          printf("A que estacion desea llegar: ");
                                           scanf("%d",&y);
                                    
                                    tiempo = y - 10;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==20)
                      {
                      printf("Uds se encuentra en la estacion Tobalaba, desea hacer combinacion a la linea 4 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n 1.Cristobal Colon\n 2.Francisco Bilbao\n 3.Principe de Gales \n 4.Simon Bolivar\n 5.Plaza Ega�a\n 6.Los Orientales \n 7.Grecia\n 8.Los Presidentes\n 9.Quilin\n 10.Las Torres\n 11.Macul\n 12.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 13.Vicente Valdes(combinacion a linea 2 <L.2>) \n 14.Rojas Magallanes\n 15.Trinidad\n 16.San Jose de la Estrella\n 17.Los Quillajes\n 18.Hospital Sotero del Rio\n 19.Protectora de la Infancia\n 20.Las mercedes\n 21.Plaza Puente Alto\n\n");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 0;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==15)
                      {
                      printf("Uds se encuentra en la estacion Baquedano, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n ");          printf("En que estacion se encuentra: ");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 11;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      break;
                      
                 case 2:
                      printf("Se encuentra en la linea 2 (L2)\n");
                      printf("\n 1.  Vespucio Norte\n 2.  Zapadores\n 3.  Dorsal\n 4.  Einstein\n 5.  Cementerios\n 6.  Cerro blanco\n 7.  Patronato \n 8.  Cal y canto\n 9.  Santa ana (combinacion a linea 5 <L.5>)\n 10.  Los Heroes(combinacion a linea 1, <L.1>) \n 11. toesca\n 12. Parque O'Higgins\n 10. Rondizzoni\n 11. Franklin\n 12. El llano\n 13. San Miguel\n 14. Lo vial\n 15. Departamental\n 16. Ciudad del ni�o\n 17. Lo Ovalle \n 18. El parron\n 19. La cisterna (combinacion a linea 4A <L. 4A>)\n\n");          
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      
                      if(llegada==9)
                      {
                      printf("Uds se encuentra en la estacion Santa Ana, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n "); 
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    
                                    tiempo = y - 8;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==10)
                      {
                      printf("Uds se encuentra en la estacion Los Heroes, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x ==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    
                                    tiempo = y - 11;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==19)
                      {
                      printf("Uds se encuentra en la estacion La cisterna, desea hacer combinacion a la linea 4A (un 1 para si, si no coloque otro valor\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.La cisterna (combinacion a linea 4A <L.4A>)\n 2.San Ramon\n 3.San Rosa\n 4.La granja\n 5.Santa Julia\n 6.Vicu�a Mackena(combinacion a linea 5 <L.5>)\n\n");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 1;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      }
                      break;
                      
                 case 3:
                      printf("Se encuentra en la linea 4A (L4A)\n");
                      printf("\n 1.La cisterna (combinacion a linea 4A <L.4A>)\n 2.San Ramon\n 3.San Rosa\n 4.La granja\n 5.Santa Julia\n 6.Vicu�a Mackena(combinacion a linea 5 <L.5>)\n\n");    
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                                   
                      }
                      if(llegada==6)
                      {
                      printf("Uds se encuentra en la estacion Vicu�a mackena, desea hacer combinacion a la linea 4 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.Tobalaba (combinacion a linea 1 <L.1>)\n 2.Cristobal Colon\n 3.Francisco Bilbao\n 4.Principe de Gales \n 5.Simon Bolivar\n 6.Plaza Ega�a\n 7.Los Orientales \n 8.Grecia\n 9.Los Presidentes\n 10.Quilin\n 11.Las Torres\n 12.Macul\n 13.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 14.Vicente Valdes(combinacion a linea 2 <L.2>) \n 15.Rojas Magallanes\n 16.Trinidad\n 17.San Jose de la Estrella\n 18.Los Quillajes\n 19.Hospital Sotero del Rio\n 20.Protectora de la Infancia\n 21.Las mercedes\n 22.Plaza Puente Alto\n\n");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 13;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      
                      
                      break;
                      
                             
                      
                 case 4:
                      printf("Se encuentra en la linea 4 (L4)\n");
                      printf("\n 1.Tobalaba (combinacion a linea 1 <L.1>)\n 2.Cristobal Colon\n 3.Francisco Bilbao\n 4.Principe de Gales \n 5.Simon Bolivar\n 6.Plaza Ega�a\n 7.Los Orientales \n 8.Grecia\n 9.Los Presidentes\n 10.Quilin\n 11.Las Torres\n 12.Macul\n 13.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 14.Vicente Valdes(combinacion a linea 2 <L.2>) \n 15.Rojas Magallanes\n 16.Trinidad\n 17.San Jose de la Estrella\n 18.Los Quillajes\n 19.Hospital Sotero del Rio\n 20.Protectora de la Infancia\n 21.Las mercedes\n 22.Plaza Puente Alto\n\n");
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      
                      if(llegada==13)
                      {
                      printf("Uds se encuentra en la estacion Vicu�a mackena, desea hacer combinacion a la linea 4A (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.La cisterna (combinacion a linea 4A <L.4A>)\n 2.San Ramon\n 3.San Rosa\n 4.La granja\n 5.Santa Julia\n 6.Vicu�a Mackena(combinacion a linea 5 <L.5>)\n\n");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 6;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==14)
                      {
                      printf("Uds se encuentra en la estacion Vicente Valdes, desea hacer combinacion a la linea 5 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n ");          
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 23;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==1)
                      {
                      printf("Uds se encuentra en la estacion Tobalaba, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 20;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      break;
                      
                 case 5:
                      printf("Se encuentra en la linea 5 (L5)\n");
                      printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n ");          printf("En que estacion se encuentra: ");
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      if(llegada==2)
                      {
                      printf("Uds se encuentra en la estacion San Pablo, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 1;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      if(llegada==11)
                      {
                      printf("Uds se encuentra en la estacion Baquedano, desea hacer combinacion a la linea 1 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 15;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==9)
                      {
                      printf("Uds se encuentra en la estacion Santa ana, desea hacer combinacion a la linea 2 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.  Vespucio Norte\n 2.  Zapadores\n 3.  Dorsal\n 4.  Einstein\n 5.  Cementerios\n 6.  Cerro blanco\n 7.  Patronato \n 8.  Cal y canto\n 9.  Santa ana (combinacion a linea 5 <L.5>)\n 10.  Los Heroes(combinacion a linea 1, <L.1>) \n 11. toesca\n 12. Parque O'Higgins\n 10. Rondizzoni\n 11. Franklin\n 12. El llano\n 13. San Miguel\n 14. Lo vial\n 15. Departamental\n 16. Ciudad del ni�o\n 17. Lo Ovalle \n 18. El parron\n 19. La cisterna (combinacion a linea 4A <L. 4A>)\n\n");          
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 9;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                      
                      if(llegada==23)
                      {
                      printf("Uds se encuentra en la estacion Vicente Valdes, desea hacer combinacion a la linea 4 (un 1 para si, si no coloque otro valor)\n\n");
                      scanf("%d",&x);
                                    if(x==1)
                                    {
                                    printf("\n 1.Tobalaba (combinacion a linea 1 <L.1>)\n 2.Cristobal Colon\n 3.Francisco Bilbao\n 4.Principe de Gales \n 5.Simon Bolivar\n 6.Plaza Ega�a\n 7.Los Orientales \n 8.Grecia\n 9.Los Presidentes\n 10.Quilin\n 11.Las Torres\n 12.Macul\n 13.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 14.Vicente Valdes(combinacion a linea 2 <L.2>) \n 15.Rojas Magallanes\n 16.Trinidad\n 17.San Jose de la Estrella\n 18.Los Quillajes\n 19.Hospital Sotero del Rio\n 20.Protectora de la Infancia\n 21.Las mercedes\n 22.Plaza Puente Alto\n\n");
                                    printf("A que estacion desea llegar: ");
                                    scanf("%d",&y);
                                    tiempo = y - 14;
                                    if (tiempo < 0) tiempo=tiempo*-1;
                       
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);                           
                                    }
                      }
                                          break;
                                          
                                     }
                                       
                                                                      
                     }
                     else
                     {
                                       printf("Su saldo es insuficiente\n\n");
                     }
               }
                   
               }   
           }
                       
        }
        
     q = q->link;
     }
} 



void Tiempo(int a)
{
     
     int ida=0;
     int llegada=0;
     int aux;
     float tiempo;
     
      printf("En que linea se encuentra. Elija un numero.\n 1. Linea 1\n 2. Linea 2\n 3. Linea 4A\n 4. Linea 4 \n 5. Linea 5\n\n");    
      scanf("%d",&aux);
                
      switch(aux)
      {
      case 1: 
                       printf("Se encuentra en la linea 1 (L1)\n");
                       printf("\n 1.  San Pable\n 2.  Neptuno\n 3.  Pajaritos\n 4.  Las rejas\n 5.  Ecuador\n 6.  San Alberto Hurtado\n 7.  Universidad de santiago \n 8.  Estacion central\n 9.  ULA\n 10. Republica\n 11. Los heroes(combinacion a linea 2 <L.2>)\n 12. Moneda\n 13. Universidad de Chile\n 11. San Lucia\n 14. Universidad Catolica\n 15. Baquedano(combinacion a linea 5 <L.5>)\n 16. Salvador\n 17. Manuel Montt\n 18. Pedro de Valdivia\n 19. Los Leones \n 20. Tobalaba(Combinacion a la linea 4 <L4>)\n 21. El golf\n 22. Alcantara \n 23. Escuela militar\n\n ");    
                       printf("En que estacion se encuentra: ");
                       scanf("%d",&ida);
                       printf("A que estacion desea llegar: ");
                       scanf("%d",&llegada);
                       
                       //calculamos el tiempo de llegada
                       if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      
                      break;
                      
      case 2:
                      printf("Se encuentra en la linea 2 (L2)\n");
                      printf("\n 1.  Vespucio Norte\n 2.  Zapadores\n 3.  Dorsal\n 4.  Einstein\n 5.  Cementerios\n 6.  Cerro blanco\n 7.  Patronato \n 8.  Cal y canto\n 9.  Santa ana (combinacion a linea 5 <L.5>)\n 10.  Los Heroes(combinacion a linea 1, <L.1>) \n 11. toesca\n 12. Parque O'Higgins\n 10. Rondizzoni\n 11. Franklin\n 12. El llano\n 13. San Miguel\n 14. Lo vial\n 15. Departamental\n 16. Ciudad del ni�o\n 17. Lo Ovalle \n 18. El parron\n 19. La cisterna (combinacion a linea 4A <L. 4A>)\n\n");          
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      break;
                      
      case 3:
                      printf("Se encuentra en la linea 4A (L4A)\n");
                      printf("\n 1.La cisterna (combinacion a linea 4A <L.4A>)\n 2.San Ramon\n 3.San Rosa\n 4.La granja\n 5.Santa Julia\n 6.Vicu�a Mackena(combinacion a linea 5 <L.5>)\n\n");    
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      break;
                      
      case 4:
                      printf("Se encuentra en la linea 4 (L4)\n");
                      printf("\n 1.Tobalaba (combinacion a linea 1 <L.1>)\n 2.Cristobal Colon\n 3.Francisco Bilbao\n 4.Principe de Gales \n 5.Simon Bolivar\n 6.Plaza Ega�a\n 7.Los Orientales \n 8.Grecia\n 9.Los Presidentes\n 10.Quilin\n 11.Las Torres\n 12.Macul\n 13.Vicu�a Mackena (combinacion a linea 4A <L.4A>)\n 14.Vicente Valdes(combinacion a linea 2 <L.2>) \n 15.Rojas Magallanes\n 16.Trinidad\n 17.San Jose de la Estrella\n 18.Los Quillajes\n 19.Hospital Sotero del Rio\n 20.Protectora de la Infancia\n 21.Las mercedes\n 22.Plaza Puente Alto\n\n");
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
                      
                      break;
                      
      case 5:
                      printf("Se encuentra en la linea 5 (L5)\n");
                      printf("\n1.  Pudahuel\n2.  San Pablo\n3.  Lo Prado\n4.  Blanqueado\n5.  Gruta de Lourdes\n6.  Quinta Normal\n7.  Cumming\n8.  Santa Ana\n9.  Plaza de Armas\n10. Bellas Artes\n11. Baquedano \n12. Parque Bustamante\n13. Santa Isabel\n14. Irarr�zaval\n15. �uble\n16. Rodrigo de Araya\n17. Carlos Valdovinos\n18. Camino Agr�cola\n19. San Joaqu�n\n20. Pedrero\n21. Mirador\n22. Bellavista de La Florida\n23. Vicente Vald�s\n\n ");          printf("En que estacion se encuentra: ");
                      printf("En que estacion se encuentra: ");
                      scanf("%d",&ida);
                      printf("A que estacion desea llegar: ");
                      scanf("%d",&llegada);
                       
                      //calculamos el tiempo de llegada
                      if(ida != llegada)
                      {       tiempo = llegada - ida;
                                   if (tiempo < 0) tiempo=tiempo*-1;
                                       printf("Se demorara %f minutos en su viaje.\n\n", tiempo+(tiempo-1)/2);
                      }
break;

default: printf("Error en digitar las linea de metro\n\n");
}
}

int main()
{
    //variable que tiene la opcion del menu
    int a;
    //variable que lleva el conteo de las tarjetas
    int numero = 10000000;
    int viajes[2];
    
    Lista L = NULL;

    printf("introduzca el numero que desea realizar:\n 1.Compra tarjeta y carga inicial\n 2.Ingreso Recarga\n 3.consultar saldo\n 4.Pago pasaje y viaje \n 5.Consultar Tiempo de viaje\n 6.estadistica\n 7.Salir \n Elija un numero que desea ocupar: ");    scanf("%d",&a);
    
    do
    {
    switch(a) {
    case 1: 
            Comprar_tarjeta(&L,&numero);
            imprimir(L);
            break;
    
    case 2: 
            Recargar(L);
            break;
    
    case 3: 
            Saldo(L); 
            break;
    
    case 4: 
            Pagar(L, viajes); 
            break;
    
    case 5: 
            Tiempo(a); 
            break;
            
    case 6: 
            //Estadistica (L); 
            break;
    case 7: 
            exit(0); 
            break;
    
    default: printf("No existe, introduzca un numero que indica el menu\n\n");
    }
    
    printf("introduzca el numero que desea realizar:\n 1.Compra tarjeta y carga inicial\n 2.Ingreso Recarga\n 3.consultar saldo\n 4.Pago pasaje y viaje\n 5.Consultar tiempo\n 6.Estadistica \n 7.Salir \n Elija un numero que desea ocupar: ");
    scanf("%d",&a);
    
    }
    while (a != 7);

}
