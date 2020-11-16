#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include<string.h>


int main(int argc, char *argv[])
{
	pid_t pid1, pid2;
	int status1, status2;

    char nombra[12];
    char apellido[12];
    char cedula[9];

    char confirmacion[20];
    float monto=0;


	if ( (pid1=fork()) == 0 )
	{ /* Registro */
		printf("Ingrese su nombre:\n");
        scanf("%s",nombra);
        printf("Ingrese su apellido:\n");
        scanf("%s",apellido);
        printf("Ingrese su cedula:\n");
        scanf("%s",cedula);
        //Registrara los datos del usuario
        if((strlen(nombra)==0)||(strlen(apellido)==0)||(strlen(cedula)==0)){
            return -1;
        }
	}
	else
 	{ 
 		if ( (pid2=fork()) == 0 )
 		{ /* Pago*/
            waitpid(pid1, &status1, 0);
 			printf("Ingrese su confirmacion de pago:\n");
            scanf("%s",confirmacion);
            printf("Ingrese su monto debitado:\n");
            scanf("%f",&monto);

            if ((monto==0)||(strlen(confirmacion)==0)){
                return -1;
            }
            
		}
		else
		{ /* padre */
/* Esperamos al registro*/
			waitpid(pid1, &status1, 0);
/* Esperamos al pago*/
			waitpid(pid2, &status2, 0);
            /* El pago se hizo y se registro el usuario */
            printf("Su registro y pago han sido validados con exito.");
 		}
	}

	return 0;
}