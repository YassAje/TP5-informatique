 #include <stdio.h>
 #include <stdlib.h>



int main(int argc,char *argv[]){

	int i,j,result;

	FILE *fp ;

	long taille_fichier;

	unsigned char *data;

	int s;
	
	fp = fopen(argv[1],"rb");

	    
	
	
	/*..................................taille............................................*/

  	fseek (fp , 0 , SEEK_END);

  	taille_fichier = ftell (fp);

  	rewind (fp);

		     /*......................début....................... */	


	data = (char *) malloc ((taille_fichier)*sizeof(char));;

		/*.....................mémoire et enregistrement..................*/

	if (data == NULL) {

		printf ("Memory error",stderr); 

		return(-1);
	}
	
	result = fread (data,1,taille_fichier,fp);

		/*.................placement dans la mémoire..................*/

	if (result != taille_fichier) {

		printf ("Reading error",stderr);
 
		   return(-1);
	                }
		/*..................allignement de tableau...................*/
	j=0;
	
	for(j=0;j<10;j++){

		for(i=0+j*16;i<(j*16+16);i+=1){

			s=data[i];

			if(isprint(s)){

		/*....................affichage en mode ascii..................*/

				printf("%c",s);

			}else{
				printf(".");

			}
		
		}	

                        printf("  ");
	
	for(i=0+j*16;i<(j*16+16);i+=1){

		s=data[i];

	/*...................affichage en hexa (%02 mode couple).......................*/

		printf("%02X ",s);

		}

		printf("\n");
	      }
	
	                  fclose(fp);

        return (EXIT_SUCCESS);

}
 

